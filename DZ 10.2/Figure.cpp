#include "Figure.h"
#include <iostream>

using namespace std;

int Figure::get_sides_count()
{
    return sides_count;
}

void Figure::print_info()
{
    cout << "������" << endl;
    if (Check()) { cout << "����������" << endl; }
    else { cout << "������������" << endl; }
    cout << "���������� ������: " << sides_count << endl;
}

bool Figure::Check()
{
    if (sides_count == 0) { return true; }
    else { return false; }
};

