#include "Quadrangle.h"
#include <iostream>

using namespace std;



void Quadrangle::print_info()
{
    cout << "Четырёхугольник: " << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
    cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
}
bool Quadrangle::Check() 
{
    if ((A + B + C + D) == 360) { return true; }
    else { return false; }
}