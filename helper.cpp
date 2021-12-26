#include <string>
#include <iostream>
#include "helper.h"

void task1() {
    std::string input;
    int parameter;
    std::cout << "Enter your text: ";
    std::getline(std::cin, input);
    std::cout << "Enter the encryption parameter: ";
    std::cin >> parameter;

    std::cout << "Encrypted text: " << encrypt_caesar(input, parameter) << std::endl;
    std::cout << "Decrypted text: " << decrypt_caesar(encrypt_caesar(input, parameter), parameter) << std::endl;
}

void task2() {
    std::string email;
    std::cout << "Enter your email address: ";
    std::cin >> email;
    if (isValidFirstHalf(email) && isValidSecondHalf(email))
        std::cout << "Yes\n";
    else std::cout << "No\n";
}

void task3() {
    std::string ip;
    std::cout << "Enter IP address: ";
    std::cin >> ip;

    isValidIP(ip) ? std::cout << "Yes" : std::cout << "No";
}

void task4(){
    std::string a, b;
    std::cout << "Enter your num a =  ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << MoreOrLess(a, b);
}

void task5() {

}

std::string encrypt_caesar (std::string s, int parameter) { // encrypt string
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

std::string decrypt_caesar (std::string s, int parameter) { // decrypt string
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

std::string getPartFromString(std::string s, int x, char ch) { // where: s - source string, ch - symbol-marker, x - which part (1, 2, 3)
    if (x < 1 || x > 4 || (s.find(ch) == std::string::npos && x > 1))
        return "";
    int pointPos = 0;
    for (int i = 1; i <= x; i++) {
        pointPos = s.find(ch, pointPos + 1);
    }
    int rightPos;
    pointPos == std::string::npos ? rightPos = s.length() : rightPos = pointPos;
    int leftPos;
    s.rfind('.',rightPos- 1) == std::string::npos ? leftPos = 0 : leftPos = s.rfind('.',rightPos - 1);

    std::string answer = "";
    int i;
    leftPos == 0 ? i = leftPos : i = leftPos + 1;
    for (; i < rightPos; i++) {
        answer += s[i];
    }
    return answer;
}

bool isValidIP(std::string s) {
    int amountPoint = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.')
            amountPoint++;
    }
    if (amountPoint > 3 || s[0] == '.' || s[s.length() -1] == '.' || isMatch(s, ".."))
        return false;

    std::string num;
    for (int i = 1; i <= 4; i++) {
        num = getPartFromString(s, i, '.');
        if (num == "" || (num[0] == '0' && num.length() != 1))
            return false;
        for (int j = 0; j < num.length(); j++) {
            if (num[j] < '0' || num[j] > '9')
                return false;
        }
        if (std::stoi(num) > 255)
            return false;
    }
    return true;
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

 void outputField(std::string *s) {
    for (int i = 0; i < s->length(); i++) {
        for (int j = 0; j < s[i].length(); j++) {
            std::cout << s[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

char getElem(std::string *s, int x, int y) {
    return s[x][y];
}

std::string getLine(std::string *s, int x) {
    std::string line;
    for (int j = 0; j < s[x].length(); j++) {
        line += s[x][j];
    }
    return line;
}

std::string getColumn(std::string *s, int x) {
    std::string column;
    for (int i = 0; i <s->length(); i++) {
        column += s[i][x];
    }
    return column;
}

bool isWinnerInLine(std::string s) {
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1])
            continue;
        else
            return false;
    }
    return true;
}

bool isWinnerInDiagonal1(std::string *s) {
    for (int i = 1; i < s->length(); i++) {
        if (s[i][i] == s[i - 1][i - 1])
            continue;
        else
            return false;
    }
    return true;
}

bool isWinnerInDiagonal2(std::string *s) {
    for (int i = 0; i < s->length(); i++) {
       for (int j = s[i].length() - 1; j > 1; j--) {
           if (s[i][j] == s[i][j - 1])
               continue;
           else
               return false;
       }
    }
    return true;
}

int getAmountOfSym(std::string *s, char ch) {
    int counter = 0;
    for (int i = 0; i < s->length(); i++) {
        for (int j = 0; j < s[i].length(); j++) {
            if (s[i][j] == ch)
               counter++;
        }
    }
    return counter;
}

std::string getWinner(std::string *s) {
    char winner = ' ';
    for (int i = 0; i <s->length(); i++) {
        if (isWinnerInLine(getLine(s, i)) || isWinnerInLine(getColumn(s, i)))
            winner = getElem(s, i, i);
    }
    if (isWinnerInDiagonal1(s))
        winner = s[0][0];
    if (isWinnerInDiagonal2(s))
        winner = s[0][s[0].length()];

    if (winner == 'X')
        return "Petya won";
    else if (winner == 'O')
        return "Vanya won";
    else
        return "Nobody";
}

bool isValidField(std::string *s) {
    int amountWins = 0;
    for (int i = 0; i < s->length(); i++) {
        if (isWinnerInLine(getLine(s, i)))
            amountWins++;
        if (isWinnerInLine(getColumn(s, i)))
            amountWins++;
    }
    if (isWinnerInDiagonal1(s))
        amountWins++;
    if (isWinnerInDiagonal2(s))
        amountWins++;

    if (amountWins > 1)
        return false;

    if (getWinner(s) == "Petya won" && (getAmountOfSym(s, 'O') >= getAmountOfSym(s, 'X')))
        return false;
    if (getWinner(s) == "Vanya won" && (getAmountOfSym(s, 'X') > getAmountOfSym(s, 'O')))
        return false;

    for (int i = 0; i < s->length(); i++){
        for (int j = 0; j < s[i].length(); j++){
            if (s[i][j] != 'O' && s[i][j] != 'X' && s[i][j] != '.')
                return false;
        }
    }

    return true;
}





