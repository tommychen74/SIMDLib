#ifndef _GCC_API_H
#define _GCC_API_H
#include <malloc.h>
#define _VU32_ALIGNED_MALLOC(size)  memalign(_VU32_ALGSIZE,size)     
#define _VU32_ALIGNED_FREE(p)   	free(p)

long long int get_cycle();
long long int get_freq();

#endif