#ifndef _VF32_AVX_H_
#define _VF32_AVX_H_

#include <immintrin.h>

typedef __m256 _VF32;

//Initialize a vector
#define _VF32_SET(_a,_b,_c,_d,_e,_f,_g,_h)	_mm256_set_ps((_a),(_b),(_c),(_d),(_e),(_f),(_g),(_h))
#define _VF32_SET1(a)				_mm256_set1_ps((a))
#define _VF32_ZERO()				_mm256_setzero_ps()
#define _VF32_MOVE(__a) 			(__a)

//Arithmetic Operations
#define _VF32_ADD(__a, __b)			_mm256_add_ps((__a), (__b))
#define _VF32_SUB(__a, __b)			_mm256_sub_ps((__a), (__b))
#define _VF32_MUL(__a, __b)			_mm256_mul_ps((__a), (__b))
#define _VF32_MADD(__a, __b,__c)	_mm256_fmadd_ps ((__a), (__b), (__c)) //a*b+c

//Comparision what different for _OQ _UQ _OS _US
#define _VF32_CMPEQ(__a, __b)		_mm256_cmp_ps((__a),(__b),_CMP_EQ_OQ)
#define _VF32_CMPNE(__a, __b) 		_mm256_cmp_ps((__a),(__b),_CMP_NEQ_OQ)
#define _VF32_CMPGT(__a, __b) 		_mm256_cmp_ps((__a),(__b),_CMP_GT_OQ)
#define _VF32_CMPGE(__a, __b)		_mm256_cmp_ps((__a),(__b),_CMP_GE_OQ)
#define _VF32_CMPLT(__a, __b) 		_mm256_cmp_ps((__a),(__b),_CMP_LT_OQ)
#define _VF32_CMPLE(__a, __b) 		_mm256_cmp_ps((__a),(__b),_CMP_LE_OQ)

//Aligned Load and Store 
#define _VF32_LOAD(aAddr)			_mm256_load_ps((aAddr))
#define _VF32_STORE(aAddr, __b)		_mm256_store_ps((aAddr), (__b))

//Unligned Load and Store 
#define _VF32_LOADU(aAddr)			_mm256_loadu_ps((aAddr))
#define _VF32_STOREU(aAddr, __b)	_mm256_storeu_ps((aAddr), (__b))

#endif
