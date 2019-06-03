//
// Created by Oleksandr Sereda on 5/30/2019.
//

#ifndef UNTITLED_LANGUAGESTATISCTICS_H
#define UNTITLED_LANGUAGESTATISCTICS_H

#include<string> // for string class
#include <map>

using namespace std;

extern const int ENGLISH_LANG_ID;
extern const int UNKNOWN_LANG_ID;
struct TextSymbolsInfo {
    int total;
    int alfabetic;
    int digit;
    int spaces;
    int other;
    string rawText;
    int langId;
    float diffetenceInSimilarity;
    map<char, int> symCounter;
    map<char, float> symFrequencyStat;
    map<char, float> symFrequencySimilarity;
};

void printTextSymbInfo(TextSymbolsInfo &);

TextSymbolsInfo proceedText(string &);

map <char, float> languageStatisticsByLangId(int);

#endif //UNTITLED_LANGUAGESTATISCTICS_H
