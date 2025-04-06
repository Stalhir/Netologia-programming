#include <iostream>

int countGreaterThan(int arr[], int size, int reference) {
  
    int left = 0;
    int right = size - 1;
    int index = size; 

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > reference) {
            index = mid; 
            right = mid - 1; 
        }
        else {
            left = mid + 1; 
        }
    }

   
    return size - index;
}

int main() {
    setlocale(LC_ALL, "rus");
    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int reference;
    std::cout << "Введите точку отсчета: ";
    std::cin >> reference;

    int count = countGreaterThan(arr, size, reference);
    std::cout << "Количество элементов в массиве больших, чем " << reference << ": " << count << std::endl;

    return 0;
}