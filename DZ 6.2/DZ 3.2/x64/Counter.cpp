#include "Counter.h" 
#pragma once
int Counter::getcount() const
{
	return this->count; 
}
void Counter::setcount(int count)
{
	this->count = count;
};

void Counter::AddCount() { ++this->count; }; 
void Counter::MinusCount() {--this->count; }; 