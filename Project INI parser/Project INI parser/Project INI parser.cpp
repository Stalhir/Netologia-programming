#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

bool boolFind(string::iterator begin, string::iterator end, char sym)
{
	if(find(begin, end, sym) == end)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void DeleteAllSym(string& Str , string::iterator begin, string::iterator end, char sym)
{
	if (begin >= end || begin < Str.begin() || end > Str.end())
		return;

	auto new_end = remove(begin, end, sym);
	Str.erase(new_end, end);
}



struct Section
{
	string name;
	map<string, string> var;
	
	Section(string name) : name(name) {}
};

class ini_parser
{
private:
	vector<Section> Sections;

	fstream file;
public:

ini_parser(string fileadress) : file(fileadress)
{
	if (!file.is_open())
	{
		throw "the file did not open";
	}
	else
	{
		readFile();
	}
}

bool AddSection(string& Str)
{
	auto itBegin = find(Str.begin(), Str.end(), '[');
	auto itEnd = find(Str.begin(), Str.end(), ']');

	if (itBegin == Str.end() || itEnd == Str.end())
	{ return false; }
	else if (itBegin >= itEnd)
	{ return false; }
	else
	{
		Sections.push_back(Section(string(itBegin + 1, itEnd)));
		return true;
	}
};

bool AddVar(string& Str, int IndexSection)
{
	if (!boolFind(Str.begin(), Str.end(), '='))
	{ return false; }
	else if ((Str.front() == '=' || Str.back() == '='))
	{ return false; }
	else 
	{
		DeleteAllSym(Str, Str.begin(), find(Str.begin(), Str.end(), '='), ' ');
		auto itEqSign = find(Str.begin(), Str.end(), '=');

		if (Str.front() != '=')
		{
			string valName, valData;
			valName = string(Str.begin(), itEqSign);
			valData = string(++itEqSign, Str.end());
			cout << valName << endl;
			cout << valData << endl;
			Sections[IndexSection].var.insert(std::pair<string, string>(valName, valData));
		}
		else { return false; }

		return true;
	}
};

void readFile() 
{
	
	string input;
	int IndSect = Sections.size()-1;
	int i = 0;

	while (getline(file, input))
	{
		
		auto it = std::find(input.begin(), input.end(), ';');
		if (it == input.begin()) { continue; }
		input.erase(it, input.end());
		
		
		if(AddSection(input))
		{
			IndSect++;	
		}
		else if(AddVar(input, IndSect))
		{
			
		}
		else { continue; }
		

		
	}

	

	
}

template<typename T>
T getvalue(string SectionName, string ValueName)
{
	bool IsFind{ false };
	std::map<string, string>::iterator findIt;
	for(int i = 0; i < Sections.size(); i++)
	{
		if(Sections[i].name == SectionName)
		{
			if(Sections[i].var.find(ValueName) != Sections[i].var.end())
			{
				findIt = Sections[i].var.find(ValueName);
				IsFind = true;
			}
			else{ throw "No varaible with that name was found"; }
		}
	}

	
	if(IsFind == true)
	{
		return findIt->second;
	}
	else { throw "No section with that name was found"; }
}

};


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, "Russian");
	
	try
	{
		ini_parser parser("C:/Games/fille.ini");
		cout << "\n test: " << parser.getvalue<string>("Section1", "var1"); 
		


	}
	catch (const char* error_message)
	{
		std::cout << error_message << std::endl;
		return 1;
	}
	return 0;
}
