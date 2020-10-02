#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#include "bibliotecas.h"
#include "ArrayEmployees.h"

#define TAM 1000

void printMenu(int menu);

int main()
{

    int opcionMenu;

    int order=0;
    int impresionMenu=1;
    int encendido=0;

    sEmployee listado[TAM];

    int Id=1000;

    //Iniciar todos los arrays de empleados, vacios
    if(initEmployees(listado,TAM) == 0)
    {
        printf("\n- Inicializacion exitosa, sin errores.\n\n");
    }
    else
    {
        printf("\n- Error al inicializar.\n\n");
    }
    system("pause");

    while(encendido!=1)
    {

        printMenu(impresionMenu);

        printf("> Ingrese la opcion realizar: ");
        fflush(stdin);
        scanf("%d",&opcionMenu);

        if(impresionMenu==1)
        {
            impresionMenu=menu1(opcionMenu, impresionMenu, encendido, listado, &Id);
        }
        else
        {
            impresionMenu=menu2(opcionMenu, impresionMenu, listado, order);
        }
        printf("\n\n");
        system("pause");
    }
    return 0;
}

void printMenu(int menu)
{

    if(menu==1)
    {
        system("cls");
        printf("\n    * MENU *\n\n");
        printf("- Ingrese la opcion a realizar. \n\n");
        printf(" 1) ALTAS\n");
        printf(" 2) MODIFICAR\n");
        printf(" 3) BAJA\n");
        printf(" 4) INFORMAR\n");
        printf(" 5) Salir\n\n");
    }
    else if (menu==2)
    {
        system("cls");
        printf("\n    * MENU *\n\n");
        printf("- Ingrese la opcion a realizar. \n\n");
        printf(" *) ALTAS\n");
        printf(" *) MODIFICAR\n");
        printf(" *) BAJA\n");
        printf(" *) INFORMAR\n");
        printf("    1) Listado de empleados.\n");
        printf("    2) Total y promedio  de los salarios.\n");
        printf("    3) Volver al MENU PRINCIPAL.\n");
        printf(" *) Salir\n\n");
    }

    return;
}
