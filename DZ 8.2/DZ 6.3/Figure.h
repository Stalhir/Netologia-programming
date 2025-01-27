#pragma once
#include "EincorrectData.h"
#include <iostream>

class Figure
{
protected:
    int blocked = false; 
    int sides_count{ 0 };
    Figure(int sides_count,bool THIS_CONSTRUCTOR_FOR_Inheritance)
    {
        this->sides_count = sides_count;
    }
    Figure(int sides_count)
    {
        this->sides_count = sides_count;
     
        try 
        {
            if (Check()==false) throw EincorrectData("Ошибка создания фигуры Причина: Неизвестна"); 
        } 
        catch (const EincorrectData& e) {
            std::cout << e.what() << std::endl;
          
        } 

            
        
    }
    

public:
    int get_sides_count();
    

    virtual void print_info();
   
    Figure() { sides_count = 0; };

    virtual bool Check();
   
};