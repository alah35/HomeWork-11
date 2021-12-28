#include <string>
#include <iostream>
#include "task_1.h"

void task1() {
    std::string input;
    int parameter;
    std::cout << "Enter your text: ";
    std::cin.ignore(256, '\n');
    std::getline(std::cin, input);
    std::cout << "Enter the encryption parameter: ";
    std::cin >> parameter;

    std::cout << "Encrypted text: " << encrypt_caesar(input, parameter) << std::endl;
    std::cout << "Decrypted text: " << decrypt_caesar(encrypt_caesar(input, parameter), parameter) << std::endl;
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