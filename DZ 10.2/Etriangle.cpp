#include "Etriangle.h"
#include <iostream>

using namespace std;


void Etriangle::print_info()
{

    cout << "�������������� �����������: " << endl;
    if (Check()) { cout << "����������" << endl; }
    else { cout << "������������" << endl; }
    cout << "���������� ������: " << sides_count << endl;
    cout << "C������: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "����: A=" << A << " B=" << B << " C=" << C << endl;
}

bool Etriangle::Check() 
{
    if (a == b && c == b && a == c && A == 60 && B == 60 && C == 60 && Triangle::Check() == true) { return true; }
    else { return false; }
}