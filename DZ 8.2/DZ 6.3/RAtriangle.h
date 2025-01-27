#include "Triangle.h"
#pragma once

class RAtriangle : public Triangle
{
public:
    RAtriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C,true) 
    {
        try
        {
            if (Check() == false) throw EincorrectData("Ошибка создания прямоугольного треугольника. Причина: угол C всегда не равен 90");
            std::cout << "Прямоугольный треугольник (стороны: " << a << ", " << b << ", " << c << "; углы " << A << " " << B << " " << C << ") создан" << std::endl;

        }
        catch (const EincorrectData& e) {
            std::cout << e.what() << std::endl;
           
        }
       
        
    } 
    
    void print_info() override;
 
    bool Check() override;
  
};