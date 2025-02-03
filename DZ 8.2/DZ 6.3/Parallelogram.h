#include "Quadrangle.h"
#pragma once

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D, true)
    {

            if (Parallelogram::Check() == false) throw EincorrectData("Ошибка создания четырёхугольника. Причина:  стороны a,c и b,d попарно не равны, углы A,C и B,D попарно не равны");
            std::cout << " Параллелограм (стороны: " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << " " << B << " " << C << D << ", " << ") создан" << std::endl;
        


    };
    void print_info() override;
    
    bool Check() override;
    
};
