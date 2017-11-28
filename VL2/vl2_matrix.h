#ifndef _VL2_MATRIX_H
#define _VL2_MATRIX_H

void vectorF32_add(float *dest, float *a,float *b,int N);
void matrixF32_setzero(float *d, int N);
void matrixF32_madd(float *d, float *a, float *b, int N);

#endif