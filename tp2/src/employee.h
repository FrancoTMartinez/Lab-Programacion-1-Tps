/*
 * employee.h
 *
 *  Created on: May 14, 2021
 *      Author: franco
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int employee_generateID();
void employee_init(Employee* arrayEmployee, int len);
int employee_add(Employee* arrayEmployee, int len, int emptyIndex);
int employee_findEmployeeById(Employee* arrayEmployee, int len,int idEmployee, int* indice);
int employee_removeEmployee(Employee* arrayEmployee, int len, int id);
int employee_printEmployees(Employee* arrayEmployee,int len);
int employee_modify(Employee* arrayEmployee,int limite ,int idEmployee);
int employee_sortByLastName(Employee* arrayEMployee, int len);
int employee_averageSalary(Employee* arrayEmployee, int len, int indexLastEmployee);

int employee_findEmpty(Employee* arrayEmployee, int len, int* index);
int employee_findFull(Employee* arrayEmployee, int len);
int employee_exceedSalary(Employee* arrayEmployee, int indexLastEmployee, float salaryRate, int* employeesRate);

#endif /* EMPLOYEE_H_ */
