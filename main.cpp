#include <iostream>
#include "Tasks/Task_1/task_1.h"
#include "Tasks/Task_2/task_2.h"
#include "Tasks/Task_3/task_3.h"
#include "Tasks/Task_4/task_4.h"
#include "Tasks/Task_5/task_5.h"


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