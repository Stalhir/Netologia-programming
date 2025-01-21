#include "Quadrangle.h"
#pragma once

class Square : public Quadrangle
{
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {

    };
    void print_info() override;
    
    bool Check() override;
   
};