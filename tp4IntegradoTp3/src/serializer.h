/*
 * serializer.h
 *
 *  Created on: Jun 8, 2021
 *      Author: franco
 */

#ifndef SERIALIZER_H_
#define SERIALIZER_H_

int serializer_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);
int serializer_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* SERIALIZER_H_ */
