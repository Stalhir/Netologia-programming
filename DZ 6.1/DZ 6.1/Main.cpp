#include <iostream>
#include "Calculator.h"
#pragma once

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	int a{}, b{};
	cout << "������� ������ �����: ";
	cin >> a;
	cout << "������� ������ �����: ";
	cin >> b;
	int operation{};
	cout << "�������� �������� (1 - ��������, 2 ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
	cin >> operation;
	if (operation == 1) { cout << a << " ���� " << b << " = " << add(a, b); }
	else if(operation == 2){ cout << a << " ����� " << b << " = " << sub(a, b); }
	else if (operation == 3) { cout << a << " �������� �� " << b << " = " << mult(a, b); }
	else if (operation == 4) { cout << a << " �������� �� " << b << " = " << divis(a, b); }
	else if (operation == 5) { cout << a << " � ������� " << b << " = " << degree(a, b); }
}