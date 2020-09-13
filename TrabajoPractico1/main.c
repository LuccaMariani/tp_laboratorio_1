#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcionesCalculadora.h"

int main()
{
    int encendido=0;
    int opcionMenu=0;

    int banderaOperaciones=0;


    int opcionResultados;

    int resultSuma;
    int resultResta;
    float resultDivision;
    int resultMultiplicar;
    long int resultFactorialX;
    long int resultFactorialY;

    int num1;
    int num2;

    while (encendido==0)
    {
        system("cls");

        menu(opcionMenu, num1, num2);

        printf("> Ingrese la opcion a realizar: ");
        fflush(stdin);
        scanf("%d",&opcionResultados);

        switch(opcionResultados){
            case 1:
                //
                printf("\n> Ingrese el primer operando (A): ");
                fflush(stdin);
                scanf("%d",&num1);

                if(opcionMenu==0)
                {
                    opcionMenu=1;
                }
                else if(opcionMenu==2)
                {
                    opcionMenu=3;
                }
                break;
            case 2:
                //
                printf("\n> Ingrese el segundo operando (B): ");
                fflush(stdin);
                scanf("%d",&num2);

                if(opcionMenu==0)
                {
                    opcionMenu=2;
                }
                else if (opcionMenu==1)
                {
                    opcionMenu=3;
                }
                break;
            case 3:
                //
                if(opcionMenu==3)
                {
                    resultSuma = suma(num1,num2);
                    resultResta = resta(num1,num2);
                    resultDivision = division(num1,num2);

                    if(resultDivision==0)
                    {
                        printf("\n--No se pudo calcular la division, ya que no es posible dividir por 0.\n");
                    }

                    resultMultiplicar = multiplicacion(num1,num2);

                    if(num1>=0)
                    {
                        resultFactorialX = factorialX(num1);
                    }
                    else
                    {
                        printf("\n--No se pudo calcular el factorial de A, ya que (%d) es negativo.\n", num1);
                    }
                    if(num2>=0)
                    {
                        resultFactorialY = factorialY(num2);
                    }
                    else
                    {
                        printf("\n--No se pudo calcular el factorial de B, ya que (%d) es negativo.\n", num2);
                    }

                    printf("\n+ + Operaciones matematicas calculadas con exito. + +\n");
                    banderaOperaciones=1;
                }
                else
                {
                    printf("\n--Debe ingresar un operando A y B antes de realizar las operaciones.\n");
                }

                break;
            case 4:
                //
                if(banderaOperaciones==1)
                {
                    printf("\n+ + Informando resultados. + +\n");
                    //suma
                    printf("\na. El resultado de (%d + %d ):  %d  \n", num1, num2,resultSuma);
                    //resta
                    printf("b. El resultado de ( %d - %d ) es:  %d  \n", num1, num2, resultResta);
                    //division
                    if(resultDivision==0)
                    {
                        printf("c. No se pudo calcular la division, ya que no es posible dividir por 0.\n");
                    }
                    else
                    {
                        printf("c. El resultado de ( %d / %d ) es:  %.2f  \n", num1, num2, resultDivision);
                    }
                    //multiplicacion
                    printf("d. El resultado de ( %d * %d ) es:  %d  \n", num1, num2, resultMultiplicar);
                    //factorialX
                    if(num1>=0)
                    {
                        printf("e. El resultado de ( %d ! ) es:  %ld \n", num1, resultFactorialX);
                    }
                    else
                    {
                        printf("e. No se pudo calcular el factorial, ya que (%d) es negativo.\n", num1);
                    }
                    //factorialY
                    if(num2>=0)
                    {
                        printf("e. El resultado de ( %d ! ) es:  %ld \n", num2, resultFactorialY);
                    }
                    else
                    {
                        printf("e. No se pudo calcular el factorial, ya que (%d) es negativo.\n", num1);
                    }
                }
                else
                {
                    printf("\n--Debe realizar las operaciones antes de mostrar los resultados.\n");
                }
                break;
            case 5:
                //
                printf("\n\n>Desea salir del programa? (Si=1) (No=0)\n>");
                fflush(stdin);
                scanf("%d",&encendido);
        }
        printf("\n");
        system("pause");
    }
    return 0;
}
