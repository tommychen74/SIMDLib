#ifndef _MVS_API_H
#define _MVS_API_H

#define _VU32_ALIGNED_MALLOC(size)  _aligned_malloc(size,_VU32_ALGSIZE)     
#define _VU32_ALIGNED_FREE(p)   	_aligned_free(p)

long long int get_cycle();
long long int get_freq();
#endif