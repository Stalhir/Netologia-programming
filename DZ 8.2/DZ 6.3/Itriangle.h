#include "Triangle.h"
#pragma once

class Itriangle : public Triangle
{
public:
    Itriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C,true) 
    {

            if (Itriangle::Check() == false) throw EincorrectData("������ �������� �������������� ������������. �������: (������� a � c �� �����, ���� A � C �� �����");
            std::cout << "����������� (�������: " << a << ", " << b << ", " << c << "; ���� " << A << " " << B << " " << C << ") ������" << std::endl;

       
    };
   
    void print_info() override;
  
    bool Check() override;
   
};
