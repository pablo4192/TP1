#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tp1.h"//en el main solo se carga el archivo.h

int main()
{
    float numero1=0;//declaro e inicializo variable 1er numero en 0
    float numero2=0;//declaro e inicializo variable 2do numero en 0
    float suma;//declaro variable para realizar la suma y guardar el resultado en su direccion de memoria
    float resta;
    float division;
    float multiplicacion;
    long int factorialA;
    long int factorialB;

    int flagNumero1=0;//flags para validar que se ingresen los datos en el orden correcto
    int flagNumero2=0;
    int flagCalcular=0;

    int opcion;//variable donde se guarda la opcion elegida

    char salir;
    char seguir;//variable de control del bucle

    seguir='s';//mientras sea =='s' vuelve al bucle, cuando sea !='s' sale.

    do
    {
        system("cls");//limpia la pantalla despues de elegir la opcion, despues del switch.
        printf("***Menu Calculadora***\n\n");
        printf("1)Ingresar 1er operando (A=%.2f)\n", numero1);//asi me cambia el valor de x cuando el usuario ingresa el dato
        printf("2)Ingresar 2do operando (B=%.2f)\n", numero2);
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

        switch(opcion)//acciones a seguir segun opcion elegida
        {
        case 1:
            system("cls");//limpio pantalla de menu y dejo solamente a la vista ingresar el dato
            printf("Escogio opcion 1)\n");
            printf("Por favor ingrese 1er operando: ");//entrada 1er dato por el usuario
            scanf("%f", &numero1);//guardo dato en direccion de memoria
            flagNumero1=1;
            break;
        case 2:
            system("cls");
            printf("Escogio opcion 2)\n");
            printf("Por favor ingrese 2do operando: ");//entrada 2do dato por el usuario
            scanf("%f", &numero2);//guardo dato en direccion de memoria
            flagNumero2=1;
            break;
        case 3:
            if(flagNumero1==1 && flagNumero2==1)//valido si las banderas de num1 y num2 estan levantadas para entrar y hacer las operaciones.
            {
                system("cls");
                suma=sumarTp1(numero1,numero2);//llamada a funcion sumarTp1, pasandole los parametros.
                resta=restaTp1(numero1,numero2);//llamada a funcion restarTp1
                if(numero2!=0)//valido si el 2do numero es !=0, asi si es 0 ni siquiera la hace la operacion
                {
                    division=divisionTp1(numero1,numero2);//llamada a funcion divisionTp1
                }
                multiplicacion=multiplicacionTp1(numero1,numero2);//llamada a funcion multiplicacioTp1
                printf("Las operaciones fueron calculadas.\nIngrese enter y luego opcion 4 para mostrar resultados.\n");
                if(numero1>=0)//valido asi si es negativo el numero, que ni se gaste en hacer el factorial.
                {
                    factorialA=factorialTp1(numero1);//llamada a funcion factorialTp1
                }
                if(numero2)
                {
                    factorialB=factorialTp1(numero2);//llamada a funcion factorialTp1
                }
                flagCalcular=1;
            }
            else
            {
                system("cls");
                printf("No se pueden hacer calculos antes de ingresar los dos operandos.\nPor favor ingrese los datos en las opciones 1) y 2)\n");
            }

            getch();//hace una pausa esperando el enter para seguir con el flujo. tambien podria usar system("pause");
            break;
        case 4:
            if(flagCalcular==1)//valido si la bandera de 3)calcular esta levantada para poder mostrar los resultados.
            {
                system("cls");
                printf("El resultado de la suma es: %.2f\n", suma);
                printf("El resultado de la resta es: %.2f\n", resta);
                if(numero2!=0)//valido para mostrar la division
                {
                    printf("El resultado de la division es: %.2f\n", division);
                }
                else
                {
                    printf("No es posible dividir por 0\n");
                }
                printf("El resultado de la multiplicacion es: %.2f\n", multiplicacion);
                if(numero1>=0)//valido si es positivo que muestre el resultado
                {
                    printf("El resultado del factorial de A es: %ld\n", factorialA);
                }
                else//si es negativo que informe al usuario que no se pudo hacer la operacion
                {
                    printf("No se puede realizar el factorial de numeros negativos.\n");
                }

                if(numero2>=0)
                {
                    printf("El resultado del factorial de B es: %ld\n", factorialB);
                }
                else
                {
                    printf("No se puede realizar el factorial de numeros negativos.\n");
                }
            }
            else//si la bandera calcular esta baja le pido al usuario los pasos correctos del flujo del programa.
            {
                system("cls");
                printf("No hay resultados para mostrar.\nPor favor primero calcule las operaciones en la opcion 3)\n");
            }
            getch();
            break;
        case 5:
            printf("Esta seguro que desea salir?\n(Ingrese: s para SALIR / cualquier otra tecla para CANCELAR)\n");
            fflush(stdin);//limpio el buffer ya que ingreso un caracter
            scanf("%c", &salir);//guardo el valor en la direccion de memoria de salir
            salir=tolower(salir);//si ingresan mayuscula lo paso a minuscula
            if(salir=='s')//valido para confirmar salida o cancelar salida, si no entra al if sigue..
            {
                seguir='n';//cambio el valor de seguir para salir del bucle.
            }
            break;
        }

    }while(seguir=='s');

    return 0;
}



/*Enunciado.
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar 1er operando (A=x)  ok
2. Ingresar 2do operando (B=y)  ok
3. Calcular todas las operaciones

a) Calcular la suma (A+B)   ok
b) Calcular la resta (A-B)  ok
c) Calcular la division (A/B)   ok
d) Calcular la multiplicacion (A*B  ok
e) Calcular el factorial (A!) ok

4. Informar resultados  ok

a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir    ok

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,    ok
que contenga las funciones para realizar las cinco operaciones.

• En el menú deberán aparecer los valores actuales cargados en los operandos A y B  ok
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

• Deberán contemplarse los casos de error (división por cero, etc)  ok

• Documentar todas las funciones    ok
*/
