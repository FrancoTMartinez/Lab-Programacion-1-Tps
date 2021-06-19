#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas, int sueldo);
Employee* employee_addEmployee(int id);
int employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_setNombreFromTxt(Employee* this,char* nombre);
char* employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_compareById(void* emp1, void* emp2);
int employee_compareByName(void* emp1, void* emp2);
int employee_compareByWorkdHours(void* emp1, void* emp2);
int employee_compareBySalary(void* emp1, void* emp2);


#endif // employee_H_INCLUDED
