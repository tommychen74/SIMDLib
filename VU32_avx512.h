#ifndef _VU32_AVX512_H_
#define _VU32_AVX512_H_

#include <immintrin.h>

typedef __m512i _VU32;
#define _VU32_SIZE 16
#define _VU32_ALGSIZE 64
#define _VU32_LOG_ALGSIZE 6


//Initialize a vector
#define _VU32_SET(_a,_b,_c,_d,_e,_f,_g,_h,_a1,_b1,_c1,_d1,_e1,_f1,_g1,_h1)	_mm512_set_epi32((_a),(_b),(_c),(_d),(_e),(_f),(_g),(_h),(_a1),(_b1),(_c1),(_d1),(_e1),(_f1),(_g1),(_h1))
#define _VU32_SET1(a)				_mm512_set1_epi32((a))
#define _VU32_ZEOR()				_mm512_setzero_si256()
#define _VU32_MOVE(__a) 			(__a)

//Bitwise Operations
#define _VU32_AND(__a, __b)			_mm512_and_si512((__a), (__b))
#define _VU32_ANDNOT(__a, __b) 		_mm512_andnot_si512((__b), (__a))  //__a AND NOT __b
#define _VU32_OR(__a, __b)			_mm512_or_si512((__a), (__b))
#define _VU32_XOR(__a, __b)			_mm512_xor_si512((__a), (__b))
#define _VU32_NOT(__a)				_VU32_XOR((__a), _VU32_SET1(0xFFFFFFFF))

//Arithmetic Operations
#define _VU32_ADD(__a, __b)			_mm512_add_epi32((__a), (__b))
#define _VU32_SUB(__a, __b)			_mm512_sub_epi32((__a), (__b))

//Logical Shift in the same shf_num
#define _VU32_SLLI(__a, b)			_mm512_slli_epi32((__a), (b))	//Logic left shift
#define _VU32_SRLI(__a, b)			_mm512_srli_epi32((__a), (b))	//Logic right shift
#define _VU32_SRRI(__a, b)			_mm512_ror_epi32((__a),32-(b))  //Rotate right shift

//Logical Shift in vector
#define _VU32_SLLV(__a, __b)  		_mm512_sllv_epi32((__a),(__b))	//Logic left shift	
#define _VU32_SRLV(__a, __b)		_mm512_srlv_epi32((__a),(__b))	//Logic right shift
#define _VU32_SRRV(__a, __b) 		_mm512_rorv_epi32((__a),(__b))	//Rotate right shift

//Comparision
/*In AVX512 comparison result is in mask register
#define _VU32_CMPEQ(__a, __b)		_mm256_cmpeq_epi32((__a),(__b))
#define _VU32_CMPNE(__a, __b) 		_VU32_NOT(_VU32_CMPEQ(__a, __b))
#define _VU32_CMPGT(__a, __b) 		_mm256_cmpgt_epi32((__a),(__b))
#define _VU32_CMPGE(__a, __b)		_VU32_OR(_VU32_CMPEQ((__a),(__b)),_VU32_CMPGT((__a),(__b)))
#define _VU32_CMPLT(__a, __b) 		_VU32_ANDNOT(_VU32_NOT(_VU32_CMPGT(__a, __b)),_VU32_CMPEQ(__a, __b)))
#define _VU32_CMPLE(__a, __b) 		_VU32_NOT(_VU32_CMPGT(__a, __b))
*/
//Min and Max
/*Not supported?
#define _VU32_MAX(__a, __b)			_mm256_max_epu32((__a),(__b))
#define _VU32_MIN(__a, __b) 		_mm256_min_epu32((__a),(__b))
*/
//if __a==__b return 1; else return 0
/*Not supported?
#define _VU32_EQ(__a,__b)			_mm256_testz_si256((__a),(__b))
*/
//Aligned Load and Store 
#define _VU32_LOAD(aAddr)			_mm512_load_si512((aAddr))
#define _VU32_STORE(aAddr, __b)		_mm512_store_si512((aAddr), (__b))

//Unligned Load and Store 
#define _VU32_LOADU(aAddr)			_mm512_loadu_si512((aAddr))
#define _VU32_STOREU(aAddr, __b)	_mm512_storeu_si512((aAddr), (__b))

//Lead Zero Count
/*Support?
#define _U32_LZCNT(__a)				_lzcnt_u32((__a))
*/
#endif
