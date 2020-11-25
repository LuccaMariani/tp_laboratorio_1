#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

#include "LinkedList.h"
#include "Controller.h"
#include "Juegos.h"

// LinkedList* listaEmpleados = ll_newLinkedList();

void menu();

int main()
{

        //startTesting(1);  // ll_newLinkedList
        //startTesting(2);  // ll_len
        //startTesting(3);  // getNode - test_getNode
        //startTesting(4);  // addNode - test_addNode
        //startTesting(5);  // ll_add
        //startTesting(6);  // ll_get
        //startTesting(7);  // ll_set
        //startTesting(8);  // ll_remove

        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort

        system("pause");


    int flagLoadText=0;
    int flagLoadBinary=0;
    int flagAddEmp=0;
    int option = 0;
    char confirmacionSalida = 'n';

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        system("cls");
        menu();

        printf("\n- Ingrese una opcion del menu.\n>");
        fflush(stdin);
        scanf("%d",&option);

        switch(option)
        {
            case 1://CARGA TEXT
                if(!flagLoadBinary && !flagLoadText)
                {
                    if(!controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("El archivo de texto fue cargado con exito.\n\n");
                        flagLoadText=1;
                    }
                    else
                    {
                        printf("Hubo un error en el proceso de cargado del archivo de texto.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\nNo puede cargar los archivos 2 veces.\n\n");

                }
                system("pause");
                break;

            case 2://CARGA BINARIOS
                if(!flagLoadBinary && !flagLoadText)
                {
                    if(!controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        flagLoadBinary=1;
                        printf("El Archivo binario fue cargado con exito.\n\n");
                    }
                    else
                    {
                        printf("Hubo un error en el proceso de cargado del archivo de binario.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\nNo puede cargar los archivos 2 veces.\n\n");

                }
                system("pause");
                break;


            case 3://ALTA EMPLEADO
                if(flagLoadText || flagLoadBinary)
                {
                    if(!controller_addEmployee(listaEmpleados))
                    {
                        flagAddEmp=1;
                        printf("El empleado fue cargado correctamente.\n\n");
                    }
                    else
                    {
                        printf("Hubo un error en el proceso de alta del empleado.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");

                }
                system("pause");
                break;


            case 4://MODIFICAR EMPLEADO
                break;


            case 5://BAJA EMPLEADO
                if(flagLoadText || flagLoadBinary)
                {
                    if(!controller_removeEmployee(listaEmpleados))
                    {
                        printf("El empleado fue dado de baja correctamente.\n\n");
                    }
                    else
                    {
                        printf("Hubo un error en el proceso de baja del empleado.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");
                }
                system("pause");
                break;


            case 6://LISTA EMPLEADO
                if(flagLoadText || flagLoadBinary)
                {
                    if(controller_ListEmployee(listaEmpleados))
                    {
                        printf("Hubo un error en el proceso de listado de los empleados.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");
                }
                system("pause");
                break;


            case 7://ORDENAR EMPLEADOS
                break;


            case 8://SALVA TEXTO
                if(!controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("TODO OK.\n\n");
                }
                else
                {
                    printf("ALGO MAL.\n\n");
                }
                break;


            case 9://SALVA BINARIO
                if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("TODO OK.\n\n");
                }
                else
                {
                    printf("ALGO MAL.\n\n");
                }
                break;


            case 10://SALE PROGRAMA
                printf("\n- Estas seguro que deseas salir? (Si = s)\n>");
                fflush(stdin);
                scanf("%c",&confirmacionSalida);
                //tolower(confirmacionSalida);
                if(confirmacionSalida!='s')
                {
                    option=0;
                }
                break;
            default:
                printf("- Ingreso una opcion incorrecta.\n ");
                break;
        }

    }while(option != 10);
    return 0;
}

void menu()
{
    printf(" TP3 - Mariani - LinkedList\n\n");
    printf(" Menu:\n\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf(" 3. Alta de empleado.\n");
    printf(" 4. Modificar datos de empleado.\n");
    printf(" 5. Baja de empleado.\n");
    printf(" 6. Listar empleados.\n");
    printf(" 7. Ordenar empleados.\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir.\n");
}

































