#include <iostream>
#include "Greet.h"
#include "windows.h" 

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    std::string temp;
    Greeter a;
    std::cout << "Введите имя:";
    std::cin >> temp;
    std::cout << a.greet(temp) << std::endl;
}
