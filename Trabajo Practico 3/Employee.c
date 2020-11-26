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
    }
    else
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

///############################################# TERMINA SET Y GET

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

int employee_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    Employee* auxEmployee;

    int flagContinuar=1;

    int id;
    int indice;
    int opcion;
    int seguir;

    char nuevoNombre[128];
    Employee* nuevoHoras;
    int nuevoSueldo;

    if(pArrayListEmployee !=NULL)
    {
        printf("\n\n");
        employee_listEmployee(pArrayListEmployee);

        printf("\n\n- Ingrese el Id del empleado a modificar:\n >");
        fflush(stdin);
        validar_Entero(&id);

        indice=employee_buscarIdEmployee(id, pArrayListEmployee);

        if(indice==-1)
        {
            printf("\n\n- El Id ingresado (%d) no existe en la lista.\nRegresando al menu...\n\n",id);
        }
        else
        {
            auxEmployee= (Employee*)ll_get(pArrayListEmployee,indice);

            while(flagContinuar)
            {
                printf("\n\n - Empleado seleccionado :\n");
                printf("  Id  | Nombre               | Horas     | Sueldo\n");
                employee_mostrarEmployee((Employee*)ll_get(pArrayListEmployee,indice));

                printf("\n\n Escriba el indice de que desea modificar del empleado:\n");
                printf(" 1 -Nombre\n 2 -Horas\n 3 -Sueldo\n 4 -Cancelar modificacion\n");
                printf("\nIngrese opcion:\n >");
                fflush(stdin);
                validar_Entero(&opcion);

                switch(opcion)
                {
                case 1:
                    printf("\n-Ingrese el nuevo nombre:\n > ");
                    fflush(stdin);
                    validar_StringCaracteres(&nuevoNombre);

                    strcpy(auxEmployee->nombre, nuevoNombre);
                    break;
                case 2:
                    printf("\n-Ingrese horas trabajadas:\n > ");
                    fflush(stdin);
                    validar_Entero(&nuevoHoras);

                    auxEmployee->horasTrabajadas= nuevoHoras;
                    break;
                case 3:
                    printf("\n-Ingrese sueldo:\n > ");
                    fflush(stdin);
                    validar_Entero(&nuevoSueldo);

                    auxEmployee->sueldo= nuevoSueldo;
                    break;
                case 4:
                    break;
                default:
                    printf(" Esta opcion no existe\n");
                }

                printf("\n\nDesea salir del menu de modificacion en este empleado?\n\n");
                printf("  Id  | Nombre               | Horas     | Sueldo\n");
                employee_mostrarEmployee((Employee*)ll_get(pArrayListEmployee,indice));
                printf("\n(SI = 1) (NO = 0)\n > ");
                validar_Entero(seguir);


                if(seguir)
                {

                    flagContinuar=0;
                    retorno=1;
                }
                else
                {
                    flagContinuar=1;
                }

            }
        }

    }

    return retorno;
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

int employee_buscarIdEmployee(int id, LinkedList* pArrayListEmployee)
{
    int retornoID=-1;
    Employee* pauxEmployee;

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pauxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            if((pauxEmployee!=NULL) && (pauxEmployee->id==id))
            {
                retornoID=i;
                break;
            }
        }
    }
    return retornoID;
}

int employee_sortEmployee(LinkedList* pArrayListEmployee)
{

    int error= 0;
    int opcion;
    char valOpcion[2];

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



int ordenar_id(void* x, void* y)
{
    int error= -1;
    Employee* pA= (Employee*)x;
    Employee* pB= (Employee*)y;

    if(x !=NULL && y !=NULL)
    {
        if(pA->id > pB->id)
        {
            error= 1;
        }
        else if(pA->id < pB->id)
        {
            error= -1;
        }
        else
        {
            error= 0;
        }
    }

    return error;

}

int ordenar_nombre(void* x, void* y)
{
    int error= -1;
    Employee* pA= (Employee*)x;
    Employee* pB= (Employee*)y;

    if(x !=NULL && y !=NULL)
    {
        if(stricmp(pA->nombre,pB->nombre)>0)
        {
            error = 1;
        }
        else if(stricmp(pA->nombre,pB->nombre)<0)
        {
            error= -1;
        }
        else
        {
            error= 0;
        }
    }

    return error;
}


int ordenar_horas(void* x, void* y)
{
    int error = 0;
    Employee* pA= (Employee*)x;
    Employee* pB= (Employee*)y;

    if(x !=NULL && y !=NULL)
    {
        if(pA->horasTrabajadas > pB->horasTrabajadas)
        {
            error= 1;
        }
        else if(pA->horasTrabajadas < pB->horasTrabajadas)
        {
            error= -1;
        }
        else
        {
            error= 0;
        }
    }

    return error;
}


int ordenar_sueldo(void* x, void* y)
{
    int error= -1;

    Employee* pA= (Employee*)x;
    Employee* pB= (Employee*)y;

    if(x !=NULL && y !=NULL)
    {
        if(pA->sueldo > pB->sueldo)
        {
            error= 1;
        }
        else if(pA->sueldo < pB->sueldo)
        {
            error= -1;
        }
        else
        {
            error= 0;
        }
    }

    return error;
}

