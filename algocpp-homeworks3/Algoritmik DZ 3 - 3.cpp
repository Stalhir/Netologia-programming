﻿#include <iostream>
using namespace std;

void count_sort(int* arr, int size) {
    const int min_val = 10;
    const int max_val = 24;
    const int range = max_val - min_val + 1;

    int count[range] = { 0 };

    for (int i = 0; i < size; ++i) {
        count[arr[i] - min_val]++;
    }

    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (count[i] > 0) {
            arr[index++] = i + min_val;
            count[i]--;
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    count_sort(arr1, size1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    int arr2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    count_sort(arr2, size2);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    int arr3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < size3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    count_sort(arr3, size3);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}