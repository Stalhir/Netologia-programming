#include <iostream>
#include <chrono>
#include <thread>
#include "TCPClient.h"


int main()
{
   try
   {
	   TCPClient F_Client;
	   F_Client.Send("HELLO");
	   while(true)
	   {
		   std::cout << F_Client.Read() << std::endl;
	   }

   }
   catch(std::runtime_error &e)
   {
	   std::cout << e.what();
   }
   system("pause");
}
