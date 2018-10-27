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
    eEmpleado vEmpleado[TAM];
    eEmpleado* pEmpleado;
    int leg;
    char resp;

    pEmpleado = vEmpleado;
    initEmpleados(pEmpleado,TAM);

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
            //ALTA
            if(hayEmpty(pEmpleado, TAM) == RET_OK)
            {
                altaEmpleado(getFreeEmployee(pEmpleado, TAM));
            }
            break;
        case 4:
            //MODI
            leg = existeLegajo(pEmpleado, TAM);
            if(leg != FALSE)
            {
                editEmpleado(getEmployee(pEmpleado, TAM, leg));
            }
            break;
        case 5:
            //BAJA
            leg = existeLegajo(pEmpleado, TAM);
            if(leg != FALSE)
            {
                bajaEmpleado(getEmployee(pEmpleado, TAM, leg));
            }
            break;
        case 6:
            //LISTAR
            mostrarEmpleados(pEmpleado, TAM);
            break;
        case 7:
            //ORDENAR
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            exit(-1);
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
