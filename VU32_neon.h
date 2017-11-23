#ifndef NEON_DSIMD_H
#define NEON_DSIMD_H

/**************************************************** NEON version *************************************************/
#include <arm_neon.h>

typedef int32x4_t _V32;
typedef uint32x4_t _VU32;

#define _VU32_SIZE 4
#define _VU32_ALGSIZE 32
#define _VU32_LOG_ALGSIZE 4

//Initialize a vector
#define _VU32_SET(_a,_b,_c,_d)		({uint32x4_t e; uint32_t *st = (uint32_t *)&e; st[0] = _a; st[1] = _b; st[2] = _c; st[3] = _d; e;})
#define _VU32_SET1(a)				vdupq_n_u32((a))
#define _VU32_ZERO()				vdupq_n_u32((0))
#define _VU32_MOVE(__a) 			(__a)
#define _V32_SET1(a) 				vdupq_n_s32((a))
//Bitwise Operations
#define _VU32_NOT(__a)				vmvnq_u32((__a))
#define _VU32_OR(__a, __b)			vorrq_u32((__a), (__b))
#define _VU32_AND(__a, __b)			vandq_u32((__a), (__b))
#define _VU32_XOR(__a, __b)			veorq_u32((__a), (__b))
#define _VU32_ANDNOT(__a, __b) 		vandq_u32((__a), veorq_u32((__b), vdupq_n_u32(0xffffffff)))  //__a AND NOT __b

#define _VU32_BSL(__a, __b, __c)	vbslq_u32((__a), (__b), (__c))
//Arithmetic Operations
#define _VU32_ADD(__a, __b)			vaddq_u32((__a), (__b))
#define _VU32_SUB(__a, __b)			vsubq_u32((__a), (__b))

//Logical Shift in the same shf_num
#define _VU32_SLLI(__a, b)			vshlq_n_u32((__a), (b))
#define _VU32_SRLI(__a, b)			vshrq_n_u32((__a), (b))
#define _VU32_SRRI(__a, b)			vrshrq_n_u32((__a), (b))

//Logical Shift in vector
#define _VU32_SLLV(__a, __b)  		vshlq_u32((__a), ((int32x4_t)(__b)))
#define _VU32_SRLV(__a, __b)		vshlq_u32((__a), vsubq_s32(vdupq_n_s32(0), (__b)))
#define _VU32_SRRV(__a, __b)		vorrq_u32((vshlq_u32((__a), ((int32x4_t)(vsubq_u32((vdupq_n_u32(32)), (__b)))))), (vshlq_u32((__a), ((int32x4_t)vsubq_u32((vdupq_n_u32((32))), (__b))))))

//Comparision
#define _VU32_CMPEQ(__a, __b)		vceqq_u32((__a), (__b))	
#define _VU32_CMPNE(__a, __b) 		vmvnq_u32((vceqq_u32((__a), (__b))))
#define _VU32_CMPGT(__a, __b) 		vcgtq_u32((__a) ,(__b))
#define _VU32_CMPGE(__a, __b)		vcgeq_u32((__a), (__b))
#define _VU32_CMPLT(__a, __b) 		vcltq_u32((__a), (__b))
#define _VU32_CMPLE(__a, __b) 		vcleq_u32((__a), (__b))

#define _VU32_MAX(__a, __b)			vmaxq_u32((__a), (__b))
#define _VU32_MIN(__a, __b) 		vminq_u32((__a), (__b))

#define _VU32_EQ(__a,__b)			vtstq_u32((__a), (__b))

//Aligned Load and Store 
#define _VU32_LOAD(aAddr)			vld1q_u32((aAddr))
#define _VU32_STORE(__b, aAddr)		vst1q_u32((aAddr), (__b))

//Unligned Load and Store 
#define _VU32_LOADU(aAddr)	
#define _VU32_STOREU(aAddr, __b)	

#define _U32_LZCNT(__a)				vclzq_u32((__a))

#define _VU32_GATHER(__a, aAddr, b)	({uint32x4_t c; uint32_t *st1 = (uint32_t *)&__a; uint32_t *st2 = (uint32_t *)&c; \
									  for(int i = 0; i < b; i++)\
									  st2[i] = aAddr[st1[i]]; c;})

#endif
