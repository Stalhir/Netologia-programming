#include "RAtriangle.h"
#include <iostream>

using namespace std;


void RAtriangle::print_info()
{


    cout << "������������� �����������: " << endl;
    if (Check()) { cout << "����������" << endl; }
    else { cout << "������������" << endl; }
    cout << "���������� ������: " << sides_count << endl;
    cout << "C������: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "����: A=" << A << " B=" << B << " C=" << C << endl;
}
bool RAtriangle::Check()
{

    if (C == 90 && Triangle::Check() == true) { return true; }
    else { return false; }
}