#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "Empleado.h"
#include "LinkedList.h"

#define TAM 10
#define FALSE 0
#define TRUE 1
#define RET_OK 0
#define RET_ERR -1

int main()
{
    int opcion;
    int leg;
    eEmpleado vEmpleado[TAM];
    eEmpleado* pEmpleado;
    char resp;

    pEmpleado = vEmpleado;
    initEmpleado(pEmpleado,TAM);

    do
    {

        do
        {
            opcion = menu();
        }
        while(opcion < 1 || opcion > 10);

        switch(opcion)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            if(hayEmpty(pEmpleado, TAM) == RET_OK)
            {
                pEmpleado = vEmpleado;
                pEmpleado = getFreeEmployee(pEmpleado, TAM);
                altaEmpleado(pEmpleado);
            }
            break;
        case 4:
            printf("\nIngrese un Legajo: ");
            scanf("%d", &leg);
            if(existeLegajo(pEmpleado, TAM, leg) == RET_OK)
            {
                //editEmpleado()
            }
            break;
        case 5:
            printf("\nIngrese un Legajo: ");
            scanf("%d", &leg);
            if(existeLegajo(pEmpleado, TAM, leg) == RET_OK)
            {
                bajaEmpleado(pEmpleado, TAM, leg);
            }
            break;
        case 6:
            mostrarEmpleados(pEmpleado, TAM);
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            break;
        }
        do
        {
            fflush(stdin);
            printf("\nDesea continuar?[s/n] ");
            scanf("%c", &resp);
        }
        while(resp != 's' && resp != 'n');

    }
    while(resp == 's');

    return 0;
}
