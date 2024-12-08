#include <iostream>

using namespace std;

struct Adres
{
    string city;
    string street;
    int houseNumber;
    int apartmentNumber;
    int index;

};

void CoutAdres(Adres adr)
{
    cout << "Город "<< adr.city;
    cout << endl;
    cout << "Улица " << adr.street;
    cout << endl;
    cout << "Номер дома " << adr.houseNumber;
    cout << endl;
    cout << "Номер Квартиры " << adr.apartmentNumber;
    cout << endl;
    cout << "Индекс " << adr.index;
}

int main()
{
    setlocale(LC_ALL, "rus");
    Adres Mos{"Москва","Арбат",12,8,123456};
    Adres Ize{ "Ижевск","Пушкина",59,143,953769 };

    CoutAdres(Mos);
    cout << endl << endl;
    CoutAdres(Ize);
}

