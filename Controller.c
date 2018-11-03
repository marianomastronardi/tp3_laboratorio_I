#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
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

    r = parser_EmployeeFromText(pFile, pArrayListEmployee);

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

    r = parser_EmployeeFromText(pFile, pArrayListEmployee);

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

    printf("%d", r);
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
    return 1;
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

    FILE *f;

    if((f=fopen("data.csv","w"))==NULL)
    {
        printf("Archivo inexistente\n");
    }
    else
    {
        f = fopen("data.csv","a");



        fclose(f);
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
    return 1;
}

