#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"

/// NO CREAS NUEVAS FUNCIONES, SOLO MODIFICAS ESTAS.
/// NO CREAS NUEVAS FUNCIONES, SOLO MODIFICAS ESTAS.
/// NO CREAS NUEVAS FUNCIONES, SOLO MODIFICAS ESTAS.

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
    return 1;
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
    return 1;
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
