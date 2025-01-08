#include <iostream>

using namespace std;

class Figure
{
protected: 
    int sides_count{0};
    Figure(int sides_count) { this->sides_count = sides_count; };
public:
    int get_sides_count()
    {
        return sides_count; 
    }
    virtual string get_name()
    {
        return "Фигура";
    }
    Figure() { sides_count = 0; }

};
class Triangle : public Figure
{
public:
    string get_name() override
    {
        return "Треугольник";
    }
    Triangle() : Figure(3) 
    {

    };
};
class Quadrangle : public Figure
{
public:
    string get_name() override
    {
        return "Четырёхугольник";
    }
    Quadrangle() : Figure(4) 
    {

    };
    
};

int main()
{
    setlocale(LC_ALL, "rus");
    Figure fig; 
    Triangle trio;
    Quadrangle quad;
    
    cout << "Количество сторон: " << endl;
    cout << fig.get_name() << ": " << fig.get_sides_count() << endl;
    cout << trio.get_name() << ": " << trio.get_sides_count() << endl; 
    cout << quad.get_name() << ": " << quad.get_sides_count() << endl; 
  
} 

