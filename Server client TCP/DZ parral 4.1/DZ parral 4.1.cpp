#include <iostream>
#include <exception>
#include "TCPServer.h"
using namespace std;

int main()
{
	try
	{
		TCPServer server;



	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what();
	}
	system("pause");
}
