#include <iostream>
#include <Windows.h>
using namespace std;

struct BankAccount
{
	string name; 
	int balanceNumber;  
	float balance;

};

void setBalance(BankAccount* b)
{
	cout << "Введите новый баланс: ";
	cin >> b->balance;
}

int main()
{
	SetConsoleCP(1251);
	 

	setlocale(LC_ALL, "rus");
	BankAccount b;
	cout << "Введите номер счёта: ";
	cin >> b.balanceNumber; 
	cout << "Введите имя владельца: ";
	cin >> b.name;
	cout << "Введите баланс: ";
	cin >> b.balance;
	setBalance(&b);
	cout << "Ваш счёт: " << b.name << ", " << b.balanceNumber << ", " << b.balance;
}

