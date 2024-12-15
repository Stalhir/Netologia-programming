#include <iostream>

using namespace std;

class Calculator
{ 
public:
	double num1;
	double num2;
	double add() { return num1 + num2; };
	double multiply() { return num1 * num2; };
	double subtract_1_2() { return num1 - num2; };
	double subtract_2_1() { return num2 - num1; };
	double divide_1_2() { return num1 / num2; };
	double divide_2_1() { return num2 / num1; };
	bool set_num1(double num1) 
	{
		if (num1 != 0)
		{
			this->num1 = num1;
			return true;
		}
		else
		{
			cout << "Неверное ввод" << endl;
			return false;
		}
	};
	bool set_num2(double num2) 
	{
		if (num2 != 0)
		{
			this->num2 = num2;
			return true;
		}
		else
		{
			cout << "Неверное ввод" << endl;
			return false;
		}
	};
};

int main()
{
	setlocale(LC_ALL, "rus");

	double a{}, b{};

	Calculator A;
	
	while(true)
	{
		cout << "Введите num1: ";
		cin >> a;
		cout << "Введите num2: ";
		cin >> b;
		A.set_num1(a);
		A.set_num2(b); 
		cout << "num1 + num2 = " << A.add() << endl;
		cout << "num1 - num2 = " << A.subtract_1_2() << endl;
		cout << "num2 - num1 = " << A.subtract_2_1() << endl;
		cout << "num1 * num2 = " << A.multiply() << endl; 
		cout << "num1 / num2 = " << A.divide_1_2() << endl;
		cout << "num2 / num1 = " << A.divide_2_1() << endl;
	}

}
