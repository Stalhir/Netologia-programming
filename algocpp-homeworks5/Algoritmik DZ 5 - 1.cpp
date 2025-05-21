#include <iostream>

void print_element(int level, const char* relation, int idx, int arr[]) {
    if (level == 0) {
        std::cout << level << " " << relation << " " << arr[idx] << std::endl;
    }
    else {
        std::cout << level << " " << relation << "(" << arr[(idx - 1) / 2] << ") " << arr[idx] << std::endl;
    }
}

void print_pyramid(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int level = 0;
        int current = i;

        
        while (current > 0) {
            current = (current - 1) / 2;
            level++;
        }

        
        if (i == 0) {
            print_element(level, "root", i, arr);
        }
        else if (i % 2 == 1) {
            print_element(level, "left", i, arr);
        }
        else {
            print_element(level, "right", i, arr);
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    // Тестовые массивы внизу
    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    std::cout << "Исходный массив: 1 3 6 5 9 8" << std::endl;
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr1, sizeof(arr1) / sizeof(arr1[0]));

    std::cout << "Исходный массив: 94 67 18 44 55 12 6 42" << std::endl;
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr2, sizeof(arr2) / sizeof(arr2[0]));

    std::cout << "Исходный массив: 16 11 9 10 5 6 8 1 2 4" << std::endl;
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr3, sizeof(arr3) / sizeof(arr3[0]));

    return 0;
}