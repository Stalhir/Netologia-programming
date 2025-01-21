#include <iostream>
#include "Counter.h" 
#include <Windows.h>
#pragma once
using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int count{};
	
	cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	string YorN;
	cin >> YorN;
	
	if(YorN == "да")
	{
		cout << "Введите начальное значение счётчика: ";
		cin >> count;
		
	}
	else {}

	Counter counter;
	
	
	while(true)
	{
		cout << "Введите команду ('+', '-', '=' или 'x'): ";
		cin >> YorN;
		
		if (YorN == "+") { counter.AddCount(); }
		else if (YorN == "-") { counter.MinusCount(); }
		else if (YorN == "=") { cout << counter.getcount() << endl; }
		else if (YorN == "x") { cout << "До свидания!" << endl; return 0; }
		else { cout << "неизвестная команда" << endl; }
			
	}
	



}

