#include <stdio.h>
#include "simd_arch.h"
#include "vector_add.h"
#define N 1024

int main(int argc,char* argv[])
{
	float *a = (float *)_VU32_ALIGNED_MALLOC(N* sizeof(float));
	float *b = (float *)_VU32_ALIGNED_MALLOC(N * sizeof(float));
	float *d = (float *)_VU32_ALIGNED_MALLOC(N * sizeof(float));
	for (int i = 0; i < N; i++){
		a[i] = (float)i;
		b[i] = (float)(1 - i);
	}
	vectorF32_add(d, a, b,N);
	for (int i = 0; i < N; i++)
		printf("%d %f", i, d[i]);
	return 0;
}

