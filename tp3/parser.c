#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pAuxEmployee;
	char idStr[50],nombre[128],horasTrabajadasStr[50],sueldoStr[50];
    int id;
	int horasTrabajadas;
    int sueldo;
    int idMax=0;

	if(pFile !=NULL){
		do{

			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombre,horasTrabajadasStr,sueldoStr)==4){
				id=atoi(idStr);
				horasTrabajadas=atoi(horasTrabajadasStr);
				sueldo=atoi(sueldoStr);

				if(id>idMax){
					idMax=id;
				}
			}else{
				break;
			}
				pAuxEmployee=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

				if(pAuxEmployee!=NULL){
					ll_add(pArrayListEmployee, pAuxEmployee);
				}
		}while(!feof(pFile));
		return idMax;
	}
    return -1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pAuxEmployee;
    int idMax=0;

	if(pFile !=NULL){
		do{
			pAuxEmployee=employee_new();

			if(fread(pAuxEmployee,sizeof(Employee),1,pFile)==1){
				ll_add(pArrayListEmployee, pAuxEmployee);

				if(pAuxEmployee->id>idMax){
					idMax=pAuxEmployee->id;
				}
			}else{
				employee_delete(pAuxEmployee);
			}
		}while(!feof(pFile));
		return idMax;
	}
    return -1;
}
