#include "Triangle.h"
#include <iostream>

using namespace std;

void Triangle::print_info() 
{


    cout << "Треугольник: " << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
    cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
}
bool Triangle::Check() 
{

    if ((A + B + C) == 180) { return true; }
    else { return false; }
}


