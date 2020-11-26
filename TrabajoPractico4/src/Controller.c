#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Juegos.h"
#include "Controller.h"
#include "parser.h"
#include "Funciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int error=1;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {

        FILE* pF = fopen(path,"r");

        if(pF!=NULL)
        {
            parser_EmployeeFromText(pF, pArrayListEmployee);
            fclose(pF);
            error=0;
        }
    }
    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error=1;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* pF=fopen(path,"rb");

        if(pF!=NULL)
        {
            parser_EmployeeFromBinary(pF,pArrayListEmployee);
            fclose(pF);
            error=0;
        }
    }

    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;

    if(pArrayListEmployee!=NULL)
    {
        if(!employee_addEmployee(pArrayListEmployee))
        {
            error=0;
        }
    }
    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
        int error=-1;

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf("    *Modificar Empleados*\n\n");
        if(employee_editEmployee(pArrayListEmployee))
        {
            error= 0;
        }
    }
    return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf("    *Baja Empleado*\n");
        if(employee_removeEmployee(pArrayListEmployee))
        {
            printf("\n");
            printf(" Baja ejecutada con exito!!!\n");
            error=0;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }

    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf("    *Lista Empleados*\n\n");

        if(!employee_listEmployee(pArrayListEmployee))
        {
            error=0;
        }
        else
        {
            printf("Hubo un error al listar los empleados.\n");
        }
    }
    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int error= 0;
    int opcion;

    if(pArrayListEmployee !=NULL)
    {
        printf("Escriba el indice del critero de ordenamiento de la lista:\n");
        printf(" 1 -Id\n 2 -Nombre\n 3 -Horas Trabajadas\n 4 -Sueldo\n");
        printf("\nIngrese opcion:\n >");
        fflush(stdin);
        validar_Entero(&opcion);

        printf("\nOrdenando empleados, por favor espere...\n");
        switch(opcion)
        {
            case 1:
                ll_sort(pArrayListEmployee, ordenar_id, 1);
                break;
            case 2:
                ll_sort(pArrayListEmployee, ordenar_nombre, 1);
                break;
            case 3:
                ll_sort(pArrayListEmployee, ordenar_horas, 1);
                break;
            case 4:
                ll_sort(pArrayListEmployee, ordenar_sueldo, 1);
                break;
            default:
                error= 0;
                printf(" Esta opcion no existe\n");
                break;
        }
        error= 1;
    }

    return error;
}

int controller_cloneEmployee(LinkedList* pArrayListEmployee, LinkedList* pArrayListEmployee_copia)
{
    int error=-1;

    if(pArrayListEmployee!=NULL)
    {
        pArrayListEmployee_copia=ll_clone(pArrayListEmployee);
        error=0;
        //error=employee_clonarLista(pArrayListEmployee, pArrayListEmployee_copia);
    }

    return error;
}

int controller_subListEmployee(LinkedList* pArrayListEmployee, LinkedList* pArrayEmployee_subList)
{

    int error=-1;

    int principio;
    int fin;
    int tamLista;
    int flagCorrecto1=0;
    int flagCorrecto2=0;

    int confirma;

    if(pArrayListEmployee!=NULL)
    {
        tamLista=ll_len(pArrayListEmployee);

        system("cls");
        printf("\n\n    *Crear SubListado Empleados*\n\n");
        printf(" - Listado original:\n\n");
        employee_listEmployee(pArrayListEmployee);

        while(flagCorrecto1==0)
        {
            printf("\n\n - Donde iniciara el sub listado?\n > ");
            validar_Entero(&principio);

            if(principio>=tamLista-1)
            {
                 printf("\n\n - Error\n Tiene que seleccionar un numero mas chico que la misma lista.");
            }
            else
            {
                flagCorrecto1=1;
            }
        }

        while(flagCorrecto2==0)
        {
            printf("\n\n - Donde finalizara el sub listado?\n > ");
            validar_Entero(&fin);

            if(fin<=principio)
            {
                 printf("\n\n - Error\n Tiene que seleccionar un numero mas grande que el inicio.");
            }
            else
            {
                flagCorrecto2=1;
            }
        }

        pArrayEmployee_subList=ll_subList(pArrayListEmployee,principio,fin);

        system("cls");
        printf("\n\n    *SubListado de Empleados*\n\n");
        employee_listEmployee(pArrayEmployee_subList);

        printf("\n\nDesea guardar este sub listado?\n (Si = 1) (No = 0)\n > ");
        validar_Entero(&confirma);
        if(confirma==0)
        {
            printf("La sub lista fue eliminada.");
            ll_deleteLinkedList(pArrayEmployee_subList);
        }
        else
        {
            printf("La sub lista fue guardada temporalmente.");
        }
        error=0;
    }



    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;

    FILE* pF = fopen(path,"w");
    Employee* auxEmployee;

     if(path!=NULL && pArrayListEmployee!=NULL)
    {
        if(pF != NULL)
        {
            fprintf(pF,"Id,Nombre,HorasTrabajadas,Sueldo\n");

            for (int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
                if (auxEmployee !=NULL)
                {
                    fprintf(pF,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
                    error = 0;
                }
            }
            fclose(pF);
        }
    }
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error=1;

    Employee* auxEmployee;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* pF=fopen(path,"wb");

        if(pF!=NULL)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmployee=(Employee*) ll_get(pArrayListEmployee, i);

                if(auxEmployee!=NULL)
                {
                    fwrite(auxEmployee, sizeof(Employee), 1, pF);
                    error = 0;
                }
            }
            fclose(pF);
        }
    }
    return error;
}
