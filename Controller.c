#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "menu.h"
#define RET_OK 1
#define RET_ERR 0

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;
    FILE* pFile = fopen(path, "r");

    if(pFile == NULL)
    {
        printf("\nEl archivo no existe.\n");
    }
    else
    {
        r = ll_clear(pArrayListEmployee);
        r = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }

    return r;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;
    FILE* pFile = fopen(path, "rb");

    if(pFile == NULL)
    {
        printf("\nEl archivo no existe.\n");
    }
    else
    {
        r = ll_clear(pArrayListEmployee);
        r = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }

    return r;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* e = employee_new();
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int r = RET_ERR;

    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        printf("Ingrese un ID \n");
        scanf("%d", &id);
        r = employee_setId(e,id);

        printf("Ingrese un Nombre \n");
        scanf("%s", nombre);
        r = employee_setNombre(e,nombre);

        printf("Ingrese Horas Trabajadas \n");
        scanf("%d", &horasTrabajadas);
        r = employee_setHorasTrabajadas(e, horasTrabajadas);

        printf("Ingrese un Sueldo \n");
        scanf("%d", &sueldo);
        r = employee_setSueldo(e, sueldo);

        r = ll_add(pArrayListEmployee, e);
    }

    return r;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;
    int idEmployee = 0;
    int idEmployeeEdit = 0;
    void* aux = employee_new();
    char name[20];
    int ht = 0;
    int sueldo = 0;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese un ID\n");
        scanf("%d", &idEmployeeEdit);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = ll_get(pArrayListEmployee, i);

            r = employee_getId((Employee*) aux, &idEmployee);

            if(r == RET_OK)
            {
                if(idEmployee == idEmployeeEdit)
                {
                    switch(mostrarMenuEdit())
                    {
                    case 1:

                        printf("Ingrese un nombre.\n");
                        scanf("%s", name);
                        r = employee_setNombre((Employee*)aux, name);
                        break;
                    case 2:

                        do
                        {
                            printf("Ingrese Horas Trabajadas\n");
                            scanf("%d", &ht);
                            r = employee_setHorasTrabajadas((Employee*) aux, ht);
                        }
                        while(ht < 0);
                        break;
                    case 3:

                        do
                        {
                            printf("Ingrese Sueldo\n");
                            scanf("%d", &sueldo);
                            r = employee_setSueldo((Employee*) aux, sueldo);
                        }
                        while(sueldo < 0);
                        break;
                    default:
                        break;
                    }

                    if(r == RET_ERR)
                    {
                        printf("\nProblemas pata modificar el campo.\n");
                    }

                    r = ll_set(pArrayListEmployee, i, aux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;
    int idEmployee;
    int idEmployeeRemove;
    Employee* aux = employee_new();

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese un ID\n");
        scanf("%d", &idEmployeeRemove);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee, i);

            r = employee_getId(aux, &idEmployee);

            if(r == RET_OK)
            {
                if(idEmployee == idEmployeeRemove)
                {
                    r = ll_remove(pArrayListEmployee, i);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
    }

    return r;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;
    Employee* emp = employee_new();
    int l = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        printf("ID    Nombre        Hs Trab.  Sueldo\n");
        for(int i = 0; i < l; i++)
        {
            emp = (Employee*) ll_get(pArrayListEmployee, i);
            employee_show(emp);
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
    }
    return r;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int order;
    int r;

    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        opcion = menuSort();
        order = menuAscDesc();

        switch(opcion)
        {
        case 1:

            r = ll_sort(pArrayListEmployee, employee_sortById, order);
            break;

        case 2:
            r = ll_sort(pArrayListEmployee, employee_sortByName, order);
            break;

        case 3:
            r = ll_sort(pArrayListEmployee, employee_sortByWorkHours, order);
            break;

        case 4:
            r = ll_sort(pArrayListEmployee, employee_sortBySalary, order);
            break;
        }
    }

    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;
    int lon;
    FILE *pFile = fopen(path,"w");

    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        Employee* pEmployee = employee_new();
        if(pFile==NULL)
        {
            printf("Archivo inexistente\n");
        }
        else
        {
            lon = ll_len(pArrayListEmployee);
            for(int i = 0; i < lon; i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

                fprintf(pFile, "%d, %s, %d, %d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);    //Se escribe al archivo

            }
            r = RET_OK;
            fclose(pFile);
        }
    }

    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int r = RET_ERR;
    int qty = 0;
    int lon;

    FILE *pFile = fopen(path,"wb");

    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        Employee* pEmployee = employee_new();
        if(pFile==NULL)
        {
            printf("Archivo inexistente\n");
        }
        else
        {
            lon = ll_len(pArrayListEmployee);

            for(int i = 0; i < lon; i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

                qty = fwrite(pEmployee, sizeof(Employee), 1, pFile );    //Se escribe al archivo

                if(qty != 1)
                {
                    printf("\nError al escribir el archivo");
                }
            }
            r = RET_OK;
            fclose(pFile);
        }
    }

    return r;
}

