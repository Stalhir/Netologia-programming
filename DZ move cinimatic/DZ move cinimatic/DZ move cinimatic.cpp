﻿#include <iostream>
#include <vector>

template <typename T>
void move_vectors(std::vector<T>& rv, std::vector<T>& lv)
{
    lv = std::move(rv); 
}

int main()
{
    
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    move_vectors(one, two);   
}
