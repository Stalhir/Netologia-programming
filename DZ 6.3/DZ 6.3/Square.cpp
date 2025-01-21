#include "Square.h"
#include <iostream>

using namespace std;


void Square::print_info()
{

    cout << "Квадрат: " << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
    cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
}
bool Square::Check()
{
    if (a == c && a == b && a == d && b == d && c == d && A == 90 && B == 90 && C == 90 && D == 90 && Quadrangle::Check() == true) { return true; }
    else { return false; }
}