#include "Itriangle.h" 
#include <iostream>

using namespace std;


void Itriangle::print_info() 
{

    cout << "�������������� �����������: " << endl;
    if (Check()) { cout << "����������" << endl; }
    else { cout << "������������" << endl; }
    cout << "���������� ������: " << sides_count << endl;
    cout << "C������: a=" << a << " b=" << b << " c=" << c << endl;
    cout << "����: A=" << A << " B=" << B << " C=" << C << endl;
}
bool Itriangle::Check() 
{
    if (a == c && A == C && Triangle::Check() == true) { return true; }
    else { return false; }
}