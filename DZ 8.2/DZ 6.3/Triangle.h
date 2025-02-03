#include "Figure.h"
#pragma once

class Triangle : public Figure
{
private:
    void initial() {} //���� ���
    
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

            if (Triangle::Check() == false) throw EincorrectData("������ �������� ������������. �������: ����� ����� �� ����� 180");
            std::cout << "����������� (�������: " << a << ", " << b << ", " << c << "; ���� " << A << " " << B << " " << C << ") ������" << std::endl;


          
    
    };
 
    
    void print_info() override;

    bool Check() override;
    
};