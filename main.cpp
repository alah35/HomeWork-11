#include <iostream>
#include "helper.h"


int main() {
    // Task 1
//    std::string input;
//    int parameter;
//    std::cout << "Enter your text: ";
//    std::getline(std::cin, input);
//    std::cout << "Enter the encryption parameter: ";
//    std::cin >> parameter;
//
//    std::cout << "Encrypted text: " << encrypt_caesar(input, parameter) << std::endl;
//    std::cout << "Decrypted text: " << decrypt_caesar(encrypt_caesar(input, parameter), parameter) << std::endl;

    // Task 2'
    std::string email;
    std::cout << "Enter your email address: ";
    std::cin >> email;

    if (isValidFirstHalf(email) && isValidSecondHalf(email))
        std::cout << "Yes\n";
    else std::cout << "No\n";
}
