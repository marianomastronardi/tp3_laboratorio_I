#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "menu.h"

#define FALSE 0
#define TRUE 1

void initEmpleado(eEmpleado* pEmpleado)
{
    pEmpleado->legajo = 0;
    strcpy(pEmpleado->nombre, "");
    strcpy(pEmpleado->apellido, "");
    pEmpleado->sexo = ' ';
    pEmpleado->sueldo = 0.00;
    pEmpleado->fechaIngreso.dia = 1;
    pEmpleado->fechaIngreso.mes = 1;
    pEmpleado->fechaIngreso.anio = 1900;
    pEmpleado->isEmpty = TRUE;
}

void altaEmpleado(eEmpleado* pEmpleado)
{
    char cNombre[20];
    char cApellido[20];

    printf("\nIngrese el Legajo: ");
    scanf("%d", &pEmpleado->legajo);

    printf("\nIngrese el Nombre: ");
    scanf("%s", cNombre);
    strcpy(pEmpleado->nombre, cNombre);

    printf("\nIngrese el Apellido: ");
    scanf("%s", cApellido);
    strcpy(pEmpleado->apellido, cApellido);

    printf("\nIngrese un sexo: ");
    scanf("%c", &pEmpleado->sexo);

    printf("\nIngrese el Sueldo: ");
    scanf("%f", &pEmpleado->sueldo);

    printf("\nIngrese el dia de la Fecha de ingreso: ");
    scanf("%d", &pEmpleado->fechaIngreso.dia);

    printf("\nIngrese el mes de la Fecha de ingreso: ");
    scanf("%d", &pEmpleado->fechaIngreso.mes);

    printf("\nIngrese el anio de la Fecha de ingreso: ");
    scanf("%d", &pEmpleado->fechaIngreso.anio);

    pEmpleado->isEmpty = FALSE;
}


void bajaEmpleado(eEmpleado* pEmpleado)
{
    pEmpleado->isEmpty = TRUE;
}

void editEmpleado(eEmpleado* pEmpleado)
{
    int opcion;
    char cNombre[20];
    char cApellido[20];

    do
    {
        opcion = subMenu();

        switch(opcion)
        {
        case 1:
            printf("\nIngrese un Nombre: ");
            scanf("%s", cNombre);
            strcpy(pEmpleado->nombre, cNombre);
            break;

        case 2:
            printf("\nIngrese un Apellido: ");
            scanf("%s", cApellido);
            strcpy(pEmpleado->apellido, cApellido);
            break;

        case 3:
            printf("\nIngrese el sexo: ");
            scanf("%c", pEmpleado->sexo);
            break;

        case 4:
            printf("\nIngrese el sueldo: ");
            scanf("%f", pEmpleado->sueldo);
            break;

        case 5:
            printf("\nIngrese el dia de la Fecha de Ingreso: ");
            scanf("%d", pEmpleado->fechaIngreso.dia);

            printf("\nIngrese el mes de la Fecha de Ingreso: ");
            scanf("%d", pEmpleado->fechaIngreso.mes);

            printf("\nIngrese el anio de la Fecha de Ingreso: ");
            scanf("%d", pEmpleado->fechaIngreso.anio);
            break;

        default:
            break;
        }
    }
    while(opcion < 1 || opcion > 5);
}
