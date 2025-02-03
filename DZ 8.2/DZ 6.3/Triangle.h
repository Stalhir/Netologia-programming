#include "Figure.h"
#pragma once

class Triangle : public Figure
{
private:
    void initial() {} //незя так
    
protected:
    int a, b, c;

    int A, B, C;
    
    Triangle(int a, int b, int c, int A, int B, int C,bool THIS_CONSTRUCTOR_FOR_Inheritance) : Figure(3,true)
    {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;
    }

public:

    ~Triangle() {};

    Triangle(int a, int b, int c, int A, int B, int C) : Figure(3, true)
    {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;

            if (Triangle::Check() == false) throw EincorrectData("Ошибка создания треугольника. Причина: сумма углов не равна 180");
            std::cout << "Треугольник (стороны: " << a << ", " << b << ", " << c << "; углы " << A << " " << B << " " << C << ") создан" << std::endl;


          
    
    };
 
    
    void print_info() override;

    bool Check() override;
    
};