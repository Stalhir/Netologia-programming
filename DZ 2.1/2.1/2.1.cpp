#include <iostream>

using namespace std;

enum months
{
    january = 1,
    february,
    march,
    april,
    may,
    jun,
    july, 
    august, 
    september, 
    october, 
    november, 
    december
};

int main()
{
    setlocale(LC_ALL, "rus");
    
    int temp=1;
    while (temp != 0) {
        cout << "Введите номер месяца: ";
        cin >> temp;
        switch (temp)
        {
        case 0:
            cout << "До свидания";
            return 0;
            break;
        case january:
            cout << "январь" << endl;
            break;
        case february:
            cout << "февраль" << endl;
            break;
        case march:
            cout << "март" << endl;
            break;
        case april:
            cout << "апрель" << endl;
            break;
        case may:
            cout << "май" << endl;
            break;
        case jun:
            cout << "июнь" << endl;
            break;
        case july:
            cout << "июль" << endl;
            break;
        case august:
            cout << "август" << endl;
            break;
        case september:
            cout << "сентябрь" << endl;
            break;
        case october:
            cout << "октябрь" << endl;
            break;
        case november:
            cout << "ноябрь" << endl;
            break;
        case december:
            cout << "декабрь" << endl;
            break;
        default:
            cout << "Неправильный номер!" << endl;
            break;
        }
    }
}

