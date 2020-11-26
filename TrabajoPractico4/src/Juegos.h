#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED


#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


int employee_addEmployee(LinkedList* pArrayListEmployee);

int employee_listEmployee(LinkedList* pArrayListEmployee);

int employee_mostrarEmployee(Employee* employee);

int employee_removeEmployee(LinkedList* pArrayListEmployee);

int employee_buscarIdEmployee(int id, LinkedList* pArrayEmp);

int employee_editEmployee(LinkedList* pArrayListEmployee);

int employee_sortEmployee(LinkedList* pArrayListEmployee);

int ordenar_id(void* x, void* y);

int ordenar_nombre(void* x, void* y);

int ordenar_sueldo(void* x, void* y);

int ordenar_horas(void* x, void* y);

#endif // employee_H_INCLUDED
