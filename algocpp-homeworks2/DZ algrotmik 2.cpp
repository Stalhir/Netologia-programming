#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2); 
}

int main() {
    setlocale(LC_ALL, "rus"); 
    int n;
    std::cout << "Введите номер числа Фибоначчи: ";
    std::cin >> n;

    std::cout << "Число Фибоначчи в позиции " << n << " равно " << fibonacci(n) << std::endl;
    return 0;
}