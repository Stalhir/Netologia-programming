#include "Quadrangle.h"
#pragma once

class Rhomb : public Quadrangle
{
public:
    Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D, true)
    {
        try
        {
            if (Check() == false) throw EincorrectData("������ �������� ����. �������: ��� ������� �� �����, ���� A,C � B,D ������� �� �����");
            std::cout << "���� (�������: " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << " " << B << " " << C << D << ", " << ") ������" << std::endl;
        }
        catch (const EincorrectData& e) {
            std::cout << e.what() << std::endl;

        }
    };
   
    void print_info() override;
    
    bool Check() override;
    
};
