#include "Counter.h" 
#pragma once
int Counter::getcount() const
{
	return count;
}
void Counter::setcount(int count)
{
	this->count = count;
};

void Counter::AddCount() { ++count; };
void Counter::MinusCount() { --count; };