#include "Triangle.h"
#pragma once

class Etriangle : public Triangle
{
public:
    Etriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C,true)
    {

            if (Etriangle::Check() == false) throw EincorrectData("Ошибка создания равностороннего треугольника. Причина: все стороны не равны, все углы не равны 60");
            std::cout << "Равносторонний треугольник (стороны: " << a << ", " << b << ", " << c << "; углы " << A << " " << B << " " << C << ") создан" << std::endl;

        
    };
    
    void print_info() override;
    
    bool Check() override;
    
};