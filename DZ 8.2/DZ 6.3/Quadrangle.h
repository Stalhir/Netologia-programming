#include "Figure.h"
#pragma once

class Quadrangle : public Figure
{
private:
    
protected:
    int a, b, c, d;

    int A, B, C, D;
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, bool THIS_CONSTRUCTOR_FOR_Inheritance) : Figure(4,true)
    {
        this->a = a; this->b = b; this->c = c; this->d = d;
        this->A = A; this->B = B; this->C = C; this->D = D;


    };
public:
    int CheckFigure() {} 
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4,true)
    {
        this->a = a; this->b = b; this->c = c; this->d = d;
        this->A = A; this->B = B; this->C = C; this->D = D;

            if (Quadrangle::Check() == false) throw EincorrectData("������ �������� ���������������. �������:  ����� ����� �� ����� 360");
            std::cout << "�������������� (�������: " << a << ", " << b << ", " << c <<", " << d << "; ���� " << A << " " << B << " " << C << D << ", " << ") ������" << std::endl;
           
        


    };

    
 
    void print_info() override;
   
    bool Check() override;
   
};