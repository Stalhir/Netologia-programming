#include "Etriangle.h"
#include <iostream>

using namespace std;


void Etriangle::print_info()
{

    cout << "Равносторонний треугольник: " << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
    cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
}

bool Etriangle::Check() 
{
    if (a == b && c == b && a == c && A == 60 && B == 60 && C == 60 && Triangle::Check() == true) { return true; }
    else { return false; }
}