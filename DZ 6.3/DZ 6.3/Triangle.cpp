#include "Triangle.h"
#include <iostream>

using namespace std;

void Triangle::print_info() 
{


    cout << "�����������: " << endl;
    if (Check()) { cout << "����������" << endl; }
    else { cout << "������������" << endl; }
    cout << "���������� ������: " << sides_count << endl;
    cout << "C������: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "����: A=" << A << " B=" << B << " C=" << C << endl;
}
bool Triangle::Check() 
{

    if ((A + B + C) == 180) { return true; }
    else { return false; }
}


