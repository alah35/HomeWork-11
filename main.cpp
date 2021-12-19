#include <iostream>
#include "helper.h"


int main() {
std::string ip;
std::cout << "Enter IP address: ";
std::cin >> ip;

std::cout << getNumFromIP(ip, 1) << " " << getNumFromIP(ip, 2) << " " << getNumFromIP(ip, 3)
          << " " << getNumFromIP(ip, 4);

}
