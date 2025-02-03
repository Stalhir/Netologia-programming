#include "Quadrangle.h"
#pragma once

class Rectangle : public Quadrangle
{
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D, true)
    {

            if (Rectangle::Check() == false) throw EincorrectData("Ошибка создания прямоугольника. Причина:  стороны a,c и b,d попарно не равны, все углы не равны 90");
            std::cout << "Прямоугольник (стороны: " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << " " << B << " " << C << D << ", " << ") создан" << std::endl;
        

    };

        void print_info() override;

        bool Check() override;
    
};