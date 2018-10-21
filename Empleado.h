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
void initEmpleados(eEmpleado* pEmpleado, int tam);
void altaEmpleado(eEmpleado* pEmpleado);
void bajaEmpleado(eEmpleado* pEmpleado);
void editEmpleado(eEmpleado* pEmpleado);
eEmpleado* getFreeEmployee(eEmpleado* pEmpleado, int tam);
void mostrarEmpleado(eEmpleado* pEmpleado);
void mostrarEmpleados(eEmpleado* pEmpleado, int tam);
int validarSexo(char sexo);
int hayEmpty(eEmpleado* pEmpleado, int tam);
int existeLegajo(eEmpleado* pEmpleado, int tam, int leg);
eEmpleado* getEmployee(eEmpleado* pEmpleado, int tam);

#endif // EMPLEADO_H_INCLUDED
