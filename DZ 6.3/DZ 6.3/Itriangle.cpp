#include "Itriangle.h" 
#include <iostream>

using namespace std;


void Itriangle::print_info() 
{

    cout << "Равнобедренный треугольник: " << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
    cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
}
bool Itriangle::Check() 
{
    if (a == c && A == C && Triangle::Check() == true) { return true; }
    else { return false; }
}