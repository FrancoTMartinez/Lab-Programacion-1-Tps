/*
 * utn.c
 *
 *  Created on: Mar 29, 2021
 *      Author: francoTMartinez
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"


int utn_getInt(int* pNumero,char* pTexto,char* pError,char* pErrorReintento,int min,int max,int reintentos){

	int retorno;
	int bufferInt;
	if(pNumero!=NULL && pTexto!=NULL && pError!=NULL && pErrorReintento!=NULL && min<=max && reintentos>=0){
		for(int i=0; i<reintentos;i++){
			printf("%s",pTexto);
			__fpurge(stdin);
			scanf("%d",&bufferInt);
			if(bufferInt>=min && bufferInt<=max){
				retorno= 0;
				reintentos=0;
				*pNumero= bufferInt;
			}else{
				printf("%s\n",pError);
				retorno=-1;
			}
		}
	}else{
		retorno=-1;
	}
	return retorno;
}

float utn_getFloatLImite(float* pNumero,char* pTexto,char* pError,float min,float max,int reintentos){

	int retorno;
	float bufferFloat;
	if(pNumero!=NULL && pTexto!=NULL && pError!=NULL && min<=max && reintentos>=0){
		for(int i=0; i<reintentos;i++){
			printf("%s",pTexto);
			__fpurge(stdin);
			scanf("%f",&bufferFloat);
			if(bufferFloat>=min && bufferFloat<=max){
				retorno= 0;
				reintentos=0;
				*pNumero= bufferFloat;
			}else{
				printf("%s\n",pError);
				retorno=-1;
			}
		}
	}else{
		retorno=-1;
	}
	return retorno;
}
float utn_getFloat(float* pNumero,char* pTexto,char* pError,int reintentos){

	int retorno;
	float bufferFloat;
	if(pNumero!=NULL && pTexto!=NULL && pError!=NULL && reintentos>=0){
		for(int i=0; i<reintentos;i++){
			printf("%s",pTexto);
			__fpurge(stdin);
			if(scanf("%f",&bufferFloat)==1){
				retorno= 0;
				reintentos=0;
				*pNumero= bufferFloat;
			}else{
				printf("%s\n",pError);
				retorno=-1;
			}
		}
	}else{
		retorno=-1;
	}
	return retorno;
}
char utn_getChar(char* pResponse,char* pTexto,char* max, char* min,char* pError,char* pErrorReintento){

	int retorno;
	char bufferChar;
	if(pResponse!= NULL && pTexto!= NULL && max!=NULL && min!=NULL && pError!= NULL && pErrorReintento!= NULL){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
			scanf("%c",&bufferChar);
			if(bufferChar >=min && bufferChar<=max){
				retorno= 0;
				*pResponse= bufferChar;
				break;
			}else{
				printf("%s\n",pError);
				retorno=-1;
			}
		}while(retorno==-1);
	}else{
		retorno=-1;
	}
	return retorno;
}

char utn_getResponse(char* pResponse,char* pTexto,char* pError,char* pErrorReintento){

	int retorno;
	char bufferChar;
	if(pResponse!= NULL && pTexto!= NULL && pError!= NULL && pErrorReintento!= NULL){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
			scanf("%c",&bufferChar);
			if(bufferChar == 'y' || bufferChar=='n'){
				retorno= 0;
				*pResponse= bufferChar;
				break;
			}else{
				printf("%s\n",pError);
				retorno=-1;
			}
		}while(bufferChar!='y' && bufferChar!='n');
	}else{
		retorno=-1;
	}
	return retorno;
}

