#pragma once

class Counter
{
private:
	int count{ 1 };
public:
	int getcount() const;
    void setcount(int count);
	
	void AddCount();  
	void MinusCount();

	Counter(int count = 1)
	{
		this->count = count;
	};
};