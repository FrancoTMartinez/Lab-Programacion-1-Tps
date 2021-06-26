/*
 * utn.h
 *
 *  Created on: Mar 29, 2021
 *      Author: francoTMartinez
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt(int* pNumero,char* pTexto,char* pError,int min,int max,int reintentos);
int utn_getFloat(float* pNumero,char* pTexto,char* pError,int min,int max,int reintentos);
char utn_getString(char* pString,int limite,char* pTexto,char* pError);
int utn_isValidName(char* pString,int limite,char* pTexto,char* pError);
char utn_getResponse(char* pResponse,char* pTexto,char* pError,int pErrorReintento);
char utn_getSexo(char* pResponse,char* pTexto,char* pError);
char utn_getTipoMascota(char* pResponse,char* pTexto,char* pError);
char utn_getPantalla(char* pResponse,char* pTexto,char* pError);
int utn_getCuit(char* pString,int limite,char* pTexto,char* pError, int reintentos);
int utn_getStringWithOnlyNumbers(char *msg, char *msgError, char *pCadena, int limite, int reintentos);
int utn_isNumeric(char *pCadena);
char utn_getStringWithNoLine(char* pString,int limite,char* pTexto,char* pError);
int utn_isValidAlphaNumericCode(char* pString,int limite,char* pTexto,char* pError);
char utn_isValidString(char* pString);
int ValidateName(char pString[]);
int ValidateCode(char pString[]);
int ValidateNomenclatura(char pString[]);
#endif /* UTN_H_ */
