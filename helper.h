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

std::string MoreOrLess (std::string a, std::string b);
#endif //HOMEWORK_11_HELPER_H
