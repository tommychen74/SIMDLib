#include "simd_arch.h"

//dest,a,b are aligned memory
void vectorF32_add(float *dest, float *a,float *b,int N){
	if((dest==NULL)||(a==NLL)||(b==N)) return;
	_VF32 d0,d1,d2,d3,a0,a1,a2,a3,b0,b1,b2,b3;
	while(N>4*_VF32_SIZE){
		a0=_VF32_LOAD((_VF32 *)a);a+=_VF32_SIZE;
		b0=_VF32_LOAD((_VF32 *)b);b+=_VF32_SIZE;
		a1=_VF32_LOAD((_VF32 *)a);a+=_VF32_SIZE;
		b1=_VF32_LOAD((_VF32 *)b);b+=_VF32_SIZE;
		a2=_VF32_LOAD((_VF32 *)a);a+=_VF32_SIZE;
		b2=_VF32_LOAD((_VF32 *)b);b+=_VF32_SIZE;
		a3=_VF32_LOAD((_VF32 *)a);a+=_VF32_SIZE;
		b3=_VF32_LOAD((_VF32 *)b);b+=_VF32_SIZE;
			
		d0=_VF32_ADD(a0,b0);
		d1=_VF32_ADD(a1,b1);
		d2=_VF32_ADD(a2,b2);
		d3=_VF32_ADD(a3,b3);
		
		_VF32_STORE(dest,d0);dest+=_VF32_SIZE;
		_VF32_STORE(dest,d1);dest+=_VF32_SIZE;
		_VF32_STORE(dest,d2);dest+=_VF32_SIZE;
		_VF32_STORE(dest,d3);dest+=_VF32_SIZE;
		N-=4*_VF32_SIZE;
	}
	if(N>2*_VF32_SIZE){
		a0=_VF32_LOAD((_VF32 *)a);a+=_VF32_SIZE;
		b0=_VF32_LOAD((_VF32 *)b);b+=_VF32_SIZE;
		a1=_VF32_LOAD((_VF32 *)a);a+=_VF32_SIZE;
		b1=_VF32_LOAD((_VF32 *)b);b+=_VF32_SIZE;
		
		d0=_VF32_ADD(a0,b0);
		d1=_VF32_ADD(a1,b1);
		
		_VF32_STORE(dest,d0);dest+=_VF32_SIZE;
		_VF32_STORE(dest,d1);dest+=_VF32_SIZE;
		
		N-=2*_VF32_SIZE;
	}
	if(N>_VF32_SIZE){
		a0=_VF32_LOAD((_VF32 *)a);a+=_VF32_SIZE;
		b0=_VF32_LOAD((_VF32 *)b);b+=_VF32_SIZE;
	
		d0=_VF32_ADD(a0,b0);
		
		_VF32_STORE(dest,d0);dest+=_VF32_SIZE;
		
		N-=*_VF32_SIZE;
	}
	if(N==0) return;
	for(int i=0;i<N;i++){
		dest[i]=a[i]+b[i];
		dest++;a++;b++;
	}
}