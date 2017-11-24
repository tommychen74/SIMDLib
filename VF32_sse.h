#ifndef _VF32_AVX_H_
#define _VF32_AVX_H_

#include <immintrin.h>

typedef __m128 _VF32;

//Initialize a vector
#define _VF32_SET(_a,_b,_c,_d)	_mm_set_ps((_a),(_b),(_c),(_d))
#define _VF32_SET1(a)				_mm_set1_ps((a))
#define _VF32_ZEOR()				_mm_setzero_ps()
#define _VF32_MOVE(__a) 			(__a)

//Arithmetic Operations
#define _VF32_ADD(__a, __b)			_mm_add_ps((__a), (__b))
#define _VF32_SUB(__a, __b)			_mm_sub_ps((__a), (__b))
#define _VF32_MUL(__a, __b)			_mm_mul_ps((__a), (__b))
#define _VF32_MADD(__a, __b,__c)	_mm_add_ps (_mm_mul_ps((__a), (__b)), (__c)) //a*b+c

//Comparision what different for _OQ _UQ _OS _US
#define _VF32_CMPEQ(__a, __b)		_mm_cmpeq_ps((__a),(__b))
#define _VF32_CMPNE(__a, __b) 		_mm_cmpneq_ps((__a),(__b))
#define _VF32_CMPGT(__a, __b) 		_mm_cmpgt_ps((__a),(__b))
#define _VF32_CMPGE(__a, __b)		_mm_cmpge_ps((__a),(__b))
#define _VF32_CMPLT(__a, __b) 		_mm_cmplt_ps((__a),(__b))
#define _VF32_CMPLE(__a, __b) 		_mm_cmple_ps((__a),(__b))

#define _VF32_MAX(__a, __b)			_mm_max_ps((__a), (__b))
#define _VF32_MIN(__a, __b)			_mm_min_ps((__a), (__b))

//Aligned Load and Store 
#define _VF32_LOAD(aAddr)			_mm_load_ps((aAddr))
#define _VF32_STORE(aAddr, __b)		_mm_store_ps((aAddr), (__b))

//Unligned Load and Store 
#define _VF32_LOADU(aAddr)			_mm_loadu_ps((aAddr))
#define _VF32_STOREU(aAddr, __b)	_mm_storeu_ps((aAddr), (__b))

#endif
