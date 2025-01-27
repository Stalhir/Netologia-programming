#include "Rhomb.h"
#include <iostream>

using namespace std;


void Rhomb::print_info() 
{
   

    cout << "Ромб: " << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
    cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
}
bool Rhomb::Check() 
{
    if (a == c && a == b && a == d && b == d && c == d && A == C && B == D && Quadrangle::Check() == true) { return true; }
    else { return false; }
}
