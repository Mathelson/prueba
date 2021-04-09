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

void activarFlag(int* pFlag);//tiro un flag y lo pasa a 1
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
 * \return void
 *
 */
void resetFlag(int* pFlag);

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

           // printf("INGRESE EL 1er OPERADOR A = X: ");
           //     fflush(stdin);
          //   scanf("%d",&numeroA);
                numeroA = getInt("INGRESE EL 1er OPERADOR A = X: ");
                activarFlag(&flagPrimerNumero);
                system("pause");
                break;
        case '2':

            if(flagPrimerNumero)
            {

                //printf("INGRESE EL 2do OPERADOR B = Y: ");
                //fflush(stdin);
                //scanf("%d",&numeroB);
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
           else if( flagPrimerNumero && !flagSegundoNumero){

                printf("\nNo se ingreso el segundo numero\n");

          }
          else{
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
    printf("\n{1}- INGRESE 1er NUMERO A = X \n{2} - INGRESAR 2do OPERADOR B = Y \n{3} - MOSTRAR\n{5} - salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    if(opcion>= '1' && opcion<='5')
    {
     opcionCorrecta = opcion;
    }
    else{
        printf("\nopcion invalida");
    }

    return opcionCorrecta;

}
void activarFlag(int* pFlag)
{
    //if(*pFlag != NULL)

        *pFlag =1;




}
void resetFlag(int* pFlag)
{


        *pFlag =0;


}

int getInt(char mensaje[])
{
    char numero[5];
    //int N;
    //int numeroValidado;
    printf("%s\n",mensaje);
    scanf("%s",numero);
    while(validar_numero(numero) == 0)
    {
        printf("Ingrese numeros validos:");
        scanf("%s",numero);
        //printf("Error. Ingrese solo numeros:");
        //scanf("%s",numero);
    }
    return atoi(numero);
}
int validar_numero(char numero [])
{
    int i;
    int auxReturn=1;
    for(i=0; i <strlen(numero); i++)//strlen es la longitud de la cadena que esta entrando
    {
        if(!(isdigit(numero[i])))//si se encuentra en el rango del 47 al 48 en el c{odigo ascii
        {
            auxReturn=0;
        }
    }
    return auxReturn;
}
