#include <iostream>
#include "helper.h"


int main() {
std::string ip;
std::cout << "Enter IP address: ";
std::cin >> ip;

isValidIP(ip) ? std::cout << "Yes" : std::cout << "No";

}

