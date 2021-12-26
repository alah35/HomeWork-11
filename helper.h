//
// Created by maxne on 16.12.2021.
//

#ifndef HOMEWORK_11_HELPER_H
#define HOMEWORK_11_HELPER_H

void task1();

void task2();

void task3();

void task4();

void task5();

std::string encrypt_caesar (std::string s, int parameter);

std::string decrypt_caesar(std::string s, int parameter);

std::string getFirstHalfOfLine(std::string s, char ch);

std::string getSecondHalfOfLine(std::string s, char ch);

bool isMatch(std::string str, std::string substr);

bool isValidFirstHalf(std::string);

bool isValidSecondHalf(std::string);

std::string getPartFromString(std::string, int x, char ch);

bool isValidIP(std::string);

bool isCorrectNum(std::string s);

std::string convertForCompareInt(std::string);

std::string convertForCompareFraction(std::string);

std::string MoreOrLess(std::string a, std::string b);

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

#endif //HOMEWORK_11_HELPER_H
