#include <stdio.h>
#include <stdlib.h>
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeDeError, char minimo, char maximo, int reintentos);
int main()
{


    return 0;
}
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeDeError, char minimo, char maximo, int reintentos)
{
    int retorno = -1;
    char buffer;
    //siempre hay que tomar como negativo lo que recibimos...
    //3 parametros para punteros tiene direccion de memoria !=NULL
    if (pResultado != NULL && mensaje != NULL && mensajeDeError != NULL && minimo <= maximo && reintentos >=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%c",&buffer);
            if(buffer >= minimo && buffer <=maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                /**break;*/
            }
            else//con el break esto se va al igual que sus corchetes
            {
                printf("%s", mensajeDeError);
                reintentos--;
            }
        }while(reintentos>=0);

    }
    return retorno;
}
