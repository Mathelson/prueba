#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

//en el mostrar me tiene que poder mostrar si se hicieron todas las operaciones;
//se puede decir que no hay ningun resultado para mostrar si SUMA=1
/**EL 3 ES MOSTRAR, PUEDE SER QUE MOSTRAR NOS DIGA QUE FALTO Y LISTO = INFORMAR RESULTADOS*/

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

/** \brief Retorna el numero Ingresado o de lo contrario muestra un mensaje de Error.
 *
 * \param mensaje[] char El mensaje a ser mostrado.
 * \return int retorna el numero solicitado ya validado;
 *
 */
int getInt(char mensaje[]);

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
//FALTA VALIDAR QUE SEA MAYOR A 0
int factorialRec(int n);
/**
*\brief Pide 2 numeros al Usuario.
*\param Si uno de los numeros ingresados es distinto de cero, realiza la divicion.
*\param realiza la divicion.
*\return El resultado de la divicion.
*\param si un numero ingresado es igual a cero.
*\return Retorna 0.0.
*/
//REVISAR QUE EL RETORNO SEA DISTINTO
float dividir (float numA,float numB);

int main()
{
    char seguir ='s';
    char confirma;

    int numeroA;
    int numeroB;
    int flagPrimerNumero;
    int flagSegundoNumero;


    resetFlag(&flagPrimerNumero);
    resetFlag(&flagSegundoNumero);

    do
    {


        switch(menu())
        {

        case '1':
            numeroA = getInt("INGRESE EL 1er OPERADOR A = X: ");
            activarFlag(&flagPrimerNumero);
            system("pause");
            break;
        case '2':

            if(flagPrimerNumero)
            {

                numeroB = getInt("INGRESE EL 2do OPERADOR B = Y: ");
                system("pause");
                activarFlag(&flagSegundoNumero);
                break;


            }
            else
            {
                printf("\nAntes de ingresar el segundo numero debe Ingresar el 1ro\n");
            }
            system("pause");
            break;
        case '3':
            if(!flagPrimerNumero)
            {
                printf("No se ingreso ningun numero");
            }
            else if( flagPrimerNumero && !flagSegundoNumero)
            {

                printf("\nNo se ingreso el segundo numero\n");

            }
            else
            {
                printf("A = %d\n",numeroA);
                printf("B = %d\n",numeroB);
                resetFlag(&flagPrimerNumero);
                resetFlag(&flagSegundoNumero);
            }


            system("pause");
            break;

        case '5':
            printf("confirma salida? S/N\n");
            fflush(stdin);
            confirma= getchar();
            if(confirma == 's')
            {
                seguir='n';
            }

            break;

        default:
            printf("opcion invalida!\n");
            system("pause");

        }


    }
    while( seguir =='s');

    return 0;
}
char menu ()
{
    char opcion;
    char opcionCorrecta;

    system("cls");
    printf("         *** Menu de Opciones ***\n\n");
    printf("\n{1} - INGRESE 1er NUMERO A = X \n{2} - INGRESAR 2do OPERADOR B = Y");
    printf("\n{3} - CALCULAR TODAS LAS OPERACIONES\n");
    printf("   a) Calcular la suma (A+B)\n");
    printf("   b) Calcular la resta (A-B)\n");
    printf("   c) Calcular la division (A/B)HECHO\n");
    printf("   d) Calcular la multiplicacion (A*B)\n");
    printf("   e) Calcular el factorial (A!)\nHECHO");
    printf("\n{4} - INFORMAR RESULTADOS:\n");
    printf("   a) El resultado de A+B es: r\n");
    printf("   b) El resultado de A-B es: r\n");
    printf("   c) El resultado de A/B es: r o No es posible dividir por cero\n");
    printf("   d) El resultado de A*B es: r\n");
    printf("   e) El factorial de A es: r1 y El factorial de B es: r2\n");
    printf("\n{5} - SALIR\n");


    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    if(opcion>= '1' && opcion<='5')
    {
        opcionCorrecta = opcion;
    }
    else
    {
        printf("\nopcion invalida");
    }

    return opcionCorrecta;

}
int activarFlag(int* pFlag)
{
    int todoOk = 0;
    if(pFlag != NULL)
    {
        *pFlag =1;
        todoOk=1;
    }

    return todoOk;
}
int resetFlag(int* pFlag)
{
    int todoOk = 0;
    if(pFlag != NULL)
    {
        *pFlag =0;
        todoOk=1;
    }

    return todoOk;
}

int getInt(char mensaje[])
{
    char numero[5];
    printf("%s\n",mensaje);
    scanf("%s",numero);
    while(validar_numero(numero) == 0)
    {
        printf("Ingrese numeros validos:");
        scanf("%s",numero);
    }
    return atoi(numero);
}
int validar_numero(char numero [])
{
    int i;
    int auxReturn=1;
    for(i=0; i <strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            auxReturn=0;
        }
    }
    return auxReturn;
}
int factorialRec(int n)
{
    int fac;
    if(n==1 || n==0)
    {
        fac=1;

    }
    else{
        fac = n * factorialRec( n-1);
        }
    return fac;
}

float dividir (float numA,float numB)
{
    if(numB!=0){
        float resDivide=numA/numB;
        return resDivide;
        }else{

            return 0.0;
        }
}
