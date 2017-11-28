#ifndef _VU32_AVX512_H_
#define _VU32_AVX512_H_

#include <immintrin.h>

typedef __m512 _VF32;

//Initialize a vector
#define _VF32_SET(_a,_b,_c,_d,_a1,_b1,_c1,_d1,_a2,_b2,_c2,_d2,_a3,_b3,_c3,_d3)	_mm512_set_ps((_a),(_b),(_c),(_d),(_a1),(_b1),(_c1),(_d1),(_a2),(_b2),(_c2),(_d2),(_a3),(_b3),(_c3),(_d3))
#define _VF32_SET1(a)				_mm512_set1_ps((a))
#define _VF32_ZERO()				_mm512_setzero_ps()
#define _VF32_MOVE(__a) 			(__a)

//Arithmetic Operations
#define _VF32_ADD(__a, __b)			_mm512_add_ps((__a), (__b))
#define _VF32_SUB(__a, __b)			_mm512_sub_ps((__a), (__b))
#define _VF32_MUL(__a, __b)			_mm512_mul_ps((__a), (__b))
#define _VF32_MADD(__a, __b,__c)	_mm512_fnmadd_ps ((__a), (__b), (__c)) //a*b+c

//Comparision what different for _OQ _UQ _OS _US
/*
#define _VF32_CMPEQ(__a, __b)		_mm_cmpeq_ps((__a),(__b))
#define _VF32_CMPNE(__a, __b) 		_mm_cmpneq_ps((__a),(__b))
#define _VF32_CMPGT(__a, __b) 		_mm_cmpgt_ps((__a),(__b))
#define _VF32_CMPGE(__a, __b)		_mm_cmpge_ps((__a),(__b))
#define _VF32_CMPLT(__a, __b) 		_mm_cmplt_ps((__a),(__b))
#define _VF32_CMPLE(__a, __b) 		_mm_cmple_ps((__a),(__b))

#define _VF32_MAX(__a, __b)			_mm_max_ps((__a), (__b))
#define _VF32_MIN(__a, __b)			_mm_min_ps((__a), (__b))
*/
//Aligned Load and Store 
#define _VF32_LOAD(aAddr)			_mm512_load_ps((aAddr))
#define _VF32_STORE(aAddr, __b)		_mm512_store_ps((aAddr), (__b))

//Unligned Load and Store 
#define _VF32_LOADU(aAddr)			_mm512_loadu_ps((aAddr))
#define _VF32_STOREU(aAddr, __b)	_mm512_storeu_ps((aAddr), (__b))


#endif