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

int menuDeOpciones(float a, float b)
{
    int opcion;

    system("cls");//limpia la pantalla despues de elegir la opcion, despues del switch.
    printf("***Menu Calculadora***\n\n");
    printf("1)Ingresar 1er operando (A=%.2f)\n", a);//asi me cambia el valor de x cuando el usuario ingresa el dato
    printf("2)Ingresar 2do operando (B=%.2f)\n", b);
    printf("3)Calcular todas las operaciones\n");
    printf("    a) Calcular la suma (A+B)\n");
    printf("    b) Calcular la resta (A-B)\n");
    printf("    c) Calcular la division (A/B)\n");
    printf("    d) Calcular la multiplicacion (A*B)\n");
    printf("    e) Calcular el factorial (A!)\n\n");
    printf("4)Informar resultados\n");
    printf("5)Salir\n");

    printf("Ingresar opcion: ");//pido dato de opcion al usuario
    scanf("%d", &opcion);//guardo dato de opcion en la direccion de memoria
    while(opcion<1 || opcion>5)
    {
        printf("Error, ingrese una opcion valida: ");
        scanf("%d", &opcion);
    }

    return opcion;
}
