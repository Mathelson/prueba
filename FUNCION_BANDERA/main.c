#include <stdio.h>
#include <stdlib.h>

/**
hola! el error ese que me decis es porque *pFlag contiene el valor de la bandera (un entero),
para verificar que el puntero a la bandera no sea null el asterisco no va, seria solo pFlag!=null,
porque lo que estas verificando es que la direccion de memoria no sea null. Si arreglas eso el segundo codigo que me pasaste deberia funcionar bien.
Avisame si asi si te funciona. Entendiste mas o menos lo de null? Osea, se usa para ver que las direcciones de memoria no sean null,
al pasar un puntero vos pasas una direccion de memoria, pero cuando tenes una variable de tipo int lo del null no va



*/

/** \brief
 *
 * \param pFlag int*
 * \return void
 *
 */
void resetFlag(int* pFlag);
/** \brief  Pone a 1 el valor de una bandera
 *
 * \param pFlag int* referencia a la bandera
 * \param
 * \return  void
 *
 */
void activarFlag(int* pFlag);//
int main()
{
    int flagPrimerNumero=0;//flagPrimerNumero=0;
    resetFlag(&flagPrimerNumero);
    printf(" FLAG RESET %d\n ",flagPrimerNumero);
    activarFlag(&flagPrimerNumero);
    printf(" FLAG AVTIVAR %d\n ",flagPrimerNumero);
    return 0;
}
void resetFlag(int* pFlag)
{
    if(pFlag!=NULL)//verifico que la direccion de memoria sea !=NULL y no el VALOR!
    {
        *pFlag=0;
    }
}
void activarFlag(int* pFlag)
{
    if(pFlag != NULL)
    {
        *pFlag = 1;
    }
}
