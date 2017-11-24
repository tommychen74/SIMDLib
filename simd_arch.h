#ifndef _SIMD_ARCH
#define _SIMA_ARCH
//USER CHANGE ARCHITECURE, HERE!
#define _SSE_ARCH
//#define _AVX_ARCH
//#define _AVX512_ARCH
//#define _NEON_ARCH

#ifdef _SSE_ARCH
#define _VU32_SIZE 4
#define _VU32_ALGSIZE 16
#define _VU32_LOG_ALGSIZE 4

#define _VF32_SIZE 4
#define _VF32_ALGSIZE 16
#define _VF32_LOG_ALGSIZE 4

#include "VU32_sse.h"
#include "VF32_sse.h"
#endif

#ifdef _AVX_ARCH
#define _VU32_SIZE 8
#define _VU32_ALGSIZE 32
#define _VU32_LOG_ALGSIZE 5

#define _VF32_SIZE 8
#define _VF32_ALGSIZE 32
#define _VF32_LOG_ALGSIZE 5

#include "VU32_avx.h"
#include "VF32_avx.h"
#endif

#ifdef _AVX512_ARCH
#define _VU32_SIZE 16
#define _VU32_ALGSIZE 64
#define _VU32_LOG_ALGSIZE 6

#include "VU32_avx512.h"
#endif

#ifdef _NEON_ARCH
#define _VU32_SIZE 4
#define _VU32_ALGSIZE 32
#define _VU32_LOG_ALGSIZE 4

#include "VU32_neon.h"
#endif

//Aligned Malloc and Free
#if defined(_MSC_VER)  		//Microsoft Visual C
#define _VU32_ALIGNED_MALLOC(size)  _aligned_malloc(size,_VU32_ALGSIZE)     
#define _VU32_ALIGNED_FREE(p)   	_aligned_free(p)

#elif defined(__GNUC__)    	//gcc
#include <malloc.h>
#define _VU32_ALIGNED_MALLOC(size)  memalign(_VU32_ALGSIZE,size)     
#define _VU32_ALIGNED_FREE(p)   	free(p)

#elif defined(__ICC) || defined(__INTEL_COMPILER)	//icc
#define _VU32_ALIGNED_MALLOC(size)  _mm_malloc(size,_VU32_ALGSIZE)     
#define _VU32_ALIGNED_FREE(p)   	_mm_free(p)

#endif

void view_VU32(_VU32 *p);
void viewH_VU32(_VU32 *p);
#endif
