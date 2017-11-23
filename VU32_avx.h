#ifndef _VU32_AVX_H_
#define _VU32_AVX_H_

#include <immintrin.h>
#include <stdlib.h>
#include <stdio.h>
typedef __m256i _VU32;
#define _VU32_SIZE 8
#define _VU32_ALGSIZE 32
#define _VU32_LOG_ALGSIZE 5

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
//Initialize a vector
#define _VU32_SET(_a,_b,_c,_d,_e,_f,_g,_h)	_mm256_set_epi32((_a),(_b),(_c),(_d),(_e),(_f),(_g),(_h))
#define _VU32_SET1(a)				_mm256_set1_epi32((a))
#define _VU32_ZEOR()				_mm256_setzero_si256()
#define _VU32_MOVE(__a) 			(__a)
//Bitwise Operations
#define _VU32_NOT(__a)				_VU32_XOR((__a), _VU32_SET1(0xFFFFFFFF))
#define _VU32_OR(__a, __b)			_mm256_or_si256((__a), (__b))
#define _VU32_AND(__a, __b)			_mm256_and_si256((__a), (__b))
#define _VU32_XOR(__a, __b)			_mm256_xor_si256((__a), (__b))
#define _VU32_ANDNOT(__a, __b) 		_mm256_andnot_si256((__b), (__a))  //__a AND NOT __b
//Arithmetic Operations
#define _VU32_ADD(__a, __b)			_mm256_add_epi32((__a), (__b))
#define _VU32_SUB(__a, __b)			_mm256_sub_epi32((__a), (__b))

//Logical Shift
#define _VU32_SLLI(__a, b)			_mm256_slli_epi32((__a), (b))
#define _VU32_SRLI(__a, b)			_mm256_srli_epi32((__a), (b))
#define _VU32_SRRI(__a, b)			_VU32_OR(_VU32_SLLI((__a),(32-(b))),_VU32_SRLI(__a, b))

#define _VU32_SLLV(__a, __b)  		_mm256_sllv_epi32((__a),(__b))
#define _VU32_SRLV(__a, __b)		_mm256_srlv_epi32((__a),(__b))
#define _VU32_SRRV(__a, __b)
//Comparision
#define _VU32_CMPEQ(__a, __b)		_mm256_cmpeq_epi32((__a),(__b))
#define _VU32_CMPNE(__a, __b) 		_VU32_NOT(_VU32_CMPEQ(__a, __b))
#define _VU32_CMPGT(__a, __b) 		_mm256_cmpgt_epi32((__a),(__b))
#define _VU32_CMPGE(__a, __b)		_VU32_OR(_VU32_CMPEQ((__a),(__b)),_VU32_CMPGT((__a),(__b)))
#define _VU32_CMPLT(__a, __b) 		
#define _VU32_CMPLE(__a, __b) 		_VU32_NOT(_VU32_CMPGT(__a, __b))

#define _VU32_MAX(__a, __b)			_mm256_max_epu32((__a),(__b))
#define _VU32_MIN(__a, __b) 		_mm256_min_epu32((__a),(__b))

#define _VU32_EQ(__a,__b)			_mm256_testz_si256((__a),(__b))

//Load and Store
#define _VU32_LOAD(aAddr)			_mm256_load_si256((aAddr))
#define _VU32_STORE(aAddr, __b)		_mm256_store_si256((aAddr), (__b))

#define _VU32_PACKLOAD(aAddr)		_mm256_loadu_si256((aAddr))
#define _VU32_PACKSTORE(aAddr, __b)	_mm256_storeu_si256((aAddr), (__b))

#define _U32_LZCNT(__a)				_lzcnt_u32((__a))


#endif
