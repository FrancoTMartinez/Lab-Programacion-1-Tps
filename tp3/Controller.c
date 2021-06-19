#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "serializer.h"
#include "utn.h"


int idEmployeeMax=0;
int controller_generateEmployeeId(){
	idEmployeeMax+=1;

	return idEmployeeMax;
}
static Employee* findById(LinkedList* pArrayListEmployee,int idToFind){
	int lenList;
	Employee* pEmployee;
	Employee* pEmployeeReturn=NULL;
	int idFind;

	if(pArrayListEmployee!=NULL){
		lenList= ll_len(pArrayListEmployee);
		for(int i=0;i<lenList;i++){
			pEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(pEmployee, &idFind);

			if(idToFind==idFind){
				pEmployeeReturn=pEmployee;
				break;
			}
		}
	}
	return pEmployeeReturn;
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pListArticulo)
{
	FILE *pFile;
	int retFuncionId;

	pFile=fopen(path,"r");
	if(path !=NULL && pFile!=NULL && pListArticulo!=NULL){

		retFuncionId=parser_EmployeeFromText(pFile, pListArticulo);

		if(retFuncionId>0){
				printf("\nLoaded successfully");
				idEmployeeMax=retFuncionId;

		}
	}
	fclose(pFile);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	int retFuncionId;

	pFile=fopen(path,"rb");
	if(pFile!=NULL && pArrayListEmployee!=NULL && path !=NULL){
		retFuncionId=parser_EmployeeFromBinary(pFile, pArrayListEmployee);

			if(retFuncionId>0){
				printf("\nLoaded successfully");
				idEmployeeMax=retFuncionId;

			}
	}
	fclose(pFile);
    return 1;
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
	Employee* pEmployee;
	int idEmployee= controller_generateEmployeeId();

	pEmployee=employee_addEmployee(idEmployee);

	if(pArrayListEmployee!=NULL && pEmployee!=NULL){
		ll_add(pArrayListEmployee,pEmployee);
		printf("\nEmployee added.");
	}else{
		printf("Error");
	}

    return 1;
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
	int idToModify;
	Employee* pEmployee;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;


	if(pArrayListEmployee!=NULL){
		if(!utn_getInt(&idToModify,"\nEnter an ID to modify: ","Error",0,99999,2)){
			pEmployee= findById(pArrayListEmployee, idToModify);

			if(pEmployee!=NULL){
				if(!utn_isValidName(nombre,128,"\nEnter your name: ","Error") &&
				   !utn_getInt(&horasTrabajadas,"\nEnter worked hours: ","Error",0,5000,3) &&
				   !utn_getInt(&sueldo,"\nEnter salary: ","Error",0,100000,3)){

					if(	!employee_setNombre(pEmployee, nombre) &&
						!employee_setHorasTrabajadas(pEmployee, horasTrabajadas) &&
						!employee_setSueldo(pEmployee, sueldo)){

						printf("\nSuccessfully modified Employee.");
						return 0;
					}
				}
			}
		}
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
	int idToDelete;
	int indexToDelete;
	Employee* pEmployee;

	if(pArrayListEmployee!=NULL){
		if(!utn_getInt(&idToDelete,"\nEnter an ID to remove: ","Error",0,99999,2)){

			pEmployee= findById(pArrayListEmployee, idToDelete);

			if(pEmployee!=NULL){
				indexToDelete= ll_indexOf(pArrayListEmployee, pEmployee);
				if(!ll_remove(pArrayListEmployee, indexToDelete) && employee_delete(pEmployee)){
					printf("\nDeleted.");
				}
			}
		}
	}
    return 1;
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
	Employee* pEmp;
	if(pArrayListEmployee!=NULL){
		printf("\nId, Name, WorkedHours, Salary");
		for(int i=0; i< ll_len(pArrayListEmployee);i++){
			pEmp=ll_get(pArrayListEmployee, i);
			printf("\n%d, %s, %d, %d", pEmp->id,pEmp->nombre,pEmp->horasTrabajadas,pEmp->sueldo);
		}
	}
    return 1;
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
	int option;

	if(pArrayListEmployee){
		printf("\n1-Sort by id."
				"\n2-Sort by name."
				"\n3-Sort by salary"
				"\n4-Sort by Worked Hours."
				"\n5-Cancel,");
		utn_getInt(&option, "\nInsert valid option","Error",1,5,3);
		switch(option){
		case 1:
            ll_sort(pArrayListEmployee, employee_compareById, 1);
            printf("\nSort done");
			break;
		case 2:
			if(!ll_sort(pArrayListEmployee,employee_compareByName,1)){
				printf("\nSort done");
			}else{
				printf("\nNo se porque no funca.Medio raro todo");
			}
			break;
		case 3:
            ll_sort(pArrayListEmployee, employee_compareBySalary, 1);
            printf("\nSort done");
			break;
		case 4:
            ll_sort(pArrayListEmployee, employee_compareByWorkdHours, 1);
            printf("\nSort done");
			break;
		case 5:
			break;
		}
	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;

	pFile=fopen(path,"w+");
	if(pFile!=NULL){
		if(!serializer_EmployeeToText(pFile, pArrayListEmployee)){
			printf("Saved in text.");
		}
	}
	fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;

	pFile=fopen(path,"w+");
	if(pFile!=NULL){
		if(!serializer_EmployeeToBinary(pFile, pArrayListEmployee)){
			printf("Saved in Binary.");
		}
	}
	fclose(pFile);
    return 1;
}

