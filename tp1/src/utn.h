/*
 * utn.h
 *
 *  Created on: Mar 29, 2021
 *      Author: francoTMartinez
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pNumero,char* pTexto,char* pError,char* pErrorReintento,int min,int max,int reintentos);
float utn_getFloatLImite(float* pNumero,char* pTexto,char* pError,float min,float max,int reintentos);
float utn_getFloat(float* pNumero,char* pTexto,char* pError,int reintentos);
char utn_getResponse(char* pResponse,char* pTexto,char* pError,char* pErrorReintento);
char utn_getChar(char* pResponse,char* pTexto,char* max, char* min,char* pError,char* pErrorReintento);

#endif /* UTN_H_ */
