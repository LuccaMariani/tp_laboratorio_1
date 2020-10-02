#ifndef BIBLIOTECAS_H_INCLUDED
#define BIBLIOTECAS_H_INCLUDED

#include "ArrayEmployees.h"

/** \brief
 *
 * \param opcionMenu int La opcion del menu elegida.
 * \param impresionMenu int La opcin de menu a imprimir.
 * \param listado[] sEmployee Estructura de los empleados.
 * \param order int Orden en el cual se debe ordenar el listado.
 * \return int devuelve la impresion del menu proxima.
 *
 */
int menu2(int opcionMenu, int impresionMenu, sEmployee listado[], int order);

/** \brief
 *
 * \param opcionMenu int La opcion del menu elegida.
 * \param impresionMenu int La opcin de menu a imprimir.
 * \param encendido int Valor del encendido del programa.
 * \param listado[] sEmployee Estructura de los empleados.
 * \param Id int* Lugar donde se encuentra el ID.
 * \return int devuelve la impresion del menu proxima.
 *
 */
int menu1(int opcionMenu, int impresionMenu, int encendido, sEmployee listado[], int* Id);



/** \brief Se encarga de validar la cadena de caracteres.
 *
 * \param cadenaCaracteres[] char es la cadena entrante a validar.
 * \return int devuelve 1 si encuentra un numero, 0 si no.
 *
 */
int validacionCadenaCaracteres(char cadenaCaracteres[]);

#endif // BIBLIOTECAS_H_INCLUDED
