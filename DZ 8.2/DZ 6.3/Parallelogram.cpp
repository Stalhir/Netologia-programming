#include "Parallelogram.h"
#include <iostream>

using namespace std;


void Parallelogram::print_info() 
{

    cout << "Параллелограмм: " << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
    cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
}
bool Parallelogram::Check() 
{
    if (a == c && b == d && A == C && B == D && Quadrangle::Check() == true) { return true; }
    else { return false; }
}