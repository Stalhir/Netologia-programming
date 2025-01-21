#include "Parallelogram.h"
#include <iostream>

using namespace std;


void Parallelogram::print_info() 
{

    cout << "��������������: " << endl;
    if (Check()) { cout << "����������" << endl; }
    else { cout << "������������" << endl; }
    cout << "���������� ������: " << sides_count << endl;
    cout << "C������: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
}
bool Parallelogram::Check() 
{
    if (a == c && b == d && A == C && B == D && Quadrangle::Check() == true) { return true; }
    else { return false; }
}