//
// Created by Oleksandr Sereda on 5/30/2019.
//
#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
#include <string>
using namespace std;

extern const int PRINT_KEY_IS_NOT_VALID;

extern const int MAIN_MENU_ID;
extern const int EXIT_KEY;
void printMenuInfo(int menuId);
int readKey();
void printInfoMessage(int templ, string infoMessage, int menuId);
void clearScr();
bool validateKeyInScope(int value, int maxScope);
void executeMenuAction(int key, int menuId);
int getMaxParamScopeFromMenuId(int menuId);

#endif //UNTITLED_MENU_H
