#include <iostream>

using namespace std;



class Figure
{
protected:
    int sides_count{ 0 };
    Figure(int sides_count) { this->sides_count = sides_count; };
    bool blocked = false;

    //если обьект не подходит по параметру то функция с обьектом не будет работать
public:
    int get_sides_count()
    {
        return sides_count;
    }

    virtual void print_info()
    {
        cout << "Фигура" << endl; 
        if (Check()) { cout << "Правильная" << endl; }else{ cout << "Неправильная" << endl; } 
        cout << "Количество сторон: " << sides_count << endl;
    }
    Figure() { sides_count = 0; }

    virtual bool Check() 
    {
        if (sides_count == 0) { return true; } 
        else { return false; }
    };
};


class Triangle : public Figure
{
protected:
    int a, b, c;

    int A, B, C;

public:

    Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
    {
        this->a = a; this->b = b; this->c = c;
        this->A = A; this->B = B; this->C = C;
    };
    void print_info() override
    {
     

        cout << "Треугольник: " << endl;
        if (Check()) { cout << "Правильная" << endl; } 
        else { cout << "Неправильная" << endl; } 
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }
    bool Check() override
    {
    
    if((A+B+C) == 180){ return true; } 
    else { return false; }
    }
 };


class RAtriangle : public Triangle
{
public:
    RAtriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {

    };
    void print_info() override
    {
       
        
        cout << "Прямоугольный треугольник: " << endl;
        if (Check()) { cout << "Правильная" << endl; } 
        else { cout << "Неправильная" << endl; } 
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }
    bool Check() override
    {
      
        if (C == 90 && Triangle::Check() == true){ return true; }
        else { return false; }
    }
};

class Itriangle : public Triangle
{
public:
    Itriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
    };
    void print_info() override
    {
        
        cout << "Равнобедренный треугольник: " << endl;
        if (Check()) { cout << "Правильная" << endl; }
        else { cout << "Неправильная" << endl; }
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }
    bool Check() override
    {
        if (a == c && A == C && Triangle::Check() == true) { return true;  }
        else { return false; }
    }
};

class Etriangle : public Triangle
{
public:
    Etriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        if (a == b && c == b && a == c && A == 60 && B == 60 && C == 60) {}
        else { blocked = true; }
    };
    void print_info() override
    {
       
        cout << "Равносторонний треугольник: " << endl;
        if (Check()) { cout << "Правильная" << endl; }
        else { cout << "Неправильная" << endl; }
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }
    bool Check() override
    {
        if (a == b && c == b && a == c && A == 60 && B == 60 && C == 60 && Triangle::Check() == true) { return true; } 
        else { return false; }
    }
};


class Quadrangle : public Figure
{
protected:
    int a, b, c, d;

    int A, B, C, D;
public:

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
    {
        this->a = a; this->b = b; this->c = c; this->d = d;
        this->A = A; this->B = B; this->C = C; this->D = D;

    };
    void print_info() override
    {
        cout << "Четырёхугольник: " << endl;
        if (Check()) { cout << "Правильная" << endl; }
        else { cout << "Неправильная" << endl; }
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
    bool Check() override
    {
        if ((A+B+C+D)==360) { return true; }
        else { return false; }
    }
};

class Rectangle : public Quadrangle
{
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) {}
        else { blocked = true; }
    };
    void print_info() override
    {
       
        cout << "Прямоугольник: " << endl;
        if (Check()) { cout << "Правильная" << endl; } 
        else { cout << "Неправильная" << endl; } 
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
    bool Check() override
    {
        if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90 && Quadrangle::Check() == true) { return true; }
        else { return false; }
    }
};

class Square : public Quadrangle
{
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        
    };
    void print_info() override
    {
       
        cout << "Квадрат: " << endl;
        if (Check()) { cout << "Правильная" << endl; } 
        else { cout << "Неправильная" << endl; } 
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
    bool Check() override 
    {
        if (a == c && a == b && a == d && b == d && c == d && A == 90 && B == 90 && C == 90 && D == 90 && Quadrangle::Check() == true) { return true; } 
        else { return false; }
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
     
       
    };
    void print_info() override
    {
      
        cout << "Параллелограмм: " << endl;
        if (Check()) { cout << "Правильная" << endl; } 
        else { cout << "Неправильная" << endl; } 
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
    bool Check() override 
    {
        if (a == c && b == d && A == C && B == D  && Quadrangle::Check() == true) { return true; } 
        else { return false; }
    }
};

class Rhomb : public Quadrangle
{
public:
    Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {

    };
    void print_info() override
    {
        if (blocked == true) { return; }

        cout << "Ромб: " << endl;
        if (Check()) { cout << "Правильная" << endl; } 
        else { cout << "Неправильная" << endl; } 
        cout << "Количество сторон: " << sides_count << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
    bool Check() override
    {
        if (a == c && a == b && a == d && b == d && c == d && A == C && B == D && Quadrangle::Check() == true) { return true; }
        else { return false; }
    } 
};

int main()
{
    setlocale(LC_ALL, "rus");

    Figure F;
    Triangle T(10, 20, 30, 50, 60, 70);
    RAtriangle RAT(10, 20, 30, 50, 60, 90);
    Itriangle  IT(10, 20, 10, 50, 60, 50);
    Etriangle ET(30, 30, 30, 60, 60, 60);

    Quadrangle Q(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle R(10, 20, 10, 20, 90, 90, 90, 90);
    Square S(20, 20, 20, 20, 90, 90, 90, 90);
    Parallelogram P(20, 30, 20, 30, 30, 40, 30, 40);
    Rhomb Rh(30, 30, 30, 30, 30, 40, 30, 40);

    F.print_info(); 
    cout << endl;
    T.print_info();
    cout << endl;
    RAT.print_info();
    cout << endl;
    IT.print_info();
    cout << endl;
    ET.print_info();
    cout << endl;



    Q.print_info();
    cout << endl;
    R.print_info();
    cout << endl;
    S.print_info();
    cout << endl;
    Rh.print_info();
    cout << endl;

}