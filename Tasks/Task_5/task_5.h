#include <string>
#include <iostream>

#ifndef HOMEWORK_11_TASK_5_H
#define HOMEWORK_11_TASK_5_H

void task5();

void outputField(std::string *s);

char getElem(std::string *s, int x, int y);

std::string getLine(std::string *s, int x);

std::string getColumn(std::string *s, int x);

bool isWinnerInLine(std::string s);

bool isWinnerInDiagonal1(std::string *s);

bool isWinnerInDiagonal2(std::string *s);

int getAmountOfSym(std::string *s, char ch);

std::string getWinner(std::string *s);

bool isValidField(std::string *s);

#endif //HOMEWORK_11_TASK_5_H
