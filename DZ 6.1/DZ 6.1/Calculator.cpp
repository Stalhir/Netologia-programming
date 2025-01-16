#include "Calculator.h"

int add(int a, int b)
{
    
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mult(int a, int b)
{
    return a*b;
}

int divis(int a, int b)
{
    return a/b;
}

int degree(int a, int b)
{
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c = c*a;
    }


    return c;
}
