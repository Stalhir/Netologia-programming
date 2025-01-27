#include "Quadrangle.h"
#pragma once

class Square : public Quadrangle
{
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D,true)
    {

        try
        {
            if (Check() == false) throw EincorrectData("Ошибка создания Квадрата. Причина: все стороны не равны, все углы не равны 90");
            std::cout << "Квадрат (стороны: " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << " " << B << " " << C << D << ", " << ") создан" << std::endl;
        }
        catch (const EincorrectData& e) {
            std::cout << e.what() << std::endl;

        }
    };
    void print_info() override;
    
    bool Check() override;
   
};