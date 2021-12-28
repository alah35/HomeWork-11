#include "../Headers/task_3.h"
#include "../Headers/task_2.h"
#include <string>
#include <iostream>

void task3() {
    std::string ip;
    std::cout << "Enter IP address: ";
    std::cin >> ip;

    isValidIP(ip) ? std::cout << "Yes" : std::cout << "No";
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