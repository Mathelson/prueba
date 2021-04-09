#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


int getInt(char mensaje[]);
int validar_numero(char numero [] );
int main()
{

    int numero;

    numero = getInt("Ingrese un numero");

    printf("el numero ingresado es %d",numero);

    return 0;
}
int validar_numero(char numero [])
{
    int i;
    int auxReturn=1;

    for(i=0; i <strlen(numero); i++)//strlen es la longitud de la cadena que esta entrando

    {
        if(!(isdigit(numero[i])))//si se encuentra en el rango del 47 al 48 en el c{odigo ascii
        {

            printf("ERROR Ingresa solo numeros\n");
            system("pause");
            auxReturn=0;

        }


    }

    return auxReturn;

}
int getInt(char mensaje[])
{

    char numero[5];
    int N;
    int numeroValidado;

    do
    {
        printf("%s\n",mensaje);
        scanf("%s",numero);
        N = validar_numero(numero);
       /**que devuelve n*/
        printf("N VALE  = %d",N);
        system("pause");


    }
    while(N==0);
    printf("N VALE = %d");
    system("pause");

    return numeroValidado=atoi(numero);

}
