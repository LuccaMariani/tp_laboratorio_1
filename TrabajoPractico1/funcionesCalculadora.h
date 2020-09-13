#ifndef FUNCIONESCALCULADORA_H_INCLUDED
#define FUNCIONESCALCULADORA_H_INCLUDED


/** \brief Realiza la suma de dos numeros ( x , y ) enteros.
 *
 * \param x int
 * \param y int
 * \return int
 *
 */
int suma(int x,int y);

/** \brief Realiza la resta entre dos numeros ( x , y ) enteros
 *
 * \param x int
 * \param y int
 * \return int
 *
 */
int resta(int x,int y);

/** \brief Realiza la resta entre dos numeros ( x , y ) enteros.
 *
 * \param x float
 * \param y float
 * \return float - Devuelve un
 *
 */
float division(float x,float y);

/** \brief Realiza la multiplicacion entre dos numeros ( x , y ) enteros.
 *
 * \param x int
 * \param y int
 * \return int
 *
 */
int multiplicacion(int x,int y);

/** \brief Realiza el factorial de un numero ( x ) entero.
 *
 * \param x int
 * \return long int
 *
 */
long int factorialX(int x);

/** \brief Realiza el factorial de un numero ( y ) entero.
 *
 * \param y int
 * \return long int
 *
 */
long int factorialY(int y);

/** \brief Imprime en la consola el menu de opciones, con sus
 *         respectivas variaciones dependiendo de los datos ingresados A y B.
 *
 *
 * \param opcionMenu int
 * \param num1 int
 * \param num2 int
 * \return void
 *
 */
void menu(int opcionMenu, int num1, int num2);

#endif // FUNCIONESCALCULADORA_H_INCLUDED
