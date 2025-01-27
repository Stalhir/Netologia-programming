#include "Quadrangle.h"
#pragma once

class Square : public Quadrangle
{
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D,true)
    {

        try
        {
            if (Check() == false) throw EincorrectData("������ �������� ��������. �������: ��� ������� �� �����, ��� ���� �� ����� 90");
            std::cout << "������� (�������: " << a << ", " << b << ", " << c << ", " << d << "; ���� " << A << " " << B << " " << C << D << ", " << ") ������" << std::endl;
        }
        catch (const EincorrectData& e) {
            std::cout << e.what() << std::endl;

        }
    };
    void print_info() override;
    
    bool Check() override;
   
};