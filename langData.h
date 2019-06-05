//
// Created by Oleksandr Sereda on 5/30/2019.
//

#ifndef UNTITLED_LANGDATA_H
#define UNTITLED_LANGDATA_H

#include <map>

using namespace std;

typedef map<char, float> Map;


const map <char, float> englishLettersStat = {
        std::make_pair('E', 12.60),
        std::make_pair('T', 9.37),
        std::make_pair('A', 8.34),
        std::make_pair('O', 7.70),
        std::make_pair('N', 6.80),
        std::make_pair('I', 6.71),
        std::make_pair('S', 6.11),
        std::make_pair('R', 5.68),
        std::make_pair('H', 6.11),
        std::make_pair('D', 4.14),
        std::make_pair('L', 4.24),
        std::make_pair('U', 2.85),
        std::make_pair('C', 2.73),
        std::make_pair('M', 2.53),
        std::make_pair('F', 2.03),
        std::make_pair('Y', 2.04),
        std::make_pair('W', 2.34),
        std::make_pair('G', 1.92),
        std::make_pair('P', 1.66),
        std::make_pair('B', 1.54),
        std::make_pair('V', 1.06),
        std::make_pair('K', 0.87),
        std::make_pair('X', 0.20),
        std::make_pair('Q', 0.09),
        std::make_pair('J', 0.23),
        std::make_pair('Z', 0.06)
};
#endif //UNTITLED_LANGDATA_H
