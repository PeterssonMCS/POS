#ifndef _LIN_ALGEBRA_H_
#define _LIN_ALGEBRA_H_

#include <stdint.h>

typedef struct{
	float x;
	float y;
	uint32_t size;
}VECTOR_t;

void VECTOR_Add( VECTOR_t* v1, VECTOR_t* v2);

void VECTOR_Sub( VECTOR_t* v1, VECTOR_t* v2);

float VECTOR_EscMult( VECTOR_t* v1 , VECTOR_t* v2);

void VECTOR_VecMult( VECTOR_t* v1 , VECTOR_t* v2);

#endif
