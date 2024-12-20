#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

class adress
{
private:
	string city;
	string street;
	int nubmerHome;
	int nubmerKwartir;

public:
	
	adress(string city, string street, int nubmerHome, int nubmerKwartir) 
	{
		this->city = city;
		this->street = street;
		this->nubmerHome = nubmerHome;
		this->nubmerKwartir = nubmerKwartir;
	};
	
	adress(){}

	string get_output_address()
	{
		string return_; 
		return_ = city + ", " + street + ", " + to_string(nubmerHome) + ", " + to_string(nubmerKwartir); 
		  
		return return_;  
	}

};

int main()
{
	setlocale(LC_ALL, "rus");
	std::ofstream outFile("C:\\out.txt");  
	std::ifstream inFile("C:\\in.txt");   
	
	int temp{};
	inFile >> temp;
	outFile << temp << endl;

	string city{}, street{};
	int nubmerHome{}, nubmerKwartir{};

	adress* adress_ptr = new adress[temp]; 
	for(int i = 0; i<temp; i++)
	{
		inFile >> city;
		inFile >> street;
		inFile >> nubmerHome;
		inFile >> nubmerKwartir;
		adress_ptr[i] = adress(city,street,nubmerHome,nubmerKwartir);

	}
	for (int i = 0; i < temp; i++)
	{
		outFile << adress_ptr[temp - i - 1].get_output_address(); 
		outFile << endl;
	}
	delete[] adress_ptr;
}
