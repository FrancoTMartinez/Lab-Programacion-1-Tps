/*
 * utn.c
 *
 *  Created on: Mar 29, 2021
 *      Author: francoTMartinez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h> //toupper-tolower
#include "utn.h"


/**
 * brief: intercambia la ultima posicion del array por "\0"
 * charArray= puntero a un array del tipo char
 * longitud= longitud del array
 */
static int myGets(char* charArray, int longitud){
    int output = -1;
    char bufferString[4096];
    __fpurge(stdin);
    if (charArray != NULL && longitud > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
        if (bufferString[0] == '\n') {
            printf("Error, solo ingreso un ENTER\n");
        } else {
            bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
            if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
                strncpy(charArray, bufferString, longitud);
                output = 0;
            }
        }
    }
    return output;
}
/**
 * brief: valida que el array estre comprendido de solo numeros enteros
 * charArray= puntero a un array del tipo char
 */
static int ValidateIntNumer(char* charArray){
	int i=0;
	int retorno=1;

	if(charArray !=NULL && strlen(charArray)>0){
		while(charArray[i] != '\0'){
			if(charArray[i]<'0' || charArray[i]>'9'){
				retorno= 0;
				break;
			}
		i++;
		}
	}
	return retorno;
}
/**
 * brief: valida que el array estre comprendido de solo numeros float
 * charArray= puntero a un array del tipo char
 */
static int ValidateFloatNumerber(char* charArray){
	int i=0;
	int retorno=1;

	if(charArray !=NULL && strlen(charArray)>0){
		while(charArray[i] != '\0'){
			if((charArray[i]>='0' && charArray[i]<='9') || charArray[i]=='.' ){
				i++;
			}else{
				retorno= 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * brief: valida que el array estre comprendido de solo numeros float
 * pString= puntero a un array del tipo char
 */
static int ValidateText(char* pString){
	int i=0;
	int retorno=1;
	if(pString !=NULL && strlen(pString)>0){
		while(pString[i] != '\n'){
			if(pString[i]<' ' || pString[i]>126){
				retorno= 0;
				break;
			}
		i++;
		}
	}
	return retorno;
}
static int ValidateTextWithNoLine(char* pString){
	int i=0;
	int retorno=1;
	if(pString !=NULL && strlen(pString)>0){
		while(pString[i] != '\0'){
			if(pString[i]<' ' || pString[i]>126){
				retorno= 0;
				break;
			}
		i++;
		}
	}
	return retorno;
}
/**
 * brief: array de caracteres a Mayusculas
 * pString= puntero a un array del tipo char
 */
static int stringToUpperCase(char pString[]){
	int i=0;
	int retorno=0;

	if(pString !=NULL && strlen(pString)>0){
		for(i=0;i<strlen(pString);i++){
			pString[i]= toupper(pString[i]);
			retorno=0;
		}
	}else{
		retorno=1;
	}
	return retorno;
}
/*static int stringToLowerCase(char pString[]){
	int i=0;
	int retorno=0;

	if(pString !=NULL && strlen(pString)>0){
		for(i=1;i<strlen(pString);i++){
			pString[i]= tolower(pString[i]);
			retorno=0;
		}
	}else{
		retorno=1;
	}
	return retorno;
}*/
/**
 * brief: valida que el array estre comprendido de solo letras y espacios
 * pString= puntero a un array del tipo char
 */
int ValidateName(char pString[]){
	int i=0;
	int retorno=0;

	if(pString !=NULL && strlen(pString)>0){
			while(pString[i]!='\0'){
				if((pString[i]<'a' || pString[i]>'z') && (pString[i]<'A' || pString[i]>'Z') && pString[i]!=' '&& pString[i]!='-' ){
					retorno= 1;
					break;
				}
			i++;
			}

	}
	return retorno;
}
int ValidateCode(char pString[]){
	int i=0;
	int retorno=0;

	if(pString !=NULL && strlen(pString)>0){
			while(pString[i]!='\0'){
				if((pString[i]<'a' || pString[i]>'z') && (pString[i]<'A' || pString[i]>'Z') && (pString[i]<'0' || pString[i]>'9') && pString[i]!='_'&& pString[i]!='-'&& pString[i]!=' ' ){
					retorno= 1;
					break;
				}
			i++;
			}

	}
	return retorno;
}
int ValidateNomenclatura(char pString[]){
	int i=0;
	int retorno=0;

	if(pString !=NULL && strlen(pString)>0){
			while(pString[i]!='\0'){
				if((pString[i]<'a' || pString[i]>'z') && (pString[i]<'A' || pString[i]>'Z') && (pString[i]<'0' || pString[i]>'9') && pString[i]!='.' ){
					retorno= 1;
					break;
				}
			i++;
			}

	}
	return retorno;
}
/**
 * brief: obtiene un int utilizandos dos funciones estaticas y atoi.
 * pNumero= puntero a una variable de tipo int
 */
static int getInt(int* pNumero){

	int retorno=-1;
	char buffer[15];

	if(pNumero!=NULL){
		if(myGets(buffer,sizeof(buffer))==0 && ValidateIntNumer(buffer)){
			*pNumero=atoi(buffer);
			retorno=0;
		}
	}else{
		retorno=-1;
	}
	return retorno;
}
static int ValidateCuit(char* charArray){
	int i=0;
	int retorno=-1;

	if(charArray !=NULL && strlen(charArray)>0){
		while(charArray[i] != '\0'){
			if( (charArray[i]>='0' && charArray[i]<='9') ||
				(charArray[0]=='2' && charArray[0]=='3')||
				(charArray[2]=='-' && charArray[11]=='-')){
				retorno=1;
			}else{
				retorno= 0;
				break;
			}
		i++;
		}
	}
	return retorno;
}
static int getCuit(char* pString, int limite){

	int retorno=-1;
	char buffer[limite];

	if(pString!=NULL){
		fgets(buffer,limite,stdin);
		if(ValidateCuit(buffer)){
			strncpy(pString,buffer,limite);
			retorno=0;
		}
	}else{
		retorno=-1;
	}
	return retorno;
}
/**
 * brief: obtiene un float utilizandos dos funciones estaticas y atof.
 * pNumero= puntero a una variable de tipo float
 */
static int getFloat(float* pNumero){

	int retorno=-1;
	char buffer[15];

	if(pNumero!=NULL){
		if(myGets(buffer,sizeof(buffer))==0 && ValidateFloatNumerber(buffer)){
			*pNumero=atof(buffer);
			retorno=0;
		}
	}else{
		retorno=-1;
	}
	return retorno;
}
/**
 * brief: obtiene un una cadena de caracteres para luego validarla.
 * pString= puntero a una variable del tipo char
 */
static int getString(char* pString, int limite){

	int retorno=-1;
	char buffer[limite];

	if(pString!=NULL){
		fgets(buffer,limite,stdin);
		if(ValidateText(buffer)){
			strncpy(pString,buffer,limite);
			retorno=0;
		}
	}else{
		retorno=-1;
	}
	return retorno;
}
static int getStringWthNoLine(char* pString, int limite){

	int retorno=-1;
	char buffer[limite];

	if(pString!=NULL){
		if(!myGets(buffer, limite) && ValidateTextWithNoLine(buffer)){
				strncpy(pString,buffer,limite);
				retorno=0;
		}
	}else{
		retorno=-1;
	}
	return retorno;
}
/**
 * brief: obtiene un int utilizandos varias validaciones ya mencionadas.
 * pNumero= puntero a una variable del tipo int.
 * pTexto= mensaje que le indicara al usario que ingresar
 * pError= mensaje de error
 * min= rango minimo que se puede ingresar
 * max= rango maximo que se puede ingresar
 * reintentos= cantidad de veces que puede ingregar los datos en caso de error
 */
int utn_getInt(int* pNumero,char* pTexto,char* pError,int min,int max,int reintentos){

	int retorno;
	int bufferInt;

	if(pNumero!=NULL && pTexto!=NULL && pError!=NULL && min<=max && reintentos>=0){
		for(int i=0; i<reintentos;i++){
			printf("%s",pTexto);
			if(getInt(&bufferInt)==0){
				if(bufferInt>=min && bufferInt<=max){
					*pNumero= bufferInt;
					retorno= 0;
					reintentos=0;
				}else{
					printf("%s\n",pError);
					retorno=-1;
				}
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
int utn_isNumeric(char *pCadena){
    int output = 1;
    if(pCadena !=NULL){
        for(int x = 0; pCadena[x] !='\0'; x++){
            if(pCadena[x] < '0' || pCadena[x] > '9')
            {
                output = 0;
                break;
            }
        }
    }
    return output;
}
/**
 * brief: obtiene un float utilizandos varias validaciones ya mencionadas.
 * pNumero= puntero a una variable del tipo float.
 * pTexto= mensaje que le indicara al usario que ingresar
 * pError= mensaje de error
 * min= rango minimo que se puede ingresar
 * max= rango maximo que se puede ingresar
 * reintentos= cantidad de veces que puede ingregar los datos en caso de error
 */
int utn_getFloat(float* pNumero,char* pTexto,char* pError,int min,int max,int reintentos){

	int retorno;
	float bufferFloat;

	if(pNumero!=NULL && pTexto!=NULL && pError!=NULL && min<=max && reintentos>=0){
		for(int i=0; i<reintentos;i++){
			printf("%s",pTexto);
			if(getFloat(&bufferFloat)==0){
				if(bufferFloat>=min && bufferFloat<=max){
					*pNumero= bufferFloat;
					retorno= 0;
					reintentos=0;
				}else{
					printf("%s\n",pError);
					retorno=-1;
				}
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
/**
 * brief: obtiene un char utilizandos varias validaciones ya mencionadas.
 * pString= puntero a una variable del tipo char.
 * pTexto= mensaje que le indicara al usario que ingresar
 * pError= mensaje de error
 */
char utn_getString(char* pString,int limite,char* pTexto,char* pError){

	int retorno;
	char bufferChar[limite];

	if(pString!= NULL && pTexto!= NULL && pError!= NULL){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
			if(getString(bufferChar,limite)==0){
				strncpy(pString,bufferChar,limite);
				retorno= 0;
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
char utn_getStringWithNoLine(char* pString,int limite,char* pTexto,char* pError){

	int retorno;
	char bufferChar[limite];

	if(pString!= NULL && pTexto!= NULL && pError!= NULL){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
			if(getStringWthNoLine(bufferChar,limite)==0){
				strncpy(pString,bufferChar,limite);
				retorno= 0;
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
/**
 * brief: obtiene un char utilizandos varias validaciones ya mencionadas.
 * pString= puntero a una variable del tipo char.
 * pTexto= mensaje que le indicara al usario que ingresar
 * pError= mensaje de error
 */
int utn_isValidName(char* pString,int limite,char* pTexto,char* pError){

	int retorno;
	char bufferChar[limite];

	if(pString!= NULL && pTexto!= NULL && pError!= NULL){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
				if( myGets(bufferChar, limite)==0 && ValidateName(bufferChar)==0){
					strncpy(pString,bufferChar,limite);
					retorno= 0;
					break;
				}else{
					printf("%s\n",pError);
					retorno=1;
				}

		}while(retorno==1);
	}else{
		retorno=-1;
	}
	return retorno;
}
int utn_isValidAlphaNumericCode(char* pString,int limite,char* pTexto,char* pError){

	int retorno;
	char bufferChar[limite];

	if(pString!= NULL && pTexto!= NULL && pError!= NULL){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
				if(!myGets(bufferChar,limite) && !ValidateCode(bufferChar)){
					strncpy(pString,bufferChar,limite);
					retorno= 0;
					break;
				}else{
					printf("%s\n",pError);
					retorno=1;
				}
		}while(retorno==1);
	}else{
		retorno=-1;
	}
	return retorno;
}
char utn_isValidString(char* pString){

	int retorno;

	if(pString!= NULL){
				if(ValidateName(pString)==0){
					retorno=0;
				}else{
					retorno=1;
				}
	}
	return retorno;
}
char utn_getResponse(char* pResponse,char* pTexto,char* pError,int pErrorReintento){

	int retorno;
	char buffer[2];
	if(pResponse!= NULL && pTexto!= NULL && pError!= NULL && pErrorReintento>=0){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
			fgets(buffer,2,stdin);
			if(buffer[0] == 'y' || buffer[0]=='n'){
				retorno= 0;
				strncpy(pResponse,buffer, 2);
				break;
			}else{
				printf("%s\n",pError);
				retorno=-1;
			}
		}while(buffer[0]!='y' && buffer[0]!='n');
	}else{
		retorno=-1;
	}
	return retorno;
}
char utn_getSexo(char* pResponse,char* pTexto,char* pError){

	int retorno;
	char buffer[2];

	if(pResponse!= NULL && pTexto!= NULL && pError!= NULL){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
			fgets(buffer,2,stdin);
			if(buffer[0] == 'f' || buffer[0]=='m'){
				retorno= 0;
				strncpy(pResponse,buffer, 2);
				break;
			}else{
				printf("%s\n",pError);
				retorno=-1;
			}
		}while(buffer[0]!='f' && buffer[0]!='m');
	}else{
		retorno=-1;
	}
	return retorno;
}
char utn_getTipoMascota(char* pResponse,char* pTexto,char* pError){

	int retorno;
	char buffer[25];
	char tipo[3][10]={{"perro\n"},{"gato\n"},{"raro\n"}};
	int flagTipo=1;
	if(pResponse!= NULL && pTexto!= NULL && pError!= NULL){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
			fgets(buffer,25,stdin);
			for(int i=0;i<3;i++){
				if(strcmp(buffer, tipo[i])==0){
					strncpy(pResponse,buffer, 25);
					retorno= 0;
					flagTipo=0;
					break;
				}
			}
		}while(flagTipo!=0);
	}else{
		retorno=-1;
	}
	return retorno;
}
char utn_getPantalla(char* pResponse,char* pTexto,char* pError){

	int retorno;
	char buffer[6];
	char tipoPantalla[2][6]={{"LCD\n"},{"LED\n"}};
	int flag=1;

	if(pResponse!= NULL && pTexto!= NULL && pError!= NULL){
		do{
			printf("%s",pTexto);
			__fpurge(stdin);
			fgets(buffer,6,stdin);
			stringToUpperCase(buffer);
			for(int i=0;i<2;i++){
				if(strcmp(buffer,tipoPantalla[i])==0){
					strncpy(pResponse,buffer, 6);
					retorno= 0;
					flag=0;
					break;
				}
			}
		}while(flag!=0);
	}else{
		retorno=-1;
	}
	return retorno;
}
int utn_getCuit(char* pString,int limite,char* pTexto,char* pError, int reintentos){

	int retorno;
	char bChar[limite];

	if(pString!=NULL && pTexto!=NULL && pError!=NULL && reintentos>=0){
		for(int i=0; i<reintentos;i++){
			printf("%s",pTexto);
			__fpurge(stdin);
			if(getCuit(bChar,limite)==0){
					strncpy(pString,bChar,limite);
					retorno= 0;
					reintentos=0;
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
int utn_getStringWithOnlyNumbers(char *msg, char *msgError, char *pCadena, int limite, int reintentos) {
    int output = -1;
    if (msg != NULL && msgError != NULL && pCadena != NULL && limite > 0 && reintentos > 0) {
        do {
            printf("%s", msg);
            if (!(myGets(pCadena, limite)) && ValidateIntNumer(pCadena)) {
                for(int x = 0; x<limite; x++){
                    pCadena[x] = toupper(pCadena[x]);
                }
                output = 0;
            } else {
                reintentos--;
                if (reintentos > 0) {
                    printf("%s: %d\n", msgError, reintentos);
                }
            }
        } while (output != 0 && reintentos > 0);
    }
    return output;
}
