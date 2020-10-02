#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "bibliotecas.h"

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty; // 1 = esta vacio , 0 = esta cargado

} typedef sEmployee;

/** \brief Coloca en todos los isEmpty de la estructura de empleados en 1.
*
* \param listado[] sEmployee Array de lista de empleados.
* \param len int Longitud del array del listado.
* \return int Return Retorna 1 si hubo algun error en la ejecucion de la funcion
*
*/
int initEmployees(sEmployee listado[], int len);


/** \brief Cambia los valores de un empleado auxiliar a los ingresados
*          por el usuario, y lugeo estos valores son remplazados
*          en el primer lugar vacio de la lista de empleados.
*
* \param listado[] sEmployee Array de lista de empleados.
* \param len int Longitud del array del listado.
* \param id int Legajo del empleado.
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(sEmployee listado[], int len, int id);


/** \brief  Busca un empleado por el Id y devuelve su posicion en el array.
*
* \param listado[] sEmployee Array de lista de empleados.
* \param len int Longitud del array del listado.
* \param id int
* \return Devuelve -1 si no encuentra al empleado, sino devuelve su posicion en el array.
*
*/
int findEmployeeById(sEmployee listado[], int len,int id);


/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
*
* \param listado[] sEmployee Array de lista de empleados.
* \param len int Longitud del array del listado.
* \param id int Id del empleado.
* \return int Return Retorna -1 si hay algun error, sino 0.
*
*/
int removeEmployee(sEmployee listado[], int len, int id);


/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param listado[] sEmployee Array de lista de empleados.
* \param len int Longitud del array del listado.
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return Retorna -1 si hay algun error, sino 0.
*
*/
int sortEmployees(sEmployee listado[], int len, int order);


/** \brief Imprime el listado de empleados.
*
* \param listado[] sEmployee Array de lista de empleados.
* \param len int Longitud del array del listado.
* \return int  Return Retorna -1 si hay algun error, sino 0.
*
*/
int printEmployees(sEmployee listado[], int len);

/** \brief Imprime
 *
 * \param listado[] sEmployee Lista de empleados.
 * \return void
 *
 */
void printEmployee(sEmployee listado[]);

/** \brief
 *
 * \param listado[] sEmployee Array de lista de empleados.
 * \param len int Longitud del array del listado.
 * \param id int legajo del empleado.
 * \return int  Return Retorna -1 si hay algun error, sino 0.
 *
 */
int findEmptyEmployee(sEmployee listado[], int len,int id);

/** \brief
 *
 * \param listado[] sEmployee Array de lista de empleados.
 * \param len int Longitud del array del listado.
 * \return int Return Retorna -1 si hay algun error, sino 0.
 *
 */
int EmptyEmployeeList(sEmployee listado[], int len);

/** \brief
 *
 * \param listado[] sEmployee Lista de empleados.
 * \return void
 *
 */
void mostrarEmployee(sEmployee oneEmployee);

/** \brief
 *
 * \param listado[] sEmployee Array de lista de empleados.
 * \param len int Longitud del array del listado.
 * \return int Return Retorna -1 si hay algun error, sino 0.
 *
 */
int modificarEmployee(sEmployee listado[], int len);

/** \brief
 *
 * \param listado[] sEmployee Lista de empleados.
 * \param len int Longitud del array del listado.
 * \return int Return Retorna -1 si hay algun error, sino 0.
 *
 */
int printEmployeeSalary(sEmployee listado[], int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
