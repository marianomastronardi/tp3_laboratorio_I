#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
int legajo;
char nombre[20];
char apellido[20];
char sexo;
float sueldo;
eFecha fechaIngreso;
int isEmpty;
}eEmpleado;

void initEmpleado(eEmpleado* pEmpleado);
void altaEmpleado(eEmpleado* pEmpleado);
void bajaEmpleado(eEmpleado* pEmpleado);

#endif // EMPLEADO_H_INCLUDED
