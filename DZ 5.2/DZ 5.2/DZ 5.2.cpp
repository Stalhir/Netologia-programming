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
        if (blocked == true) { return; }
        cout << sides_count << endl;
    }
    Figure() { sides_count = 0; }

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
        if (blocked == true) { return; }
        cout << "Треугольник: " << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }
};


class RAtriangle : public Triangle
{
public:
    RAtriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        if(C == 90){}
        else { blocked = true; }
    };
    void print_info() override
    {
        if (blocked == true) { return; }
        cout << "Прямоугольный треугольник: " << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }
 
};

class Itriangle : public Triangle
{
public:
    Itriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        if (a == c && A == C) {}
        else {   blocked = true;}
    };
    void print_info() override
    {
        if (blocked == true) { return; }
        cout << "Равнобедренный треугольник: " << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }
};

class Etriangle : public Triangle 
{
public:
    Etriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
    {
        if (a == b && c == b && a == c && A == 60 && B == 60 && C == 60) {}
        else {  blocked = true;}
    };
    void print_info() override
    {
        if (blocked == true) { return; }
        cout << "Равносторонний треугольник: " << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
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
        if (blocked == true) { return; }
        cout << "Четырёхугольник: " << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d="<<d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D<< endl;
    }
};

class Rectangle : public Quadrangle
{
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        if(a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90){}
        else {  blocked = true;}
    };
    void print_info() override
    {
        if (blocked == true) { return; }
        cout << "Прямоугольник: " << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

class Square : public Quadrangle
{
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        if (a == c && a == b && a == d && b == d && c == d && A == 90 && B == 90 && C == 90 && D == 90) {} 
        else {  blocked = true;}
    };
    void print_info() override
    {
        if (blocked == true) { return; }
        cout << "Квадрат: " << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

class Parallelogram  : public Quadrangle
{
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        if (a == c && b == d && A == C && B == D) {}
        else {  blocked = true; }
    };
    void print_info() override
    {
        if (blocked == true) { return; }
        cout << "Параллелограмм: " << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

class Rhomb : public Quadrangle
{
public:
    Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        if (a == c&& a== b && a == d && b == d && c == d && A == C && B == D) {} 
        else { blocked = true;}
    
    };
    void print_info() override
    {
        if (blocked == true) { return; }
        
        cout << "Ромб: " << endl;
        cout << "Cтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
}; 

int main()
{
    setlocale(LC_ALL, "rus");
     
    Triangle T(10, 20, 30, 50, 60, 70); 
    RAtriangle RAT(10,20,30,50,60,90); 
    Itriangle  IT(10,20,10,50,60,50);  
    Etriangle ET(300,30,30,60,60,60); 
  
    Quadrangle Q(10, 20, 30, 40, 50, 60, 70, 80); 
    Rectangle R(10, 20, 10, 20, 90, 90, 90, 90); 
    Square S(20, 20, 20, 20, 90, 90, 90, 90); 
    Parallelogram P(20, 30, 20, 30, 30, 40, 30, 40); 
    Rhomb Rh(30, 30, 30, 30, 30, 40, 30, 40); 

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