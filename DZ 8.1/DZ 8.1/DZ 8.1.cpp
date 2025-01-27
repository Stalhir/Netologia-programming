#include <iostream>
#include <string>

using namespace std; 

class bad_length : public std::exception {
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания"; }
};

int function(std::string& str, int forbidden_length) {
    int length = (str.length());
    if (length == forbidden_length) {
        throw bad_length();
    }
    return length;
}

int main() {
    setlocale(LC_ALL, "rus"); 
    int forbidden_length{};
    cout << "Введите запретную длину: ";
    cin >> forbidden_length;
    cin.ignore(); 

    string temp;
    while (true) {
        cout << "Введите слово: ";
        getline(std::cin, temp); 
        
        try {
            int length = function(temp, forbidden_length); 
            cout << "Длина слова \"" << temp << "\" равна " << length << endl; 
        }
        catch (const bad_length& e) {
            cout<<e.what();
            
            break;
        }
    }

    return 0;
}