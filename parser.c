#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#define RET_OK 1
#define RET_ERR 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;
    int qty = 0;
    char idFile[4];
    char name[20];
    char htFile[4];
    char salFile[4];

    if(pFile != NULL)
    {
        do
        {
            qty = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idFile,name,htFile,salFile);

            if(qty!=4)
            {
                printf("\nProblemas para cargar el archivo data.csv\n");
            }
            else
            {
                Employee* pEmployee = employee_new();
                pEmployee->id = atoi(idFile);
                strcpy(pEmployee->nombre, name);
                pEmployee->horasTrabajadas = atoi(htFile);
                pEmployee->sueldo = atoi(salFile);
                ll_add(pArrayListEmployee, pEmployee);
            }

        }
        while(!feof(pFile));
        fclose(pFile);
        r = RET_OK;
    }
    else
    {
        printf("Archivo vacio\n");
    }

    return r;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;
    int qty;

    if(pFile != NULL)
    {
        do
        {
            Employee* pEmployee = employee_new();
            qty = fread(pEmployee,sizeof(Employee), 1, pFile);
            /*if(qty!=4)
            {
                printf("\nProblemas para cargar el archivo data.bin\n");
            }
            else
            {
              */  ll_add(pArrayListEmployee, pEmployee);
           // }
        }
        while(!feof(pFile));
        fclose(pFile);
        r = RET_OK;
    }
    else
    {
        printf("\nArchivo vacio\n");
    }

    return r;
}

