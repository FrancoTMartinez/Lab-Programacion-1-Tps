/*
 ============================================================================
 Name        : tp2.c
 Author      : FrancoTMartinez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
2)Se cargan varios empleados, los informes solo imprime uno solo.
3)No muestra el “Average salary” y en ese momento se trata de volver a ingresar el sort y no se imprime
más la lista.
No se puede continuar con las pruebas, ya que no hay forma de poder ver la lista de empleados cargado


4)Se debería arrojar un mensaje al usuario cuando se equivoca de opción y no hay empleados cargados.
5)Al momento de eliminarse o modificarse se debería mostrar, previamente, la lista de empleados
	para saber que id usar.
6)El modificar no hace nada, el eliminar tampoco.
7)Cuando se desea imprimir la lista ordenada solo muestra el primer ingresado.
8)No se puede continuar con las pruebas por los errores en tiempo de ejecución

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
							if(!employee_add(employeeList, QYT_EMPLOYEES, emptyIndex)){
								printf("\nLoaded.");
							}
						break;
					case 2:
						if(employee_findFull(employeeList,QYT_EMPLOYEES)==0){
							employee_printEmployees(employeeList, QYT_EMPLOYEES);
							if(utn_getInt(&employeeId,"\nEnter your ID","Error",1,10,3)==0 &&
								employee_modify(employeeList, QYT_EMPLOYEES,employeeId)==0){
							}
						}else{
							printf("\nNo se puede ingresar debido a que no hay empleados cargados.");
						}
						break;
					case 3:
						if(employee_findFull(employeeList,QYT_EMPLOYEES)==0){
							employee_printEmployees(employeeList, QYT_EMPLOYEES);
							if(utn_getInt(&employeeId,"\nEnter your ID","Error",1,10,3)==0 &&
								employee_removeEmployee(employeeList, QYT_EMPLOYEES,employeeId)==0){
								printf("\nDone.");
							}
						}else{
							printf("\nNo se puede ingresar debido a que no hay empleados cargados.");
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
											}else{
												printf("\nError");
											}
										break;
									case 2:
										if(employee_findEmpty(employeeList,QYT_EMPLOYEES,&emptyIndex)==0){
											if(employee_averageSalary(employeeList,QYT_EMPLOYEES,emptyIndex)==-1){
												printf("\nerror");
											}
										}
										break;
									default:
										break;
								}
							}while(subMenuOption!=3);
						}else{
							printf("\nNo se puede ingresar debido a que no hay empleados cargados.");
						}
						break;
					case 5:
						break;
				}
			}while(option!=5);
}
