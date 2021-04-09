#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void pedir_y_mostar_notacion_VECTORIAL();
void pedir_y_mostar_notacion_PUNTERO();
int main()
{
    /**ARITMETICA DE PUNTEROS**/
  /**  int numeros[TAM];//numeros apunta a la primer direccion de memoria
    numeros[0] = 1;//NOTACION VECTORIAL
    numeros[1] = 2;
    numeros[2] = 3;
    //NOTACION DE PUNTEROS
    *(numeros + 4) = 4;
    printf("%d\n", *numeros);
    printf("%d\n", *(numeros + 1));
    printf("%d\n", *(numeros + 2));////de donde comienza la direccion de memoria me muevo 8 bytes 4 + 4
    printf("%d\n", *(numeros + 4));*/

    pedir_y_mostar_notacion_VECTORIAL();
    pedir_y_mostar_notacion_PUNTERO();



    return 0;
}
void pedir_y_mostar_notacion_VECTORIAL()
{
    //int numeros[5];

    int numeros[2];
    printf("\n\n ***NOTACION VECTORIAL*** \n\n");

    printf("Ingrese un numero a vecto: ");
    fflush(stdin);
    scanf("%d\n",&numeros[2]);

    printf("EL NUMERO INGRESADO ES %d",numeros[2]);


}
void pedir_y_mostar_notacion_PUNTERO()
{

    int numeros[4];

    printf("\n\n ***NOTACION PUNTERO** \n\n");

    *(numeros + 4) = 4;//lo harcodeo

    printf(" NUMERO HARCODEADO %d\n", *(numeros + 4));

    printf("Ingrese un numero a puntero: ");
    fflush(stdin);
    scanf("%d", numeros + 4);
    printf("EL NUMERO INGRESADO ES  %d\n", *(numeros + 4));

}
