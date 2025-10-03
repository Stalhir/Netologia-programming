#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <exception>
#include <iostream>
#include <mutex>
#include <chrono>
#include <vector>
#include <string>

struct Client
{
	int socket;
	sockaddr_in clientAddr;
	std::thread clientThread;
	char* buffer = new char[256];
	

	Client(SOCKET sockfd, sockaddr_in addr) : socket(sockfd) 
	{
		clientAddr = addr;
		 
		clientThread = std::thread([this]() { 
			this->HandleClient(); 
		}); 
		std::cout << "Client create" << std::endl;
		
	}

	void HandleClient() 
	{
		while (true)
		{
			std::string message = Recv(socket);
			std::cout << message << std::endl;

			Send(socket, message += " Hello");
		}

		closesocket(socket); 
	}

	void Send(SOCKET socket, std::string send_message)
	{
		send(socket, send_message.c_str(), 256, 0);
	}

	std::string Recv(SOCKET socket)
	{
		memset(buffer, 0, sizeof(buffer));
		recv(socket, buffer, 256, 0);
		return std::string(buffer);
	}


	Client(Client&& other) noexcept 
		: socket(other.socket) 
		, clientAddr(other.clientAddr)
		, clientThread(std::move(other.clientThread))  
		, buffer(other.buffer) 
	{
		other.socket = INVALID_SOCKET;
		other.buffer = nullptr;  
	}

	~Client()
	{
		clientThread.join();
		closesocket(socket);
		delete[] buffer;
	}
};

class TCPServer
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 2);
	std::mutex m;
	std::vector<Client> Clients; 
	sockaddr_in serverService;


public:
	TCPServer()
	{
		if (WSAStartup(DLLVersion, &wsaData) != 0)
		{
			throw std::runtime_error("The winsock dll not found");
		}

		int enterSocket = socket(AF_INET, SOCK_STREAM, 0);
		
		if(enterSocket == INVALID_SOCKET)
		{
			throw std::runtime_error("Socket creation failed");
			WSACleanup();
		}
		
		serverService.sin_family = AF_INET;
		serverService.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		serverService.sin_port = htons(54542);
		if (bind(enterSocket, (SOCKADDR*)&serverService, sizeof(serverService)) == SOCKET_ERROR) {
			throw std::runtime_error("Bind failed");
			closesocket(enterSocket);
			WSACleanup();
		}
		
		if(listen(enterSocket, 5) == SOCKET_ERROR)
		{
			throw std::runtime_error("listen failed");
			closesocket(enterSocket);
			WSACleanup();
		}


		StartServer(enterSocket);
	}

	void StartServer(SOCKET socket)
	{
		while (true) 
		{
			sockaddr_in clientAddr;
			int clientAddrSize = sizeof(clientAddr);
			int new_socket = accept(socket, (SOCKADDR*)&clientAddr, &clientAddrSize); 
			if (new_socket == INVALID_SOCKET) 
			{
				std::cout << "accept failed" << std::endl;
			}
			else
			{
				m.lock();
				Clients.emplace_back(new_socket, clientAddr); // тут ошибка поток нельзя копирываТь ХОТЯ НЕТУ ТУТ ПОТОКАА 
				m.unlock();
			}
		}
		closesocket(socket);
	}



	~TCPServer()
	{

	
		WSACleanup();
	}
			
};
	

