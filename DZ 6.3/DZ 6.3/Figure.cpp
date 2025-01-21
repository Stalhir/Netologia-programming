#include "Figure.h"
#include <iostream>

using namespace std;

int Figure::get_sides_count()
{
    return sides_count;
}

void Figure::print_info()
{
    cout << "Фигура" << endl;
    if (Check()) { cout << "Правильная" << endl; }
    else { cout << "Неправильная" << endl; }
    cout << "Количество сторон: " << sides_count << endl;
}

bool Figure::Check()
{
    if (sides_count == 0) { return true; }
    else { return false; }
};

