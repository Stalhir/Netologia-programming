#include <iostream>

using namespace std;


#define MODE 1


#ifndef MODE
#error "Необходимо определить MODE"
#endif


#if MODE == 1
int add(int a, int b) {
    return a + b;
}
#endif

int main() {
    setlocale(LC_ALL, "rus"); 
#if MODE == 0
    cout << "Работаю в режиме тренировки" << endl;
#elif MODE == 1
    cout << "Работаю в боевом режиме" << endl;
    int num1, num2;
    cout << "Введите два числа: " << endl;
    cin >> num1;
    cin >> num2;
    int result = add(num1, num2);
    cout << "Результат сложения: " << result << endl;
#else
    cout << "Работаю в режиме тренировки" << endl;
#endif

    return 0;
}