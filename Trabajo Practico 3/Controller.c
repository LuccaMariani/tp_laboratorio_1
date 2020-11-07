#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

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
    return 1;
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
    return 1;
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
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee emp = {1, "jose", 23,23};

    int error=1;

    FILE* f = fopen("data.csv","wb");

    if(f==NULL){
        printf("No se pudo abrir el archivo data.csv. \n");

    }
    else{
        error=0;
    }

    fwrite(&emp, sizeof(Employee), 1, f);


    return error;
\
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

