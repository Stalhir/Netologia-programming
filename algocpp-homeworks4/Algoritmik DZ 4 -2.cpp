#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < logical_size; ++i) {
        std::cout << arr[i] << " ";
    }
    
    for (int i = logical_size; i < actual_size; ++i) {
        std::cout << "_ ";
    }
    std::cout << std::endl;
}

void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int new_element) {
    
    if (logical_size < actual_size) {
        arr[logical_size] = new_element;
        logical_size++;
    }
    else {
       
        int new_actual_size = actual_size * 2;
        int* new_arr = new int[new_actual_size];

        for (int i = 0; i < actual_size; ++i) {
            new_arr[i] = arr[i];
        }
       
        new_arr[logical_size] = new_element;
        logical_size++;
        actual_size = new_actual_size;

        delete[] arr;
        arr = new_arr;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int actual_size, logical_size;

    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;

    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    while (logical_size > actual_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        std::cout << "Введите фактический размер массива: ";
        std::cin >> actual_size;

        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }


    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    int new_element;
    while (true) {
        std::cout << "Введите элемент для добавления: ";
        std::cin >> new_element;

        if (new_element == 0) {
            break; 
        }

        append_to_dynamic_array(arr, logical_size, actual_size, new_element);

        std::cout << "Динамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);
    }

    std::cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    
    delete[] arr;

    return 0;
}