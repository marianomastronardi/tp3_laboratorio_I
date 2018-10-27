#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "menu.h"

#define FALSE 0
#define TRUE 1
#define RET_OK 0
#define RET_ERR -1

void initEmpleado(eEmpleado* pEmpleado)
{
    pEmpleado->legajo = 0;
    strcpy(pEmpleado->nombre, "");
    fflush(stdin);
    pEmpleado->sexo = ' ';
    pEmpleado->sueldo = 0.00;
    pEmpleado->fechaIngreso.dia = 1;
    pEmpleado->fechaIngreso.mes = 1;
    pEmpleado->fechaIngreso.anio = 1900;
    pEmpleado->isEmpty = TRUE;
}

void initEmpleados(eEmpleado* pEmpleado, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        pEmpleado->legajo = 0;
        strcpy(pEmpleado->nombre, "");
        fflush(stdin);
        pEmpleado->sexo = ' ';
        pEmpleado->sueldo = 0.00;
        pEmpleado->fechaIngreso.dia = 1;
        pEmpleado->fechaIngreso.mes = 1;
        pEmpleado->fechaIngreso.anio = 1900;
        pEmpleado->isEmpty = TRUE;
        pEmpleado++;
    }
}

void altaEmpleado(eEmpleado* pEmpleado)
{
    char cNombre[20];

    do
    {
        printf("\nIngrese el Legajo: ");
        scanf("%d", &pEmpleado->legajo);
        if(pEmpleado->legajo <= 0)
        {
            printf("\nLegajo incorrecto. Debe ser mayor a 0.\n");
        }
    }
    while(pEmpleado->legajo <= 0);

    fflush(stdin);
    printf("\nIngrese el Nombre: ");
    scanf("%s", cNombre);
    strcpy(pEmpleado->nombre, cNombre);

    do
    {
        fflush(stdin);
        printf("\nIngrese un sexo: ");
        scanf("%c", &pEmpleado->sexo);
    }
    while(validarSexo(pEmpleado->sexo) == RET_ERR);

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

    do
    {
        opcion = subMenu();

        switch(opcion)
        {
        case 1:
            printf("\nIngrese un Nombre: ");
            fflush(stdin);
            scanf("%s", cNombre);
            strcpy(pEmpleado->nombre, cNombre);
            break;

        case 2:
            do
            {
                fflush(stdin);
                printf("\nIngrese el sexo: ");
                scanf("%c", &pEmpleado->sexo);
            }
            while(validarSexo(pEmpleado->sexo) == RET_ERR);
            break;

        case 3:
            printf("\nIngrese el sueldo: ");
            scanf("%f", &pEmpleado->sueldo);
            break;

        case 4:
            printf("\nIngrese el dia de la Fecha de Ingreso: ");
            scanf("%d", &pEmpleado->fechaIngreso.dia);

            printf("\nIngrese el mes de la Fecha de Ingreso: ");
            scanf("%d", &pEmpleado->fechaIngreso.mes);

            printf("\nIngrese el anio de la Fecha de Ingreso: ");
            scanf("%d", &pEmpleado->fechaIngreso.anio);
            break;

        default:
            break;
        }
    }
    while(opcion < 1 || opcion > 4);
}

eEmpleado* getFreeEmployee(eEmpleado* pEmpleado, int tam)
{
    eEmpleado* rEmpleado;

    for(int i = 0; i < tam; i++)
    {
        if(pEmpleado->isEmpty == TRUE)
        {
            rEmpleado = pEmpleado;
            break;
        }
        pEmpleado++;
    }
    return rEmpleado;
}

void mostrarEmpleado(eEmpleado* pEmpleado)
{
    system("cls");
    printf("\nLegajo            Nombre              Sexo    Sueldo  Fecha Ingreso");
    printf("\n-------------------------------------------------------------------");
    fflush(stdin);
    printf("\n%4d   %20s      %c      %.2f    %2d/%2d/%4d", pEmpleado->legajo, pEmpleado->nombre, pEmpleado->sexo, pEmpleado->sueldo, pEmpleado->fechaIngreso.dia, pEmpleado->fechaIngreso.mes, pEmpleado->fechaIngreso.anio);
}

void mostrarEmpleados(eEmpleado* pEmpleado, int tam)
{
    system("cls");
    printf("\nLegajo            Nombre        Sexo    Sueldo  Fecha Ingreso");
    printf("\n-------------------------------------------------------------");
    for(int i = 0; i < tam; i++)
    {
        if(pEmpleado->isEmpty == FALSE)
        {
            fflush(stdin);
            printf("\n%4d   %20s      %c      %.2f    %2d/%2d/%4d", pEmpleado->legajo, pEmpleado->nombre, pEmpleado->sexo, pEmpleado->sueldo, pEmpleado->fechaIngreso.dia, pEmpleado->fechaIngreso.mes, pEmpleado->fechaIngreso.anio);
        }
        pEmpleado++;
    }
}


int validarSexo(char sexo)
{
    int r = RET_ERR;

    if(sexo == 'f' || sexo == 'm')
    {
        r = RET_OK;
    }
    return r;
}

int hayEmpty(eEmpleado* pEmpleado, int tam)
{
    int r = RET_ERR;

    for(int i = 0; i < tam; i++)
    {
        if(pEmpleado->isEmpty == TRUE)
        {
            r = RET_OK;
            break;
        }
        pEmpleado++;
    }
    if(r == RET_ERR)
    {
        printf("\nNo hay espacios vacios en el Vector");
    }
    return r;
}

int existeLegajo(eEmpleado* pEmpleado, int tam)
{
    int r = FALSE;
    int leg = 0;

    printf("\nIngrese un Legajo: ");
    scanf("%d", &leg);

    for(int i = 0; i < tam; i++)
    {
        if(pEmpleado->legajo == leg)
        {
            r = leg;
            break;
        }
        pEmpleado++;
    }
    if(r == FALSE)
    {
        printf("\nNo existe el legajo ingresado");
    }
    return r;
}

eEmpleado* getEmployee(eEmpleado* pEmpleado, int tam, int leg)
{
    eEmpleado* r;

    for(int i = 0; i < tam; i++)
    {
        if(pEmpleado->legajo == leg)
        {
            r = pEmpleado;
            break;
        }
        pEmpleado++;
    }
    return r;
}
