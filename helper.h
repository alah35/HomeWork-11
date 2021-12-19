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

std::string firstHalfLine(std::string s, char ch);

std::string secondHalfLine(std::string s, char ch);

bool isMatch(std::string str, std::string substr);

bool isValidFirstHalf(std::string);

bool isValidSecondHalf(std::string);

std::string getNumFromIP(std::string, int x);

bool isValidIP(std::string);
#endif //HOMEWORK_11_HELPER_H
