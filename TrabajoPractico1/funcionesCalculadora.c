#include <stdio.h>
#include <stdlib.h>

int suma (int x,int y)
{
    int resultSuma;

    resultSuma = x + y;

    return resultSuma;
}

int resta (int x,int y)
{
    int resultResta;

    resultResta = x - y;

    return resultResta;
}

float division (float x,float y)
{
    float resultDivision;

    if(y==0)
    {
        resultDivision = 0;
    }
    else
    {
        resultDivision = (float) x/y;
    }

    return resultDivision;
}

int multiplicacion (int x,int y)
{
    //MULTIPLICACION
    int resultMultiplicar;

    resultMultiplicar = x*y;

    return resultMultiplicar;
}

long int factorialX(int x)
{
    //FACTORIAL X
    long int resultFactorialX=1;
    long int temp1;

    for(temp1=1; temp1<=x; temp1++)
    {
        resultFactorialX=temp1*resultFactorialX;
    }

    return resultFactorialX;
}

long int factorialY(int y)
{
    //FACTORIAL Y
    long int resultFactorialY=1;
    long int temp2;

    for(temp2=1; temp2<=y; temp2++)
    {
    resultFactorialY=temp2*resultFactorialY;
    }

    return resultFactorialY;
}


void menu(int opcionMenu, int A, int B)
{

    printf("\n    * CALCULADORA *\n\n");

    switch(opcionMenu)
    {
        case 0:
            //para ningun valor de A o B
            printf("1) Primer operando  ( A = x )\n\n");
            printf("2) Segundo operando ( B = y )\n\n");
        break;
        case 1:
            //para todos los valores de A
            printf("1) Primer operando  ( A = %d )\n\n",A);
            printf("2) Segundo operando ( B = y )\n\n");
        break;
        case 2:
            //para todos los valores de B
            printf("1) Primer operando  ( A = x )\n\n");
            printf("2) Segundo operando ( B = %d )\n\n",B);
        break;
        case 3:
            //para todos los valores de A y B
            printf("1) Primer operando  ( A = %d )\n\n",A);
            printf("2) Segundo operando ( B = %d )\n\n",B);
        break;
    }

    printf("3) Operaciones matematicas\n\n");
    printf(" a. Suma        ( A + B )\n");
    printf(" b. Resta       ( A - B )\n");
    printf(" c. Divison     ( A / B )\n");
    printf(" d. Multipicar  ( A * B )\n");
    printf(" e. Factorial   ( A ! , B !)\n\n");
    printf("4) Informar resultados\n\n");
    printf("5) Salir\n\n");

    return;
}
