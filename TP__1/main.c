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
//FALTA VALIDAR QUE SEA MAYOR A 0
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

int main()
{
    char seguir ='s';
    char confirma;

    float numeroA;
    float numeroB;
    float resSuma;
    float resResta;
    float resDiv;
    float resMulti;
    float factorialA;

    int flagPrimerNumero;
    int flagSegundoNumero;
    int flagCalcular;


    resetFlag(&flagCalcular);
    resetFlag(&flagPrimerNumero);
    resetFlag(&flagSegundoNumero);

    do
    {


        switch(menu())
        {

        case '1':
            numeroA = getFloat("INGRESE EL 1er OPERADOR A = X: ");
            activarFlag(&flagPrimerNumero);
            system("pause");
            break;
        case '2':

            if(flagPrimerNumero)
            {

                numeroB = getFloat("INGRESE EL 2do OPERADOR B = Y: ");
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
        case'3':
            printf("se hicieron los calculos correspondientes\n");

            resSuma=sumar(numeroA,numeroB);
            resResta=restar(numeroA,numeroB);
            resDiv=dividir(numeroA,numeroB);
            resMulti=multiplicar(numeroA,numeroB);
            factorialA=factorialRec(numeroA);

            activarFlag(&flagCalcular);

            system("pause");
            break;
        case '4':
            if(!flagPrimerNumero)
            {
                printf("\nNo se ingreso ningun numero\n");
            }
            else if( flagPrimerNumero && !flagSegundoNumero)
            {

                printf("\nNo se ingreso el segundo numero\n");

            }
            else
            {
                printf("A = %.2f\n",numeroA);
                printf("B = %.2f\n",numeroB);
                if(flagCalcular)
                {
                    muestraResultados(resSuma,resResta,resDiv,resMulti,numeroA,factorialA);
                    resetFlag(&flagPrimerNumero);
                    resetFlag(&flagSegundoNumero);
                }
                else{
                    printf("NO REALIZO EL CALCULO");
                }

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
float getFloat(char mensaje[])
{
    char numero[5];
    printf("%s\n",mensaje);
    scanf("%s",numero);
    while(validar_numero(numero) == 0)
    {
        printf("Ingrese numeros validos:");
        scanf("%s",numero);
    }
    return atof(numero);
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
    else
    {
        fac = n * factorialRec( n-1);
    }
    return fac;
}

float dividir (float numA,float numB)
{
    float auxReturn=0.0;
    if(numB!=0)
    {
        float resDivide=numA/numB;
        auxReturn = resDivide;
    }
    return auxReturn;
}
float sumar(float numA,float numB)
{
    float resSuma=numA+numB;
    return resSuma;
}
float restar(float numA,float numB)
{
    float resResta=numA-numB;
    return resResta;

}
float multiplicar(float numA,float numB)
{
    float resMultiplicar=numA*numB;
    return resMultiplicar;

}

/***************************************************/
void muestraResultados(float resSuma,float resResta, float resDiv, float resMulti, float numeroA, float factorialA)
 {

        printf("\nEl resultado de la suma es %.2f: \n ",resSuma);
        printf("\nEl resultado de la resta es es %.2f: \n ",resResta);
        if(resDiv == 0.0)
        {
            printf("\nNo es posible dividir por cero\n\n");
        }
            else
        {
            printf("\nEl resultado de la div es %.2f \n ",resDiv);
        }
            printf("\nEl resultado de la multiplicacion es %.2f \n ",resMulti);
        if(numeroA>0)
        {
        printf("\nEl factorial de (A!) = %.1f es %.1f \n",numeroA,factorialA);
        }
        else
        {
        printf("\nPara (A!) = el numero debe ser mayor a 0\n");
        }
}
