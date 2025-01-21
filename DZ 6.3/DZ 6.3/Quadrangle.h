#include "Figure.h"
#pragma once

class Quadrangle : public Figure
{
protected:
    int a, b, c, d;

    int A, B, C, D;
public:

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
    {
        this->a = a; this->b = b; this->c = c; this->d = d;
        this->A = A; this->B = B; this->C = C; this->D = D;

    };
    
 
    void print_info() override;
   
    bool Check() override;
   
};