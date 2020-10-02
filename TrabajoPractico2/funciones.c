#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bibliotecas.h"
#include "ArrayEmployees.h"

#define TAM 1000

int menu1(int opcionMenu, int impresionMenu, int encendido, sEmployee listado[], int* Id)
{
    // validacion para el print menu 1
    while(opcionMenu>5 || opcionMenu<1 || isalpha(opcionMenu)!=0)
    {
        printf("\n- Opcion incorrecta -\n\n> Ingrese la opcion realizar: ");
        fflush(stdin);
        scanf("%d",&opcionMenu);
    }

    switch (opcionMenu)
    {
        case 1:
            //funcion altas
            //      Se debe permitir ingresar un empleado calculando automáticamente el número
            //      de Id. El resto de los campos se le pedirá al usuario.
            if(addEmployee(listado, TAM, *Id)==1)
            {
                *Id=*Id+1;
            }
            break;
        case 2:
            //funcion modificar
            if(EmptyEmployeeList(listado, TAM))
            {
                printf("\n- El listado se encuentra vacio -\n");
                printf("- No se puede modificar ningun empleado.\n");
            }
            else
            {
                modificarEmployee(listado, TAM);
            }
            break;
        case 3:
            //funcion baja
            if(EmptyEmployeeList(listado, TAM))
            {
                printf("\n- El listado se encuentra vacio -\n");
                printf("- No se puede dar de baja a ningun empleado.\n");
            }
            else
            {
                removeEmployee(listado, TAM, *Id);
            }
            break;
        case 4:
            impresionMenu=2;
            // arranca menu 2
            break;
        case 5:
            //salir
            printf("\n\n> Desea salir del programa? (Si=1) (No=0)\n> ");
            fflush(stdin);
            scanf("%d",&encendido);
            break;
    }
    return impresionMenu;
}

int menu2 (int opcionMenu, int impresionMenu, sEmployee listado[], int order)
{
    while(opcionMenu>3 || opcionMenu<1 || isalpha(opcionMenu)!=0)
    {
        printf("\n- Opcion incorrecta -\n\n> Ingrese la opcion realizar: ");
        fflush(stdin);
        scanf("%d",&opcionMenu);
    }
    switch(opcionMenu)
    {
        case 1:
            //  case lista de empleados
            if(EmptyEmployeeList(listado, TAM))
            {
                printf("\n- El listado se encuentra vacio -\n");
                printf("- No se puede informar la lista de empleados.\n");
            }
            else
            {
                printf("\n> Ingrese el metodo de ordenamiento por sector.\n De mayor a menor: 0\n De menor a mayor: 1\n> ");
                fflush(stdin);
                scanf("%d",&order);

                while(opcionMenu>3 || opcionMenu<1 || isalpha(opcionMenu)!=0)
                {
                    printf("\n- Opcion incorrecta -\n\n> Ingrese el metodo de ordenamiento por sector.\n De mayor a menor: 0\n De menor a mayor: 1\n> ");
                    fflush(stdin);
                    scanf("%d",&order);
                }
                sortEmployees(listado, TAM, order);
                printEmployees(listado, TAM);
            }
            break;
        case 2:

            if(EmptyEmployeeList(listado, TAM))
            {
                printf("\n- El listado se encuentra vacio -\n");
                printf("- No se puede informar el promedio ni todal de los salarios.\n");
            }
            else
            {
                printEmployeeSalary(listado, TAM);
            }
            break;
        case 3:
            impresionMenu=1;
    }
    return impresionMenu;
}

int validacionCadenaCaracteres(char cadenaCaracteres[])
{
    int i;
    int encontrarNumero = 0;
    int len = strlen(cadenaCaracteres);

    for( i = 0; i < len; i++)
    {
        if(0==isalpha(cadenaCaracteres[i]))
        {
            encontrarNumero = 1;
            break;
        }
    }
    return encontrarNumero; // devuelve 1 si encuentra un numero, 0 si no.
}
