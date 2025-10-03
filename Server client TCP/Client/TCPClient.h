#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <ws2tcpip.h>
#include <exception>
#include <iostream>
#include <string>


class TCPClient
{
private:
	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 2);
	int sockfd = 0;
	sockaddr_in clientService;
	char* buffer = new char[256];
public:	

	TCPClient()
	{
		
		if(WSAStartup(DLLVersion, &wsaData) != 0)
		{
			throw std::runtime_error("The winsock dll not found");
		}
	
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd == INVALID_SOCKET)
		{
			throw std::runtime_error("Socket creation failed");
			WSACleanup();
		}
		
		
		clientService.sin_family = AF_INET;
		clientService.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		clientService.sin_port = htons(54542);
		int conn = connect(sockfd, (SOCKADDR*)&clientService, sizeof(clientService));
		if(conn == -1)
		{
			throw std::runtime_error("Invalid connect");
		}
	}

	void Send(std::string send_message)
	{
		int errCheck = send(sockfd, send_message.c_str(), 256, 0 );
	}

	
	std::string Read()
	{
		memset(buffer, 0, sizeof(buffer));
		int errCheck = recv(sockfd, buffer, 256, 0);
		return std::string(buffer);
	}

	~TCPClient()
	{
		closesocket(sockfd);
		WSACleanup();
	}

};