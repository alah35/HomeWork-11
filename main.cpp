#include <iostream>
#include "helper.h"


int main() {
    std::string line1, line2, line3;
    std::cout << "Enter the playing field state:\n";
    std::cin >> line1 >> line2 >> line3;
    const int SIZE_FIELD = 3;
    std::string field[SIZE_FIELD] = {line1, line2, line3};
    outputField(field);
    if (!isValidField(field))
        std::cout << "Incorrect";
    else
        std::cout << getWinner(field);
}