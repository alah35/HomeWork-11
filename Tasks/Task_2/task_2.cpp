#include "task_2.h"
#include <string>
#include <iostream>

void task2() {
    std::string email;
    std::cout << "Enter your email address: ";
    std::cin >> email;
    if (isValidFirstHalf(email) && isValidSecondHalf(email))
        std::cout << "Yes\n";
    else std::cout << "No\n";
}

std::string getFirstHalfOfLine(std::string s, char ch) { // returns the part of the string before symbol ch
    std::string firstHalf = "";
    if (s.find(ch) == std::string::npos)
        return "";
    else {
        for (int i = 0; i < s.find(ch); i++) {
            firstHalf += s[i];
        }
        return firstHalf;
    }
}

std::string getSecondHalfOfLine(std::string s, char ch) { // returns the part of the string after symbol ch
    std::string secondHalf = "";
    if (s.find(ch) == std::string::npos)
        return "";
    else {
        for (int i = s.find(ch) + 1; i < s.length(); i++) {
            secondHalf += s[i];
        }
        return secondHalf;
    }
}

bool isMatch(std::string str, std::string substr) { // check if substr is included in a str
    if (str.find(substr[0]) == std::string::npos)
        return false;
    for (int i = str.find(substr[0]); i < str.length() - substr.length(); i++) {
        for (int j = 0; j < substr.length(); j++) {
            if (str[i + j] != substr[j])
                break;
            else if (j == substr.length() - 1)
                return true;
        }
    }
    return false;
}

bool isValidFirstHalf(std::string s) {
    s = getFirstHalfOfLine(s, '@');
    if (s == "" || s[0] == '.' || s[s.length() - 1] == '.' || s.length() > 64 || isMatch(s,"..")) {
        return false;
    }
    std::string allowedSymbols = "!#$%&'*+-/=?^_`{|}~.-";
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] < '0' || s[i] > '9') && (s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')) {
            if (allowedSymbols.find(s[i]) == std::string::npos)
                return false;
        }
    }
    return true;
}

bool isValidSecondHalf(std::string s) {
    s = getSecondHalfOfLine(s, '@');
    if (s == "" || s[0] == '.' || s[s.length() - 1] == '.' || s.length() > 63 || isMatch(s, "..")
        || s.find('@') != std::string::npos)
        return false;
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] < '0' || s[i] > '9') && (s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z')
            && s[i] != '-' && s[i] != '.') {
            return false;
        }
    }
    return true;
}