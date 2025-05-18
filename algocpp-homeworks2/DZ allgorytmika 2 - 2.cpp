#include <iostream>

using namespace std;

int fibonacci(int n) {
    int* fib = new int[n + 1]; 
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; 
    }

    int result = fib[n]; 
    delete[] fib; 
    return result; 
}

int main() {
    setlocale(LC_ALL, "rus");

    int n;

    cout << "Введите n: ";
    cin >> n;

    if (n < 0) {
        cout << "n должно быть неотрицательным!" << endl;
    }
    else {
        cout << "Число Фибоначчи F(" << n << ") = " << fibonacci(n) << endl;
    }

    return 0;
}