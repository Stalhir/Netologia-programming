#include "Figure.h"
#pragma once

class Triangle : public Figure
{
protected:
    int a, b, c;

    int A, B, C;

public:

    Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
    {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;
    };
 
    
    void print_info() override;

    bool Check() override;
    
};