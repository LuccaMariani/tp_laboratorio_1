#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Employee.h"
#include "LinkedList.h"
#include "Funciones.h"


Employee* employee_new()
{
    Employee* auxEmployee = (Employee*)malloc(sizeof(Employee));
    return auxEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* auxEmployee=employee_new();

    if((idStr!=NULL) && (nombreStr!=NULL) && (horasTrabajadasStr!=NULL) && (sueldoStr!=NULL) && (auxEmployee!=NULL))
    {
        auxEmployee->id= atoi(idStr);
        auxEmployee-> horasTrabajadas= atoi(horasTrabajadasStr);
        strcpy(auxEmployee->nombre, nombreStr);
        auxEmployee->sueldo= atoi(sueldoStr);
        return auxEmployee;
    }else
    {
        employee_delete(auxEmployee);
        return NULL;
    }
}

void employee_delete(Employee* auxEmployee)
{
    if(auxEmployee!=NULL)
    {
        free(auxEmployee);
    }
}

int employee_setId(Employee* this,int id)
{
    int error=0;

    if(this!=NULL)
    {
        this->id=id;
        error=1;
    }

    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error=0;

    if((this!=NULL) && (id!=NULL))
    {
        *id=this->id;
        error=1;
    }

    return error;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int error=0;

    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        error=1;
    }

    return error;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int error=0;

    if((this!=NULL) && (nombre!=NULL))
    {
        error=1;
        strcpy(nombre, this->nombre);
    }

    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error=0;

    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        error=1;
    }

    return error;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error=0;

    if((this!=NULL) && (horasTrabajadas!=NULL))
    {
        *horasTrabajadas=this->horasTrabajadas;
        error=1;
    }

    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error=0;

    if(this!=NULL)
    {
        this->sueldo=sueldo;
        error=1;
    }

    return error;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int error=0;

    if((this!=NULL) && (sueldo!=NULL))
    {
        *sueldo=this->sueldo;
        error=1;
    }

    return error;
}


int employee_addEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    Employee* newEmployee=employee_new();

    if(pArrayListEmployee!=NULL)
    {

        id=(ll_len(pArrayListEmployee) + 1);
        printf("\nId del empleado: %d\n", id);

        printf("Ingrese el nombre del empleado:\n> ");
        validar_StringCaracteres(nombre);

        printf("\nIngrese las horas trabajadas:\n> ");
        validar_Entero(&horasTrabajadas);

        printf("\nIngrese el sueldo:\n> ");
        validar_Entero(&sueldo);

        employee_setId(newEmployee, id);
        employee_setNombre(newEmployee, nombre);
        employee_setHorasTrabajadas(newEmployee, horasTrabajadas);
        employee_setSueldo(newEmployee, sueldo);

        ll_add(pArrayListEmployee, newEmployee);

        error=0;
    }

    return error;
}


int employee_listEmployee(LinkedList* pArrayListEmployee)
{
    int error=1;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {

        printf("  Id  | Nombre               | Horas     | Sueldo\n");
        printf("------|----------------------|-----------|------------\n");

        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
                auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
                employee_mostrarEmployee(auxEmployee);
        }
        error=0;
    }
    printf("\n");
    return error;
}

int employee_mostrarEmployee(Employee* employee)
{
    int error=1;
    if(employee!=NULL)
    {
        error =0;
        printf("%5d | %20s | %9d | %9d \n",employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);
    }
    return error;
}


int employee_removeEmployee(LinkedList* pArrayListEmployee)
{

    int error=1;
    int id;
    int retornoId;
    char confirmarBaja;

    if(pArrayListEmployee !=NULL)
    {

        employee_listEmployee(pArrayListEmployee);

        printf(" Ingrese ID del empleado a dar de baja: ");
        validar_Entero(&id);

        retornoId=employee_buscarIdEmployee(id,pArrayListEmployee);

        if(retornoId<0)
        {
            printf("El ingresado (%d) no existe.\n",id);
        }
        else
        {
            system("cls");
            printf(" *Baja Empleado*\n\n");
            printf("  Id  | Nombre               | Horas     | Sueldo\n");
            printf("------|----------------------|-----------|------------\n");
            employee_mostrarEmployee((Employee*)ll_get(pArrayListEmployee,retornoId));


            printf("\n- Confirma que este es el empleado a dar de baja? (s = Si)\n>");
            fflush(stdin);
            scanf("%c",&confirmarBaja);
            if(confirmarBaja!='s')
            {
                printf("Se cancelo la baja del empleado correctamente.\n");
            }
            else
            {
                ll_remove(pArrayListEmployee,retornoId);
                printf("El empleado a sido dado de baja con exito.\n");
            }
        }
        error=0;
    }

    return error;
}

int employee_buscarIdEmployee(int id, LinkedList* pArrayEmp)
{
    int retornoID=-1;
    Employee* pauxEmployee;

    if(pArrayEmp!=NULL)
    {
        for(int i=0; i<ll_len(pArrayEmp); i++)
        {
            pauxEmployee=(Employee*)ll_get(pArrayEmp,i);
            if((pauxEmployee!=NULL) && (pauxEmployee->id==id))
            {
                retornoID=i;
                break;
            }
        }
    }
    return retornoID;
}
