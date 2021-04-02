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

	float a;
	float b;
	float resultado;

	if(utn_getFloat(&a,"Ingrese el primer numero","Error. Reintente",3)==0){
		printf("Ingreso: %.2f\n", a);
	};
	if(utn_getFloat(&b,"Ingrese el segundo numero","Error. Reintente",3)==0){
		printf("Ingreso: %.2f\n", b);
	};

	if(ftm_getSuma(&a, &b, &resultado,"Hubo un error.")==0){
		printf("El resultado de %.2f + %.2f es: %.2f \n", a,b,resultado);
	}
	if(ftm_getResta(&a, &b, &resultado,"Hubo un error.")==0){
		printf("El resultado de %.2f - %.2f es: %.2f \n", a,b,resultado);
	}
	if(ftm_getMultiplicar(&a, &b, &resultado,"Todo numero multiplicado por cero es cero.","Hubo un error.")==0){
		printf("El resultado de %.2f * %.2f es: %.2f \n", a,b,resultado);
	}
	if(ftm_getDividir(&a, &b, &resultado,"No se puede dividir por cero.","Hubo un error.")==0){
		printf("El resultado de %.2f / %.2f es: %.2f \n", a,b,resultado);
	}
	if(ftm_getFactorial(&a, &resultado,"No se puede hacer el factorial de un numero negativo.","Hubo un error.")==0){
			printf("El factotial de %.0f es: %.0f \n", a,resultado);
		}
	if(ftm_getFactorial(&b, &resultado,"No se puede hacer el factorial de un numero negativo.","Hubo un error.")==0){
			printf("El factotial de %.0f es: %.0f \n", b,resultado);
		}
	return 0;
}
