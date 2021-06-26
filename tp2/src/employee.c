/*
 * employee.c
 *
 *  Created on: May 14, 2021
 *      Author: franco
 */

#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/*
 * \brief: generate an AutoIncremental id
 * \return: returns an id
 */
int idEmployee=0;
int employee_generateID(){
	idEmployee+=1;

	return idEmployee;
}
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void employee_init(Employee* arrayEmployee, int len){
	for(int i=0; i<=len;i++){
		arrayEmployee[i].id=0;
		arrayEmployee[i].name[i]=0;
		arrayEmployee[i].lastName[i]=0;
		arrayEmployee[i].salary=0;
		arrayEmployee[i].sector=0;
		arrayEmployee[i].isEmpty=0;
	}
}
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param emptyIndex int
 * \return
*/
int employee_add(Employee* arrayEmployee, int len, int emptyIndex){
	int retorno=-1;
	Employee auxEmployee;

	if(arrayEmployee !=NULL && len>=0){
		if(utn_isValidName(auxEmployee.name, 51, "\nEnter your name: ","error")==0){
			if(utn_isValidName(auxEmployee.lastName,51,"\nEnter your lastName: ","error")==0){
				if(utn_getFloat(&auxEmployee.salary,"\nEnter your salary: ","Error",0,1000000,4)==0){
					if(utn_getInt(&auxEmployee.sector,"\nEnter your sector:"
													"\n1-Administrative"
													"\n2-Developer"
													"\n3-Cleaning", "Erorr", 1,3 ,2)==0){
						auxEmployee.isEmpty=1;
						auxEmployee.id= employee_generateID();
						arrayEmployee[emptyIndex]=auxEmployee;

						retorno=0;

					}
				}
			}
		}
	}
	return retorno;

}
/** \brief find an Employee by Id and returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int employee_findEmployeeById(Employee* arrayEmployee, int len,int id, int* index){
	int retorno=-1;
	int i;
	if(arrayEmployee!=NULL && len>0 && id>0){
		for(i=0;i<len;i++){
			if(arrayEmployee[i].id== id && arrayEmployee[i].isEmpty==1){
				*index=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int employee_removeEmployee(Employee* arrayEmployee, int len, int id){
	int retorno=-1;

	if(arrayEmployee !=NULL && len>0 && id>=0){
		for(int i=0; i<len; i++){
			if(arrayEmployee[i].id == id){
				arrayEmployee[i].isEmpty=0;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int employee_printEmployees(Employee* arrayEmployee,int len){
	int retorno=-1;

	if(arrayEmployee!=NULL && len>=0){
		for(int i=0;i<len;i++){
			if(arrayEmployee[i].isEmpty==1){
				printf("\n ID: %d) Name: %s ,LastName: %s ,Salary: %.2f, Sector: %d,",arrayEmployee[i].id,
																				arrayEmployee[i].name,
																				arrayEmployee[i].lastName,
																				arrayEmployee[i].salary,
																				arrayEmployee[i].sector);
																							retorno=0;
			}
		}
	}
	return retorno;
}
/** \brief Modify a Employee by Id
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int employee_modify(Employee* arrayEmployee,int len ,int idEmployee){
	int retorno=-1;
	int option;
	int indexToModify;

	Employee auxEmployee;

	if(employee_findEmployeeById(arrayEmployee, len, idEmployee, &indexToModify)==0){
		if(arrayEmployee !=NULL && len>0){
		do{
				utn_getInt(&option,"\nIngrese "
										"\n1- To modify Name. "
										"\n2- To modify LastName."
										"\n3- To modify salary."
										"\n4- To modify sector."
										"\n5-Exits","Error",1,5,3);
				switch (option) {
					case 1:
						if(utn_isValidName(auxEmployee.name, 51,"\nIngrese su nombre:","Error")==0){
							strncpy(arrayEmployee[indexToModify].name,auxEmployee.name,25);
							printf("\nModificacion exitosa.");
							retorno=0;
						}
						break;
					case 2:
						if(utn_isValidName(auxEmployee.lastName,51,"\nIngrese su lastName:","Error")==0){
							strncpy(arrayEmployee[indexToModify].lastName,auxEmployee.lastName,25);
							printf("\nModificacion exitosa.");
							retorno=0;
						}
						break;
					case 3:
						if(utn_getFloat(&auxEmployee.salary,"\nEnter your salary: ","Error",0,1000000,2)==0){
							arrayEmployee[indexToModify].salary=auxEmployee.salary;
							printf("\nModificacion exitosa.");
							retorno=0;
						}
						break;
					case 4:
						if(utn_getInt(&auxEmployee.sector,"\nEnter your sector:"
														"\n1-Administrative"
														"\n2-Developer"
														"\n3-Cleaning", "Erorr", 1,3 ,2)==0){
							arrayEmployee[indexToModify].sector=auxEmployee.sector;
							printf("\nModificacion exitosa.");
						}
						break;
					default:
						retorno=0;
						break;
				}
				retorno=0;

			}while(option!=5);
		}
	}

	return retorno;
}
/** \brief Find an empty place in the employeeList
 *
 * \param list Employee*
 * \param len int
 * \param idex int*
 * \return int Return (-1) if Error - (0) if Ok and return de empty index
 *
 */
int employee_findEmpty(Employee* arrayEmployee, int len, int* index){
	int retorno=-1;
	if(arrayEmployee!=NULL && len>0){
		for(int i=0; i<len;i++){
			if(arrayEmployee[i].isEmpty==0){
				*index=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief Find an full place in the employeeList
 *
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int employee_findFull(Employee* arrayEmployee, int len){
	int retorno=-1;
	if(arrayEmployee!=NULL && len>0){
		for(int i=0; i<len;i++){
			if(arrayEmployee[i].isEmpty==1){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief sort by last name
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int employee_sortByLastName(Employee* arrayEmployee, int len){
	int retorno=-1;
	int i=0;
	Employee auxEmployee;

	if(arrayEmployee!=NULL && len >0){
		for(i=0;i<len;i++){
			for(int j=i+1; j<len; j++){
				if(arrayEmployee[i].isEmpty==1 && arrayEmployee[j].isEmpty==1){
					if(strncmp(arrayEmployee[i].lastName,arrayEmployee[j].lastName,51)>0){

						auxEmployee=arrayEmployee[i];
						arrayEmployee[i]=arrayEmployee[j];
						arrayEmployee[j]=auxEmployee;
						retorno=0;
					}
				}
			}
		}
	}

	return retorno;
}
/** \brief Calculate avarage salary
 * \param list Employee*
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int employee_averageSalary(Employee* arrayEmployee, int len, int indexLastEmployee){
	int retorno=-1;
	float auxSalaryRate=0;
	float salaryRate=0;
	int employeesRate=0;

	if(arrayEmployee!=NULL && len>0 && indexLastEmployee>0){
		for(int i=0; i<=indexLastEmployee-1;i++){
			auxSalaryRate+=arrayEmployee[i].salary;
		}
		salaryRate= auxSalaryRate/(indexLastEmployee);
		if(employee_exceedSalary(arrayEmployee, indexLastEmployee, salaryRate, &employeesRate)==0){
			printf("The average salary is: %.2f,and the number of employees that exceed the average salary is: %d",salaryRate,employeesRate);
			retorno=0;
		}
	}
	return retorno;
}
/** \brief Calculate hoy many eployees exceeds the avarage salary
 * \param list Employee*
 * \param index of the last employee added int
 * \param salaryRate float
 * \param cuantity of employees wich exceed the salary rate int*
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int employee_exceedSalary(Employee* arrayEmployee, int indexLastEmployee, float salaryRate, int* employeesRate){
	int retorno=-1;
	int auxEmployeesRate=0;

	if(arrayEmployee!=NULL && indexLastEmployee>0 && salaryRate>=0){
		for(int i=0; i<indexLastEmployee;i++){
			if(arrayEmployee[i].salary > salaryRate){
				auxEmployeesRate++;
				retorno=0;
			}
		}
		*employeesRate=auxEmployeesRate;
		retorno=0;
	}
	return retorno;
}
