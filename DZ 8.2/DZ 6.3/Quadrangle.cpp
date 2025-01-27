#include "Quadrangle.h"
#include <iostream>

using namespace std;



void Quadrangle::print_info()
{
    cout << "��������������: " << endl;
    if (Check()) { cout << "����������" << endl; }
    else { cout << "������������" << endl; }
    cout << "���������� ������: " << sides_count << endl;
    cout << "C������: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
}
bool Quadrangle::Check() 
{
    if ((A + B + C + D) == 360) { return true; }
    else { return false; }
}