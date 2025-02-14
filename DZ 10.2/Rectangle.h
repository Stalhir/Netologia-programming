#include "Quadrangle.h"
#pragma once

class Rectangle : public Quadrangle
{
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) {}
        else { blocked = true; }
    };

        void print_info() override;

        bool Check() override;
    
};