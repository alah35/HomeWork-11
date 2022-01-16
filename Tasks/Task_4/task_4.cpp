#include "task_4.h"
#include "../Task_3/task_3.h"

void task4(){
    std::string a, b;
    std::cout << "Enter your num a =  ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

//    std::cout << getIntPart(a) << " " << getFracPart(a) << std::endl;
//    std::cout << getIntPart(b) << " " << getFracPart(b) << std::endl;

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
            if (s[i] >= '0' && s[i] <= '9') isThereNum = true; //alternative: bool isThereNum = s[i] >= '0' && s[i] <= '9';
        }
        if (s.length() == 1 && s[0] >= '0' && s[0] <= '9') isThereNum = true; // isThereNum = s.length() == 1 && s[0] >= '0' && s[0] <= '9';
    }
    if (!isThereNum)
        return false;
    return true;
}

std::string getIntPart(std::string s) {
    if (s[0] == '.') {
        return "0";
    } else {
        std::string result = "";
        int endIntPart = s.find('.');
        if (endIntPart == std::string::npos)
            endIntPart = s.length();
        for (int i = 0; i < endIntPart; i++) {
            result += s[i];
        }
        if (result == "-")
            return "-1";
        else
            return result;
    }
}

std::string getFracPart(std::string s) {
    std::string result = "";
    if (s[s.length() - 1] == '.' || s.find('.') == std::string::npos)
        return "0";
    else {
        for (int i = s.find('.') + 1; i < s.length(); i++) {
            result += s[i];
        }
    }
    return result;
}

char getFracNum (std::string s, int x) {
    if (x > (s.length() - 1))
        return '0';
    else
        return s[x];
}

std::string MoreOrLess(std::string a, std::string b) {
    if (isCorrectNum(a) && isCorrectNum(b)) {
        std::string aInt = getIntPart(a);
        std::string bInt = getIntPart(b);
        if (aInt[0] != '-' && bInt[0] != '-') {
            if (aInt.length() > bInt.length())
                return "More";
            if (aInt.length() < bInt.length())
                return "Less";
        } else if (aInt[0] == '-' && bInt[0] == '-') {
            if (aInt.length() > bInt.length())
                return "Less";
            if (aInt.length() < bInt.length())
                return "More";
        }
        for (int i = 0; i < aInt.length(); i++) {
            if (aInt[i] > bInt[i])
                return "More";
            if (aInt[i] < bInt[i])
                return "Less";
        }

        int endCompare;
        std::string aFrac = getFracPart(a);
        std::string bFrac = getFracPart(b);
        aFrac.length() > bFrac.length() ? endCompare = aFrac.length() : endCompare = bFrac.length();
        for (int i = 0; i < endCompare; i++) {
            if (aInt[0] == '-' && bInt[0] == '-') {
                if (getFracNum(aFrac, i) > getFracNum(bFrac, i))
                    return "Less";
                if (getFracNum(aFrac, i) < getFracNum(bFrac, i))
                    return "More";
            } else {
                if (getFracNum(aFrac, i) > getFracNum(bFrac, i))
                    return "More";
                if (getFracNum(aFrac, i) < getFracNum(bFrac, i))
                    return "Less";
            }
        }
        return "Equal";
    } else
        return "Uncorrect numbers";
}