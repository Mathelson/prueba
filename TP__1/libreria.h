#ifndef LIBRERIAH
#define LIBRERIAH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>


/** \brief Muestra las opciones de un menu
 *
 * \param
 * \param
 * \return retorna la opcion elegida
 *
 */

char menu ();
/** \brief  Pone a 1 el valor de una bandera
 *
 * \param pFlag int* referencia a la bandera
 * \param
 * \return  void
 *
 */

int activarFlag(int* pFlag);//tiro un flag y lo pasa a 1
/** \brief Pone un 0 a el valor de la vandera
 *
 * \param
 * \param pFlag int* referencia a la vandera;
 * \return
 *
 */

/** \brief
 *
 * \param pFlag int*
 * \return
 *
 */
int resetFlag(int* pFlag);

/** \brief Retorna el numero Ingresado(tipo Entero) o de lo contrario muestra un mensaje de Error.
 *
 * \param mensaje[] char El mensaje a ser mostrado.
 * \return int retorna el numero solicitado ya validado;
 *
 */
int getInt(char mensaje[]);
/** \brief Retorna el numero Ingresado (tipoFlotante) o de lo contrario muestra un mensaje de Error.
 *
 * \param mensaje[] char El mensaje a ser mostrado.
 * \return float retorna el numero solicitado ya validado;
 *
 */
float getFloat(char mensaje[]);

/** \brief Valida que lo que haya ingresado el usuario sea un numero
 *
 * \param [] char numero toma el numero como string para luego recorrerlo
 * \return int Retorna un 1 si lo ingresado es un numero y un 0 si no lo es
 *
 */
int validar_numero(char numero []);
/** \brief Funcion Factorial
 *
 * \param n int numero a Factorizar
 * \return int numero Factorizado
 *
 */
int factorialRec(int n);
/**
*\brief Pide 2 numeros al Usuario.
*\param Si uno de los numeros ingresados es distinto de cero, realiza la división.
*\param realiza ladivisión.
*\return El resultado de la división.
*\param si un numero ingresado es igual a cero.
*\return Retorna 0.0.
*/

float dividir (float numA,float numB);

/**
*\brief Pide 2 numeros al Usuario.
*\param Realiza la suma entre los numeros ingresados.
*\return El resultado de la suma.
*
*/
float sumar(float numA,float numB);

/**
*\brief Pide 2 numeros al Usuario.
*\param Realiza la resta entre los numeros ingresados.
*\return El resultado de la resta.
*
*/
float restar(float numA,float numB);

/**
*\brief Pide 2 numeros al Usuario.
*\param Realiza la multiplicacion entre los numeros ingresados.
*\return El resultado de la multiplicacion.
*
*/
float multiplicar(float numA,float numB);
/** \brief MUESTTRA LOS RESULTADOS
 *
 * \param resResta float
 * \param resDiv float
 * \param resMulti float
 * \param numeroA float
 * \param factorialA float
 * \return void
 *
 */
void muestraResultados(float resSuma,float resResta, float resDiv, float resMulti, float numeroA, float factorialA);

#endif // LIBRERIAH
