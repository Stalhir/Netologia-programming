#include "Rectangle.h"
#include <iostream>

using namespace std;


void Rectangle::print_info() 
{

    cout << "Прямоугольник: " << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
    cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
}
bool Rectangle::Check() 
{
    if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90 && Quadrangle::Check() == true) { return true; }
    else { return false; }
}
