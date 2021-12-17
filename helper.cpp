#include <string>
#include "helper.h"

std::string encrypt_caesar (std::string s, int parameter) {
    for (int i = 0; i < s.length(); i++) {
        if ( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ) {
            if (s[i] + parameter > 'Z' && s[i] == toupper(s[i])) {
                s[i] = (s[i] + parameter - 'Z') +'A' - 1;
            } else if (s[i] + parameter > 'z' && s[i] != toupper(s[i])) {
                s[i] = (s[i] + parameter - 'z') +'a' - 1;
            } else s[i] += parameter;
        }
    }
    return s;
}

std::string decrypt_caesar (std::string s, int parameter) {
    for (int i = 0; i < s.length(); i++) {
        if ( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ) {
            if (s[i] - parameter < 'A' && s[i] == toupper(s[i]))
                s[i] = 'Z' - ('A' - (s[i] - parameter)) + 1;
            else if (s[i] - parameter < 'a' && s[i] != toupper(s[i]))
                s[i] = 'z' - ('a' - (s[i] - parameter)) + 1;
            else s[i] -= parameter;
        }
    }
    return s;
}

std::string firstHalfLine(std::string s, char ch) { // returns the part of the string before symbol ch
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

std::string secondHalfLine(std::string s, char ch) { // returns the part of the string after symbol ch
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
            else if (j == substr.length() - 1) return true;
        }
    }
    return false;
}

bool isValidFirstHalf(std::string s) {
    s = firstHalfLine(s, '@');
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
    s = secondHalfLine(s, '@');
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



