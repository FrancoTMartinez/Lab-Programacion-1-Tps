#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

Employee* employee_new(){
	return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(int id,char* nombre,int horasTrabajadas, int sueldo){
	Employee* auxEmployee= employee_new();
	if(auxEmployee!=NULL){
		//
		if( employee_setId(auxEmployee, id)<0 ||
			employee_setNombreFromTxt(auxEmployee, nombre) <0 ||
			employee_setHorasTrabajadas(auxEmployee, horasTrabajadas) <0 ||
			employee_setSueldo(auxEmployee, sueldo) <0 ){

			employee_delete(auxEmployee);
			auxEmployee=NULL;
		}
	}
	return auxEmployee;
}
Employee* employee_addEmployee(int id){

    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* pAuxEmployee= employee_new();

		if(!utn_isValidName(nombre,128,"Enter your name: ","Error") &&
		   !utn_getInt(&horasTrabajadas,"Enter worked hours: ","Error",0,5000,3) &&
		   !utn_getInt(&sueldo,"Enter salary: ","Error",0,100000,3)){
				printf("\n----Tomo datos-----");

			if( !employee_setId(pAuxEmployee, id) &&
				!employee_setNombre(pAuxEmployee, nombre) &&
				!employee_setHorasTrabajadas(pAuxEmployee, horasTrabajadas) &&
				!employee_setSueldo(pAuxEmployee, sueldo)){
				printf("\n----seteo datos-----");
				return pAuxEmployee;
			}
		}
	return NULL;
}
int employee_delete(Employee* this){
	if(this!=NULL){
		free(this);
		return 0;
	}
	return 1;
}

int employee_setId(Employee* this,int id){
	int retorno = -1;
	if(this != NULL && id>0) //&& !utn_isHoras(horasTrabajadas)
	{
		this->id= id;
		retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id){
	int retorno = -1;
	if(this != NULL){
		*id= this->id;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL && !ValidateName(nombre))
	{
		strncpy(this->nombre,nombre,128);
		retorno = 0;
	}
	return retorno;
}
int employee_setNombreFromTxt(Employee* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL && !utn_isValidString(nombre))
	{
		strncpy(this->nombre,nombre,128);
		retorno = 0;
	}
	return retorno;
}
char* employee_getNombre(Employee* this,char* nombre){

	char* auxNombre= NULL;
	if(this != NULL)
	{
		strncpy(auxNombre,this->nombre,128);
	}
	return auxNombre;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno = -1;
	if(this != NULL && horasTrabajadas>0) //&& !utn_isHoras(horasTrabajadas)
	{
		this->horasTrabajadas= horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = -1;
	if(this != NULL){
		*horasTrabajadas= this->horasTrabajadas;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
	int retorno = -1;
	if(this != NULL && sueldo >0 )//&& !utn_isInt(sueldo)
	{

		this->sueldo= sueldo;

		retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno = -1;
	if(this != NULL)
	{
		*sueldo= this->horasTrabajadas;
	}
	return retorno;
}

int employee_compareById(void* emp1, void* emp2){
	int retorno;

    if(((Employee*)emp1)->id > ((Employee*)emp2)->id){
        retorno=1;
    }else if(((Employee*)emp1)->id < ((Employee*)emp2)->id){
        retorno=-1;
    }else{
    retorno =0;
    }

    return retorno;
}
int employee_compareByName(void* emp1, void* emp2){
	int ret=-1;
	Employee* employee1=NULL;
	Employee* employee2=NULL;

	employee1=(Employee*)emp1;
	employee2=(Employee*)emp2;

	char nombreA[128];
	char nombreB[128];

	employee_getNombre(employee1, nombreA);
	employee_getNombre(employee2, nombreB);
	if(strcmp(nombreA,nombreB)>0){
		ret=1;
	}

	return ret;
}
int employee_compareByWorkdHours(void* emp1, void* emp2){
	int retorno;

    if(((Employee*)emp1)->horasTrabajadas > ((Employee*)emp2)->horasTrabajadas){
        retorno=1;
    }else if(((Employee*)emp1)->horasTrabajadas < ((Employee*)emp2)->horasTrabajadas){
        retorno=-1;
    }else{
    retorno =0;
    }

    return retorno;

}
int employee_compareBySalary(void* emp1, void* emp2){

	int retorno;

    if(((Employee*)emp1)->sueldo > ((Employee*)emp2)->sueldo){
        retorno=1;
    }else if(((Employee*)emp1)->sueldo < ((Employee*)emp2)->sueldo){
        retorno=-1;
    }else{
    retorno =0;
    }

    return retorno;
}
