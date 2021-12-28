#include <iostream>
#include "Headers/task_1.h"
#include "Headers/task_2.h"
#include "Headers/task_3.h"
#include "Headers/task_4.h"
#include "Headers/task_5.h"


int main() {
    int num;
    do {
    std::cout << "\nFor exit enter -1.\n Enter task number: ";
    std::cin >> num;
        switch (num) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            default:
                std::cout << "Wrong number. Try again\n";
        }
    } while (num != -1);
}