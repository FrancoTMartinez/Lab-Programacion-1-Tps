/*
 * serializer.c
 *
 *  Created on: Jun 8, 2021
 *      Author: franco
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

int serializer_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee){
	Employee* pEmployee;
	int lenList;
	int flag=1;

	lenList=ll_len(pArrayListEmployee);

	fprintf(pFile,"Id,Nombre,HorasTrabajadas,Sueldo");
	for(int i=0; i<lenList;i++){
		pEmployee= ll_get(pArrayListEmployee, i);
		if(pEmployee!=NULL){
			fprintf(pFile,"\n%d,%s,%d,%d",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
			flag=0;
		}
	}
	return flag;
}
int serializer_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee){
	Employee* pEmployee;
	int lenList;
	int flag=1;

	lenList=ll_len(pArrayListEmployee);

	for(int i=0; i<lenList;i++){
		pEmployee= ll_get(pArrayListEmployee, i);
		if(pEmployee!=NULL){
			fwrite(pEmployee,sizeof(Employee),1,pFile);
			flag=0;
		}
	}
	return flag;
}
