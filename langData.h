//
// Created by Oleksandr Sereda on 5/30/2019.
//

#ifndef UNTITLED_LANGDATA_H
#define UNTITLED_LANGDATA_H

#include <map>

using namespace std;

typedef map<char, float> Map;


const map <char, float> englishLettersStat = {
        std::make_pair('E', 12.02),
        std::make_pair('T', 9.1),
        std::make_pair('A', 8.12),
        std::make_pair('O', 7.68),
        std::make_pair('I', 7.31),
        std::make_pair('N', 6.95),
        std::make_pair('S', 6.28),
        std::make_pair('R', 6.02),
        std::make_pair('H', 5.92),
        std::make_pair('D', 4.32),
        std::make_pair('L', 3.98),
        std::make_pair('U', 2.88),
        std::make_pair('C', 2.71),
        std::make_pair('M', 2.61),
        std::make_pair('F', 2.3),
        std::make_pair('Y', 2.11),
        std::make_pair('W', 2.09),
        std::make_pair('G', 2.03),
        std::make_pair('P', 1.82),
        std::make_pair('B', 1.49),
        std::make_pair('V', 1.11),
        std::make_pair('K', 0.69),
        std::make_pair('X', 0.17),
        std::make_pair('Q', 0.11),
        std::make_pair('J', 0.1),
        std::make_pair('Z', 0.07)
};
#endif //UNTITLED_LANGDATA_H
