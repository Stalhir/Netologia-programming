#include "Triangle.h"
#pragma once

class Etriangle : public Triangle
{
public:
    Etriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
    };
    
    void print_info() override;
    
    bool Check() override;
    
};