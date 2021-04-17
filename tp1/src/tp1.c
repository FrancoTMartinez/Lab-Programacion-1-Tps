/*
 ============================================================================
 Name        : tp1.c
 Author      : FrancoTMartinez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "math.h"
#include "utn.h"

int main(void) {

	int opcion;
	int respuestaOpcion;
	float a;
	float b;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorialA;
	float resultadoFactorialB;



	do{
		respuestaOpcion=utn_getInt(&opcion, "Selecione una opcion:\n\n1-Para ingresar el primer numero"
				"								 	 \n2-Para ingresar el segundo numero"
				"									 \n3-Calcular operaciones"
				"									 \n4-Mostrar Resultados"
				"									 \n5-Salir.", "No es una opcion valida\n ","Reintente",1,5,3);

		if(respuestaOpcion==0){
			switch(opcion){
				case 1:
					if(utn_getFloat(&a,"Ingrese el primer numero","Error. Reintente",3)==0){
						printf("Ingreso: %.2f\n", a);
					};
					break;
				case 2:
					if(utn_getFloat(&b,"Ingrese el segundo numero","Error. Reintente",3)==0){
						printf("Ingreso: %.2f\n", b);
					};
					break;
				case 3:
					ftm_getSuma(&a, &b, &resultadoSuma,"Hubo un error.");
					ftm_getResta(&a, &b, &resultadoResta,"Hubo un error.");
					ftm_getMultiplicar(&a, &b, &resultadoMultiplicacion,"Todo numero multiplicado por cero es cero.","Hubo un error.");
					ftm_getDividir(&a, &b, &resultadoDivision,"No se puede dividir por cero.","Hubo un error.");
					ftm_getFactorial(&a, &resultadoFactorialA,"No se puede hacer el factorial de un numero negativo.","Hubo un error.");
					ftm_getFactorial(&b, &resultadoFactorialB,"No se puede hacer el factorial de un numero negativo.","Hubo un error.");
					break;
				case 4:
					printf("El resultado de %.2f + %.2f es: %.2f \n", a,b,resultadoSuma);
					printf("El resultado de %.2f - %.2f es: %.2f \n", a,b,resultadoResta);
					printf("El resultado de %.2f * %.2f es: %.2f \n", a,b,resultadoMultiplicacion);
					printf("El resultado de %.2f / %.2f es: %.2f \n", a,b,resultadoDivision);
					printf("El factotial de %.0f es: %.0f \n", a,resultadoFactorialA);
					printf("El factotial de %.0f es: %.0f \n", b,resultadoFactorialB);
					break;
			}
		}
	}while(opcion!=5);

	return 0;
}
