#include "Triangle.h"
#pragma once

class Etriangle : public Triangle
{
public:
    Etriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C,true)
    {

            if (Etriangle::Check() == false) throw EincorrectData("������ �������� ��������������� ������������. �������: ��� ������� �� �����, ��� ���� �� ����� 60");
            std::cout << "�������������� ����������� (�������: " << a << ", " << b << ", " << c << "; ���� " << A << " " << B << " " << C << ") ������" << std::endl;

        
    };
    
    void print_info() override;
    
    bool Check() override;
    
};