#include <iostream>
#include "Calculator.h"
#pragma once

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	int a{}, b{};
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;
	int operation{};
	cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	cin >> operation;
	if (operation == 1) { cout << a << " плюс " << b << " = " << add(a, b); }
	else if(operation == 2){ cout << a << " минус " << b << " = " << sub(a, b); }
	else if (operation == 3) { cout << a << " умножить на " << b << " = " << mult(a, b); }
	else if (operation == 4) { cout << a << " поделить на " << b << " = " << divis(a, b); }
	else if (operation == 5) { cout << a << " в степени " << b << " = " << degree(a, b); }
}