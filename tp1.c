#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp1.h"

float sumarTp1(float a, float b)
{
    float resultado;

    resultado=a+b;

    return resultado;
}

float restaTp1(float a, float b)
{
    float resultado;

    resultado=a-b;

    return resultado;
}

float divisionTp1(float a, float b)
{
    float resultado;

    resultado=a/b;

    return resultado;
}

float multiplicacionTp1(float a, float b)
{
    float resultado;

    resultado=a*b;

    return resultado;
}

long int factorialTp1(float a)
{
    long int factorial;

    factorial=1;

    for(int i=1; i<=a; i++)
    {
        factorial*=i;
    }

    return factorial;
}
