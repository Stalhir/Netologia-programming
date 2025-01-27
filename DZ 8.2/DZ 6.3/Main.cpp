#include <iostream>
#include "EincorrectData.h"
#include "Figure.h"
#include "Triangle.h"
#include "RAtriangle.h"
#include "Itriangle.h"
#include "Etriangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"

#pragma once 

using namespace std;



int main()
{
    setlocale(LC_ALL, "rus");

    //Figure F;
    Triangle T(10, 20, 30, 50, 60, 70);
    RAtriangle RAT(10, 20, 30, 50, 60, 90);
    Itriangle  IT(10, 20, 10, 50, 60, 50);
    Etriangle ET(30, 30, 30, 60, 60, 60);

    //Quadrangle Q(10, 20, 30, 40, 50, 60, 70, 80);
    //Rectangle R(10, 20, 10, 20, 90, 90, 90, 90);
    //Square S(20, 20, 20, 20, 90, 90, 90, 90);
    //Parallelogram P(20, 30, 20, 30, 30, 40, 30, 40);
    //Rhomb Rh(30, 30, 30, 30, 30, 40, 30, 40);


}