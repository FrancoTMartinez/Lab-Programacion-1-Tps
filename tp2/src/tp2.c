/*
 ============================================================================
 Name        : tp2.c
 Author      : FrancoTMartinez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "utn.h"

#define QYT_EMPLOYEES 10

int main(void) {
	int option;
	int subMenuOption;
	int emptyIndex;
	int employeeId;

	Employee employeeList[QYT_EMPLOYEES];

	employee_init(employeeList, QYT_EMPLOYEES);


	do{
				printf("\n----------------------------------------------\n"
						"\n1-Add Employee"
						"\n2-Modificate Employee"
						"\n3-Remove Employee"
						"\n4-Inform"
						"\n5-Exit"
						"\n----------------------------------------------\n");
				utn_getInt(&option,"\nChoose an option: ","Error",1,5,3);
				switch(option){
					case 1:
							employee_findEmpty(employeeList,QYT_EMPLOYEES,&emptyIndex);
							employee_add(employeeList, QYT_EMPLOYEES, emptyIndex);
						break;
					case 2:
						if(employee_findFull(employeeList,QYT_EMPLOYEES)==0){
							if(utn_getInt(&employeeId,"Enter your ID","Error",1,10,3)==0 &&
								employee_modify(employeeList, QYT_EMPLOYEES,employeeId)==0){
								printf("\nDone..");
							}
						}
						break;
					case 3:
						if(employee_findFull(employeeList,QYT_EMPLOYEES)==0){
							if(utn_getInt(&employeeId,"Enter your ID","Error",1,10,3)==0 &&
								employee_removeEmployee(employeeList, QYT_EMPLOYEES,employeeId)==0){
								printf("\nDone.");
							}
						}
						break;
					case 4:
						if(employee_findFull(employeeList,QYT_EMPLOYEES)==0){
							do{
								printf("\n----------------------------------------------\n"
										"\n1-Sort by Name order"
										"\n2-Average salary"
										"\n3-Exit"
										"\n----------------------------------------------\n");
								utn_getInt(&subMenuOption,"\nChoose an option: ","Error",1,3,3);
								switch(subMenuOption){
									case 1:
											if(employee_sortByLastName(employeeList,QYT_EMPLOYEES)==0){
												employee_printEmployees(employeeList, QYT_EMPLOYEES);
											}
										break;
									case 2:
										if(employee_findEmpty(employeeList,QYT_EMPLOYEES,&emptyIndex)==0){
											if(employee_averageSalary(employeeList,QYT_EMPLOYEES,emptyIndex)==-1){
												printf("error");
											}
										}
										break;
									default:
										break;
								}
							}while(subMenuOption!=3);
						}
						break;
				}
			}while(option!=5);
}
