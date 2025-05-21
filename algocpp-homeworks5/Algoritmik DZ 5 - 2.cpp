#include <iostream>
#include <cmath>

using namespace std;


void printPyramid(int arr[], int size) {
    int level = 0;
    int index = 0;

    while (index < size) {
        cout << level << " ";
        for (int i = 0; i < pow(2, level) && index < size; i++) {
            if (i == 0) {
                cout << "root " << arr[index];
            }
            else {
                cout << "left(" << arr[(index - 1) / 2] << ") " << arr[index];
            }
            index++;
            if (i % 2 == 1) {
                cout << " ";
            }
        }
        cout << endl;
        level++;
    }
}

int getParentIndex(int index) {
    return (index - 1) / 2;
}

int getLeftChildIndex(int index) {
    return 2 * index + 1;
}

int getRightChildIndex(int index) {
    return 2 * index + 2;
}

int main() {
    setlocale(LC_ALL, "rus");
    
    int pyramid[] = { 1, 3, 6, 5, 9, 8 };
    int size = sizeof(pyramid) / sizeof(pyramid[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << pyramid[i] << " ";
    }
    cout << endl;

    cout << "Пирамида:" << endl;
    printPyramid(pyramid, size);

    int currentIndex = 0;
    string command;

    while (true) {
        cout << "Вы находитесь здесь: " << currentIndex << " ";
        if (currentIndex == 0) {
            cout << "root " << pyramid[currentIndex] << endl;
        }
        else {
            cout << "left(" << pyramid[getParentIndex(currentIndex)] << ") " << pyramid[currentIndex] << endl;
        }

        cout << "Введите команду: ";
        cin >> command;

        if (command == "up") {
            if (currentIndex == 0) {
                cout << "Ошибка! Отсутствует родитель" << endl;
            }
            else {
                currentIndex = getParentIndex(currentIndex);
                cout << "Ок" << endl;
            }
        }
        else if (command == "left") {
            int leftChildIndex = getLeftChildIndex(currentIndex);
            if (leftChildIndex < size) {
                currentIndex = leftChildIndex;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует левый потомок" << endl;
            }
        }
        else if (command == "right") {
            int rightChildIndex = getRightChildIndex(currentIndex);
            if (rightChildIndex < size) {
                currentIndex = rightChildIndex;
                cout << "Ок" << endl;
            }
            else {
                cout << "Ошибка! Отсутствует правый потомок" << endl;
            }
        }
        else if (command == "exit") {
            break;
        }
        else {
            cout << "Ошибка! Неверная команда" << endl;
        }
    }

    return 0;
}