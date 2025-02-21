#include <iostream>
#include "Windows.h" 
#include "Leaver.h"



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    std::string temp;
    Leaver a;
    std::cout << "Введите имя:";
    std::cin >> temp;
    std::cout << a.leave(temp) << std::endl;
    std::cin >> temp;
}
