#include "Quadrangle.h"
#pragma once

class Rectangle : public Quadrangle
{
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D, true)
    {

            if (Rectangle::Check() == false) throw EincorrectData("������ �������� ��������������. �������:  ������� a,c � b,d ������� �� �����, ��� ���� �� ����� 90");
            std::cout << "������������� (�������: " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << " " << B << " " << C << D << ", " << ") ������" << std::endl;
        

    };

        void print_info() override;

        bool Check() override;
    
};