#include "Quadrangle.h"
#pragma once

class Rhomb : public Quadrangle
{
public:
    Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D, true)
    {

            if (Rhomb::Check() == false) throw EincorrectData("������ �������� ����. �������: ��� ������� �� �����, ���� A,C � B,D ������� �� �����");
            std::cout << "���� (�������: " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << " " << B << " " << C << D << ", " << ") ������" << std::endl;

    };
   
    void print_info() override;
    
    bool Check() override;
    
};
