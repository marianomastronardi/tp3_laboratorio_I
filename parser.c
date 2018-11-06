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
<<<<<<< HEAD
    int qty;
=======

    //int id, ht, sueldo;
    //char name[20];
    int line = 0;
>>>>>>> bfca7783021e5b6261b8d4fbe3e632148adbe18d

    if(pFile != NULL)
    {
        do
        {
<<<<<<< HEAD
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
=======

                Employee* e = employee_new();
                fread(e, sizeof(Employee), 1, pFile);
                //e->id = id;
                //strcpy(e->nombre, name);
                //e->horasTrabajadas = ht;
                //e->sueldo = sueldo;
                ll_add(pArrayListEmployee, e);
                line++;

>>>>>>> bfca7783021e5b6261b8d4fbe3e632148adbe18d
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

