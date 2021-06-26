#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir

*****************************************************/



int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
		printf("\n----------------------------------------------\n"
				"\n1-Load employees from text"
				"\n2-Load employees from binary"
				"\n3-Add employee"
				"\n4-Modify employee"
				"\n5-Remove employee"
				"\n6-List employees"
				"\n7-Sort employees"
				"\n8-Save data in text mode"
				"\n9-Save data in binary mode"
				"\n10-Exit"
				"\n----------------------------------------------\n");
		utn_getInt(&option,"\nEnter a number for an option: ","Error",1,10,3);
			switch(option)
			{
				case 1:
					controller_loadFromText("/home/franco/Documents/facultad/ejercicios/funciones-ejercicios/tp4IntegradoTp3/src/textMode.txt",listaEmpleados);
					break;
				case 2:
					controller_loadFromBinary("/home/franco/Documents/facultad/ejercicios/funciones-ejercicios/tp4IntegradoTp3/src/textBinary.txt",listaEmpleados);
					break;
				case 3:
					controller_addEmployee(listaEmpleados);
					break;
				case 4:
					controller_editEmployee(listaEmpleados);
					break;
				case 5:
					controller_removeEmployee(listaEmpleados);
					break;
				case 6:
					controller_ListEmployee(listaEmpleados);
					break;
				case 7:
					controller_sortEmployee(listaEmpleados);
					break;
				case 8:
					controller_saveAsText("/home/franco/Documents/facultad/ejercicios/funciones-ejercicios/tp4IntegradoTp3/src/textMode.txt", listaEmpleados);
					break;
				case 9:
					controller_saveAsBinary("/home/franco/Documents/facultad/ejercicios/funciones-ejercicios/tp4IntegradoTp3/src/textBinary.txt", listaEmpleados);
					break;
				case 10:
					break;
			}
    }while(option != 10);

    return 0;
}

