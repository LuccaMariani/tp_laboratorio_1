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
        /*
        startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode
        startTesting(4);  // addNode - test_addNode
        startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
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
        */


    int flagLoadText=0;
    int flagLoadBinary=0;

    int option = 0;
    int confirmacionSalida;

    LinkedList* listaEmpleados = NULL;
    LinkedList* listaEmpleados_copia = NULL;
    LinkedList* listaEmpleados_subLista = NULL;

    listaEmpleados = ll_newLinkedList();
    listaEmpleados_copia = ll_newLinkedList();
    listaEmpleados_subLista = ll_newLinkedList();

    do{
        system("cls");
        menu();

        printf("\n- Ingrese una opcion del menu.\n>");
        fflush(stdin);
        validar_Entero(&option);

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
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_addEmployee(listaEmpleados))
                    {
                        printf("\n\nEl empleado fue cargado correctamente.\n\n");
                    }
                    else
                    {
                        printf("\n\nHubo un error en el proceso de alta del empleado.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");

                }
                system("pause");
                break;


            case 4://MODIFICAR EMPLEADO
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_editEmployee(listaEmpleados))
                    {
                        printf("\n\nEl empleado fue dado de modificado correctamente.\n\n");
                    }
                    else
                    {
                        printf("\n\nHubo un error en el proceso de modificacion del empleado.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");
                }
                break;


            case 5://BAJA EMPLEADO
                if(!ll_isEmpty(listaEmpleados))
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
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(controller_ListEmployee(listaEmpleados))
                    {
                        printf("\n\nHubo un error en el proceso de listado de los empleados.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");
                }
                system("pause");
                break;
            case 7://LISTA EMPLEADO COPIA
                if(ll_isEmpty(listaEmpleados_copia))
                {
                    if(controller_ListEmployee(listaEmpleados_copia))
                    {
                        printf("\n\nHubo un error en el proceso de listado de los empleados.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que crear la copia de la lista primero.\n\n");
                }
                system("pause");
                break;


            case 8://ORDENAR EMPLEADOS
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(controller_sortEmployee(listaEmpleados))
                    {
                        printf("\n\nHubo un error en el proceso de listado de los empleados.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");
                }
                break;
            case 9://REALIZAR COPIA ll_clone
                if(!ll_isEmpty(listaEmpleados))
                {
                    listaEmpleados_copia=ll_clone(listaEmpleados);

                    if(ll_containsAll(listaEmpleados, listaEmpleados_copia) && ll_containsAll(listaEmpleados_copia, listaEmpleados))
                    {
                        printf("\n\nHubo un error en el proceso de clonado de los empleados.\n\n");
                    }
                    else
                    {
                        printf("\n\nLa lista principal fue clonada con exito.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");
                }
                system("pause");
                break;

            case 10://CREAR SUBLISTA
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(controller_subListEmployee(listaEmpleados, listaEmpleados_subLista))
                    {
                        printf("\n\nHubo un error en el proceso de sub listado de los empleados.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");
                }
                system("pause");
                break;

            case 11://SALVA TEXTO COPIA
                if(!ll_isEmpty(listaEmpleados_copia))
                {
                    if(!controller_saveAsText("data.csv",listaEmpleados))
                    {
                        printf("\n\nEl proceso de guardado listado copia, de los empleados como texto fue llevado a cabo correctamente.\n\n");
                    }
                    else
                    {
                        printf("\n\nHubo un error en el proceso de guardado listado copia, de los empleados como texto.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que crear la copia de la lista, antes de guardarla.\n\n");
                }
                break;
            case 12://SALVA TEXTO
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_saveAsText("data.csv",listaEmpleados))
                    {
                        printf("\n\nEl proceso de guardado listado de los empleados como texto fue llevado a cabo correctamente.\n\n");
                    }
                    else
                    {
                        printf("\n\nHubo un error en el proceso de guardado listado de los empleados como texto.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");
                }
                break;


            case 13://SALVA BINARIO
                if(!ll_isEmpty(listaEmpleados))
                {
                    if(!controller_saveAsBinary("data.bin",listaEmpleados))
                    {
                        printf("\n\nEl proceso de guardado listado de los empleados como binario fue llevado a cabo correctamente.\n\n");
                    }
                    else
                    {
                        printf("\n\nHubo un error en el proceso de guardado listado de los empleados como binario.\n\n");
                    }
                }
                else
                {
                    printf("\n- Error\n Tiene que cargar los archivos primero.\n\n");
                }
                break;


            case 0://SALE PROGRAMA
                printf("\n- Estas seguro que deseas salir? (Si = 1) (No = 0)\n > ");
                fflush(stdin);
                validar_Entero(&confirmacionSalida);
                if(confirmacionSalida==1)
                {
                    option=99;
                }
                break;
            default:
                printf("- Ingreso una opcion incorrecta.\n ");
                break;
        }

    }while(option != 99);
    return 0;

    ll_deleteLinkedList(listaEmpleados_copia);
    ll_deleteLinkedList(listaEmpleados);

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
    printf(" 6. Listar copia de lista empleados.\n");
    printf(" 8. Ordenar empleados.\n");
    printf(" 9. Realizar copia de la lista principal.\n");
    printf(" 10. Crear sublista entre dos indices.\n");
    printf(" 11. Guardar los datos de la copia lista empleados en el archivo data_copia.csv (modo texto).\n");
    printf(" 12. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 13. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf(" 0. Salir.\n");
}

































