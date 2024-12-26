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
	int indexAlf;

	int symbol_citi()
	{
		
		return static_cast<int>(this->city[0]);
	}

public:

	adress(string city, string street, int nubmerHome, int nubmerKwartir)
	{
		this->city = city;
		this->street = street;
		this->nubmerHome = nubmerHome;
		this->nubmerKwartir = nubmerKwartir;
	};

	adress() {}

	string get_output_address()
	{
		string return_;
		return_ = city + ", " + street + ", " + to_string(nubmerHome) + ", " + to_string(nubmerKwartir);
		
		return return_;
	}
	 void sort(adress* addresses, int size)
	{

		
			for (int i = 0; i < size; i++)
				for (int j = i; j < size - 1; j++)
				{
					if (addresses[j].symbol_citi() > addresses[j + 1].symbol_citi())
					{
						swap(addresses[j], addresses[j + 1]);
					}
				}
		
		
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
	system("chcp 1251"); 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 

	string city{}, street{};
	int nubmerHome{}, nubmerKwartir{};

	adress* adress_ptr = new adress[temp];
	for (int i = 0; i < temp; i++)
	{
		inFile >> city;
		inFile >> street;
		inFile >> nubmerHome;
		inFile >> nubmerKwartir;
		adress_ptr[i] = adress(city, street, nubmerHome, nubmerKwartir);

	}
 
	adress_ptr->sort(adress_ptr, temp); 

	

	for(int i =0;i<temp;i++)
	{
		outFile << adress_ptr[i].get_output_address(); 
		outFile << endl; 
	}


	outFile.close();
	inFile.close();
	delete[] adress_ptr;
}