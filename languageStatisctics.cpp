//
// Created by Oleksandr Sereda on 5/30/2019.
//
#include<string> // for string class
#include <map>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>
#include "languageStatisctics.h"
#include "langData.h"

using namespace std;
extern const int ENGLISH_LANG_ID = 0;
extern const int UNKNOWN_LANG_ID = 1;

void updateSymCounter(TextSymbolsInfo &info, char &c);

int predictLanguage(TextSymbolsInfo &info);

void calculateSymFrequencyStat(TextSymbolsInfo &info);

void calculateSymFrequencyDifference(TextSymbolsInfo &info, int langId);
string languageFromLandId(int langId);

TextSymbolsInfo proceedText(string &text) {
    TextSymbolsInfo result;
    result.total = 0;
    result.alfabetic = 0;
    result.digit = 0;
    result.spaces = 0;
    result.other = 0;
    std::transform(text.begin(), text.end(), text.begin(), ::toupper);

    for (char c:text) {
        ++result.total;
        if (c >= 0 && c <= 255) {
            if (isalpha(c)) {
                ++result.alfabetic;
                updateSymCounter(result, c);
            } else if (isdigit(c)) {
                ++result.digit;
            } else if (c == ' ') {
                ++result.spaces;
            }
        } else ++result.other;
    }
    result.rawText.append(text);
    calculateSymFrequencyStat(result);
    calculateSymFrequencyDifference(result, ENGLISH_LANG_ID);
    predictLanguage(result);
    return result;
}

void printTextSymbInfo(TextSymbolsInfo &info) {
    map<char, float> ls = languageStatisticsByLangId(info.langId);

    cout << "total symbols " + std::to_string(info.total) << endl;
    cout << "alpha symbols " + std::to_string(info.alfabetic) << endl;
    cout << "digit symbols " + std::to_string(info.digit) << endl;
    cout << "space symbols " + std::to_string(info.spaces) << endl;
    cout << "other symbols " + std::to_string(info.other) << endl;
    cout << "RAW " + info.rawText << endl;
    for (auto it = info.symCounter.cbegin(); it != info.symCounter.cend(); ++it) {
        std::map<char, float>::iterator iter1 = info.symFrequencyStat.find(it->first);
        std::map<char, float>::iterator iter2 = ls.find(it->first);
        std::map<char, float>::iterator iter3 = info.symFrequencySimilarity.find(it->first);

        std::cout << " letter " << it->first<<
                      " quntity " + std::to_string(it->second)
                     + " message frequency " + std::to_string(iter1->second)
                     + " standard frequency " + std::to_string(iter2->second)
                     + " difference " + std::to_string(iter3->second)

                  << "\n";
    }


    cout << "print average deviation " + std::to_string(info.diffetenceInSimilarity) << endl;
    cout << "It looks like the language of message is " + languageFromLandId(predictLanguage(info)) << endl;

}

int predictLanguage(TextSymbolsInfo &info) {
    if (info.diffetenceInSimilarity < 1.3) {
        return info.langId;
    } else return UNKNOWN_LANG_ID;
}

void calculateSymFrequencyStat(TextSymbolsInfo &info) {
    for (auto it = info.symCounter.cbegin(); it != info.symCounter.cend(); ++it) {
        std::cout << it->first << " " << std::to_string(it->second) << "\n";
        float f = (float(it->second) / info.total) * 100;
        info.symFrequencyStat.insert(std::make_pair(it->first, ceilf(f * 100) / 100));
    }
}

void calculateSymFrequencyDifference(TextSymbolsInfo &info, int langId) {
    map<char, float> ls = languageStatisticsByLangId(langId);
    float deviation = 0;
    float deviationAll = 0;

    for (auto it = info.symFrequencyStat.cbegin(); it != info.symFrequencyStat.cend(); ++it) {
        std::map<char, float>::iterator iter = ls.find(it->first);
        if (iter != ls.end()) {
            deviation = it->second - iter->second;
            deviationAll += fabs(deviation);
        } else {
            deviation = it->second;
            deviationAll += fabs(deviation);
        }
        info.symFrequencySimilarity.insert(std::make_pair(it->first, deviation));
    }
    if (deviationAll > 0) {
        deviationAll = deviationAll / info.symFrequencySimilarity.size();
    } else deviationAll = 100;
    info.diffetenceInSimilarity = deviationAll;
    info.langId = langId;
}


void updateSymCounter(TextSymbolsInfo &info, char &c) {
    std::map<char, int>::iterator iter = info.symCounter.find(c);
    if (iter != info.symCounter.end()) {
        ++iter->second;
    } else {
        info.symCounter.insert(std::make_pair(c, 1));
    }
}

map<char, float> languageStatisticsByLangId(int langId) {
    if (langId == ENGLISH_LANG_ID) {
        return englishLettersStat;
    }
    return englishLettersStat;
}

string languageFromLandId(int langId){
    if (langId == ENGLISH_LANG_ID) {
        return "ENGLISH";
    }
    return "UNKNOWN";
}
