#ifndef _SIMD_ARCH
#define _SIMA_ARCH

#define _AVX_ARCH

#ifdef _AVX_ARCH
#include "VU32_avx.h"
#endif
void view_VU32(_VU32 *p){
	unsigned int *q = (unsigned int *)p;
	for (int i = _VU32_SIZE-1; i >= 0; i--)
		printf("%d\t", q[i]);
	printf("\n");
}
void viewH_VU32(_VU32 *p){
	unsigned int *q = (unsigned int *)p;
	for (int i = _VU32_SIZE-1; i >= 0; i--)
		printf("%0x\t", q[i]);
	printf("\n");
}
#endif