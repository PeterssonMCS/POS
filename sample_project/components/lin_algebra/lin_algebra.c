#include "lin_algebra.h"

void VECTOR_Add( VECTOR_t* v1, VECTOR_t* v2)
{
	v1->x = v1->x + v2->x;
	v1->y = v1->y + v2->y;
}

void VECTOR_Sub( VECTOR_t* v1, VECTOR_t* v2)
{
	v1->x = v1->x - v2->x;
	v1->y = v1->y - v2->y;
}

float VECTOR_EscMult( VECTOR_t* v1 , VECTOR_t* v2)
{
	return (v1->x*v2->y - v1->y*v2->x);
}

void VECTOR_VecMult( VECTOR_t* v1 , VECTOR_t* v2)
{
	VECTOR_t result[2];
	result[0].x = v1->x * v2->x;
	result[0].y = v1->x * v2->y;
	result[1].x = v1->y * v2->x;
	result[1].y = v1->y * v2->y;
}
