#include "RAtriangle.h"
#include <iostream>

using namespace std;


void RAtriangle::print_info()
{


    cout << "Прямоугольный треугольник: " << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
    cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
}
bool RAtriangle::Check()
{

    if (C == 90 && Triangle::Check() == true) { return true; }
    else { return false; }
}