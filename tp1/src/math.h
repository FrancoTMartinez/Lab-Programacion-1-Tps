/*
 * math.h
 *
 *  Created on: Apr 1, 2021
 *      Author: FrancoTMartinez
 */

#ifndef MATH_H_
#define MATH_H_

float ftm_getSuma(float* pNumeroA, float* pNumeroB, float* resultado, char* errorNULL);
float ftm_getResta(float* pNumeroA, float* pNumeroB, float* resultado, char* errorNULL);
float ftm_getMultiplicar(float* pNumeroA, float* pNumeroB, float* resultado, char* errorCero, char* errorNULL);
float ftm_getDividir(float* pNumeroA, float* pNumeroB, float* resultado, char* errorCero, char* errorNULL);
float ftm_getFactorial(float* pNumeroA, float* resultado, char* errorNegativo, char* errorNULL);
#endif /* MATH_H_ */
