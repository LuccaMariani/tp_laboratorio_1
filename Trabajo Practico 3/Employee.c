#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Employee.h"


Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_addEmployee(LinkedList* this this)
{
    int error

    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
    char id[128];

    /// MANERA A

    int ok=0;
    char confirma='n';


    Employee* newEmployee=employee_new();

    if(this!=NULL)
    {

        obtenerId(&id);
        sprintf(idStr, "%d", id);


        getAlphaString("Ingrese el nombre del empleado: ", "Error, intente de nuevo: ", 128, nombreStr);
        employee_setNombre(newEmployee, nombreStr);;


        getNumberString("Ingrese las horas trabajadas: ", "Error, intente de nuevo: ", 128, horasStr);


        getNumberString("Ingrese el sueldo del empleado: ", "Error, intente de nuevo: ", 128, sueldoStr);


        confirma=getLetter("Confirma alta?: ", "Caracter invalido, intente de nuevo: ");

        if(confirma=='s')
        {
            newEmployee=employee_newParametros(idStr, nombreStr, horasStr, sueldoStr);
            ll_add(this, newEmployee);
            actualizarId(id);
            ok=1;
        }
    }


    ///MANERA B

    int retorno=-1;
    Employee* pEmpleado=NULL;

    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];
    char id[128];

    if(this != NULL)
    {
       sprintf(id,"%d",proximoId());

        if(!utn_getCadena(nombre,sizeof(nombre),1,"Ingrese el nombre del empleado: ","Error,reingrese: "))
        {
            if(!utn_getCadena(horasTrabajadas,sizeof(horasTrabajadas),1,"Ingrese las horas trabajadas por este empleado : ","Error.Reingrese: "))
            {
                if(!utn_getCadena(sueldo,sizeof(sueldo),1,"Ingrese el sueldo del empleado: ","Error.Reingrese: "))
                {
                    pEmpleado=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

                    if(pEmpleado != NULL)
                    {
                        if(!ll_add(this,pEmpleado))
                        {
                            retorno=0;//EXITO
                        }
                    }
                }
            }
        }

    }
    return retorno;
}
