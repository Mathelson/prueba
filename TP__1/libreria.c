#include "libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

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
    printf("   c) Calcular la division (A/B)\n");
    printf("   d) Calcular la multiplicacion (A*B)\n");
    printf("   e) Calcular el factorial (A!)\n");
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
