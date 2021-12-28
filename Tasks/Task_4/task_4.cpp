#include "task_4.h"
#include "../Task_3/task_3.h"

void task4(){
    std::string a, b;
    std::cout << "Enter your num a =  ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << MoreOrLess(a, b);
}

bool isCorrectNum(std::string s) {
    bool isThereNum = false;
    if ( s[0] == '+' || ( (s[0] < '0' || s[0] > '9') && s[0] != '-' && s[0] != '.' ) )
        return false; // filter for the first symbol
    else {// if it's ok, make a pass along the string
        for (int i = 1; i < s.length(); i++) { // start from 1 pos because we have filter for the first symbol
            if (s[i] < '0' || s[i] > '9') {
                if (s[i] != '.') {
                    return false;
                } else {
                    if  ( (s[0] != '.' && s.find('.', i + 1) != std::string::npos)
                          || (s[0] == '.' && s.find('.', 1) != std::string::npos) ) {
                        return false;
                    }
                }
            }
            if (s[i] >= '0' && s[i] <= '9') isThereNum = true;
        }
        if (s.length() == 1 && s[0] >= '0' && s[0] <= '9') isThereNum = true;
    }
    if (!isThereNum)
        return false;
    return true;
}

std::string convertForCompareInt(std::string s) {
    if (s == "")
        return "0";
    std::string num = "";
    if (s[0] == '-' && s.length() == 1) {
        return "-0";
    } else if (s[0] == '0') {
        for (int i = 1; i < s.length(); i++) {
            num += s[i];
        }
    } else {
        for (int i = 0; i < s.length(); i++) {
            num += s[i];
        }
    }
    return num;
}

std::string convertForCompareFraction(std::string s) {
    if (s == "")
        return "0";
    std::string num = "";
    for(int i = 0; i < s.length(); i++) {
        num += s[i];
    }
    return num;
}

std::string MoreOrLess(std::string a, std::string b) {
    if (isCorrectNum(a) && isCorrectNum(b)) {
        std::string num1Int = convertForCompareInt(getPartFromString(a, 1, '.'));
        std::string num2Int = convertForCompareInt(getPartFromString(b, 1, '.'));
        std::string num1Frac = convertForCompareFraction(getPartFromString(a, 2, '.'));
        std::string num2Frac = convertForCompareFraction(getPartFromString(b, 2, '.'));
        std::string num1 = num1Int + '.' + num1Frac;
        std::string num2 = num2Int + '.' + num2Frac;
        if (std::stof(num1) > std::stof(num2))
            return "More";
        else if (std::stof(num1) < std::stof(num2))
            return "Less";
        else return "Equal";
    } else
        return "-1";
}