#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "Empleado.h"
#include "LinkedList.h"

int main()
{
    int opcion;

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
        //altaEmpleado()
        break;
    case 4:
        //editEmpleado()
        break;
    case 5:
        //bajaEmpleado()
        break;
    case 6:
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
    return 0;
}
