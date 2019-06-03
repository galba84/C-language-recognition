//
// Created by Oleksandr Sereda on 5/30/2019.
//
#include<iostream>
#include <string>
#include "menu.h"
#include "languageStatisctics.h"
using namespace std;
extern const int PRINT_KEY_IS_NOT_VALID = 1;

extern const int MAIN_MENU_ID = 1;

extern const int EXIT_KEY = 0;

void printMenuInfo(int menuId) {
    if (menuId == MAIN_MENU_ID) {
        cout << "press 1 to enter a message to analize; press 0 to exit program" << endl;
    }
}

int readKey() {
    cin.clear();
    string key;
    getline(cin, key);

    if (key.length() > 0 && key.find_first_not_of("0123456789") == string::npos) {
        return (int) (key.at(0) - '0');
    }
    return -1;
}


void printInfoMessage(int templ, string infoMessage, int menuId) {
    if (templ = PRINT_KEY_IS_NOT_VALID) {
        cout << infoMessage + " is not valid please press key from 0 to " + to_string(getMaxParamScopeFromMenuId(menuId))
             << std::endl;
    }
}

void clearScr();

bool validateKeyInScope(int value, int menuId) {
    return (value >= 0 && value <= getMaxParamScopeFromMenuId(menuId));
}

int getMaxParamScopeFromMenuId(int menuId) {
    if (menuId == MAIN_MENU_ID)
        return 1;
    else return 0;
}

void executeMenuAction(int key, int menuId) {

    if (menuId == MAIN_MENU_ID && key == EXIT_KEY) {
        std::cout << "exit" + key << std::endl;
        exit(0);
    }
    if (menuId == MAIN_MENU_ID && key == 1) {
        cin.clear();
        std::cout << " ENTER MESSAGE TO DETECT LANGUAGE" + key << std::endl;
        string dddd;
        getline(cin, dddd);
        TextSymbolsInfo tsi = proceedText(dddd);
        printTextSymbInfo(tsi);
        dddd.clear();
    }
}
