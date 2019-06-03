//
// Created by Oleksandr Sereda on 5/30/2019.
//

#include<iostream>
#include<string> // for string class
#include <vector>
#include "languageStatisctics.h"
#include "menu.h"

using namespace std;

int main() {
    int menuId = MAIN_MENU_ID;
    int key;
    for (int i=1; i>0;) {
        printMenuInfo(menuId);
        key = readKey();
        if (validateKeyInScope(key, menuId)) {
            executeMenuAction(key, menuId);
        } else printInfoMessage(PRINT_KEY_IS_NOT_VALID, to_string(key), menuId);
    }
    return 0;
}
