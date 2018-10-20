#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int menu()
{
    int opcion;
    system("cls");
    printf("\n**********   Menu de opciones   **********\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    scanf("%d", &opcion);
    return opcion;
}

int subMenu()
{
    int opcion;
    system("cls");
    printf("\nElija una opcion a modificar\n");
    printf("1. Nombre");
    printf("2. Apellido");
    printf("3. Sexo");
    printf("4. Sueldo");
    printf("5. Fecha de Ingreso");
    scanf("%d", &opcion);
    return opcion;
}
