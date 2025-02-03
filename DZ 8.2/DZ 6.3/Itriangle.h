#include "Triangle.h"
#pragma once

class Itriangle : public Triangle
{
public:
    Itriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C,true) 
    {

            if (Itriangle::Check() == false) throw EincorrectData("Ошибка создания равнобедреного треугольника. Причина: (стороны a и c не равны, углы A и C не равны");
            std::cout << "Треугольник (стороны: " << a << ", " << b << ", " << c << "; углы " << A << " " << B << " " << C << ") создан" << std::endl;

       
    };
   
    void print_info() override;
  
    bool Check() override;
   
};
