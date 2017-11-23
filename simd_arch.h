#ifndef _SIMD_ARCH
#define _SIMA_ARCH

#define _AVX_ARCH

#ifdef _AVX_ARCH
#include "VU32_avx.h"
#endif

//Aligned Malloc and Free
#if defined(_MSC_VER)  		//Microsoft Visual C
#define _VU32_ALIGNED_MALLOC(size)  (_VU32 *)_aligned_malloc(size,_VU32_ALGSIZE)     
#define _VU32_ALIGNED_FREE(p)   	_aligned_free(p)

#elif defined(__GNUC_)_
#define _VU32_ALIGNED_MALLOC(size)  (_VU32 *)memalign(_VU32_ALGSIZE,size)     
#define _VU32_ALIGNED_FREE(p)   	free(p)

#elif defined(__ICC) || defined(__INTEL_COMPILER)
#define _VU32_ALIGNED_MALLOC(size)  (_VU32 *)_mm_malloc(size,_VU32_ALGSIZE)     
#define _VU32_ALIGNED_FREE(p)   	_mm_free(p)

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