/*
 * math.c
 *
 *  Created on: Apr 1, 2021
 *      Author: FrancoTMartinez
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "math.h"


float ftm_getSuma(float* pNumeroA, float* pNumeroB, float* resultado, char* errorNULL){
	int retorno;
	float suma;
	if(pNumeroA !=NULL && pNumeroB!=NULL && resultado!= NULL && errorNULL!=NULL){
		suma= *pNumeroA + *pNumeroB;
		*resultado= suma;
		retorno=0;
	}else{
		printf("%s", errorNULL);
		retorno=-1;
	}
	return retorno;
}
float ftm_getResta(float* pNumeroA, float* pNumeroB, float* resultado, char* errorNULL){
	int retorno;
	float resta;
	if(pNumeroA !=NULL && pNumeroB!=NULL && resultado!= NULL && errorNULL!=NULL){
		resta= *pNumeroA - *pNumeroB;
		*resultado= resta;
		retorno=0;
	}else{
		printf("%s", errorNULL);
		retorno=-1;
	}
	return retorno;
}
float ftm_getMultiplicar(float* pNumeroA, float* pNumeroB, float* resultado, char* errorCero, char* errorNULL){
	int retorno;
	float multiplicacion;
	if(pNumeroA !=NULL && pNumeroB!=NULL && resultado!= NULL && errorCero!=NULL && errorNULL!=NULL){
		if(*pNumeroA !=0 && *pNumeroB !=0){
			multiplicacion= *pNumeroA * *pNumeroB;
			*resultado= multiplicacion;
			retorno=0;
		}else{
			*resultado=0;
			printf("%s",errorCero);
			retorno=-1;
		}
	}else{
		printf("%s", errorNULL);
		retorno=-1;
	}
	return retorno;
}
float ftm_getDividir(float* pNumeroA, float* pNumeroB, float* resultado, char* errorCero, char* errorNULL){
	int retorno;
	float division;

	if(pNumeroA!=NULL && pNumeroB!=NULL && resultado!=NULL && errorCero!=NULL && errorNULL!=NULL){
		if(*pNumeroB !=0){
			division= *pNumeroA / *pNumeroB;
			*resultado= division;
			retorno=0;
		}else{
			*resultado=0;
			printf("%s",errorCero);
			retorno=-1;
		}
	}else{
		printf("%s", errorNULL);
		retorno=-1;
	}
	return retorno;
}
float ftm_getFactorial(float* pNumeroA, float* resultado, char* errorNegativo, char* errorNULL){
	int retorno;
	int acum=1;
	if(pNumeroA!=NULL && resultado!=NULL && errorNegativo!=NULL && errorNULL!= NULL){
		if(*pNumeroA>0){
			for(int i=1;i<=(int)*pNumeroA;i++){
				acum *= i;
			}
			*resultado=acum;
			retorno=0;
		}else{
			printf("%s", errorNegativo);
			retorno=-1;
		}
	}else{
		printf("%s", errorNULL);
		retorno=-1;
	}
	return retorno;
}

