#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"


/// NO CREAS NUEVAS FUNCIONES, SOLO MODIFICAS ESTAS.


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pF, LinkedList* pArrayListEmployee)
{
    int error=0;
    char buffer[4][128];

    int cantidadParam;

    Employee* auxEmployee=NULL;

    if((pF!=NULL) && (pArrayListEmployee!=NULL))
    {
        fscanf(pF,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pF))
        {

            cantidadParam=fscanf(pF,"%[^,] , %[^,], %[^,], %[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cantidadParam==4)
            {
                auxEmployee= employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                if(auxEmployee!=NULL)
                {
                    ll_add(pArrayListEmployee,auxEmployee);
                    error=1;
                }
            }
            else
            {
                printf("Error inside parser Employee from text.\n\n");
                break;
            }
        }
    }

    return error;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pF, LinkedList* pArrayListEmployee)
{
    int error=0;

    Employee* auxEmployee;

    if((pF!=NULL) && (pArrayListEmployee!=NULL))
    {
        while(!feof(pF))
        {
            auxEmployee=employee_new();

            if(fread(auxEmployee, sizeof(Employee),1,pF)!=0)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                error=1;
            }
        }
    }
    return error;
}
