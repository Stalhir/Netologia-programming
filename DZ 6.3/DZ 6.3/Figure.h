#pragma once

class Figure
{
protected:
    int sides_count{ 0 };
    Figure(int sides_count) { this->sides_count = sides_count; };
    bool blocked = false;

public:
    int get_sides_count();
    

    virtual void print_info();
   
    Figure() { sides_count = 0; };

    virtual bool Check();
   
};