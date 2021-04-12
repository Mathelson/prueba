#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>
#include "libreria.h"


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
