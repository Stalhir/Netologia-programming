#include "Quadrangle.h"
#pragma once

class Rhomb : public Quadrangle
{
public:
    Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D, true)
    {
        try
        {
            if (Check() == false) throw EincorrectData("Ошибка создания Ромб. Причина: все стороны не равны, углы A,C и B,D попарно не равны");
            std::cout << "Ромб (стороны: " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << " " << B << " " << C << D << ", " << ") создан" << std::endl;
        }
        catch (const EincorrectData& e) {
            std::cout << e.what() << std::endl;

        }
    };
   
    void print_info() override;
    
    bool Check() override;
    
};
