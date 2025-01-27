#pragma once
#include <iostream>
#include <stdexcept>

class EincorrectData : public std::domain_error 
{
private:
	
public:
	
	explicit EincorrectData(const std::string& message) : std::domain_error(message)
	{
		
		
	}  

	
};