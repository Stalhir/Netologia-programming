#include <iostream>
#include <string>
#include <windows.h>
 
int main() {  
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    std::string name; 

    std::cout << "Введите имя: "; 
    std::getline(std::cin, name); 
     
    std::cout << "Здравствуйте, " << name << "!" << std::endl; 
     
    return 0;
}