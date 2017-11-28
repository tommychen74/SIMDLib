#include "simd_arch.h"

//dest,a,b are aligned memory
void vectorF32_add(float *dest, float *a,float *b,int N){
	if((dest==NULL)||(a==NULL)||(b==NULL)) return;
	_VF32 d0, d1, d2, d3, a0, a1, a2, a3, b0, b1, b2, b3;
	while(N>=4*_VF32_SIZE){
		a0=_VF32_LOAD(a);a+=_VF32_SIZE;
		b0=_VF32_LOAD(b);b+=_VF32_SIZE;
		a1=_VF32_LOAD(a);a+=_VF32_SIZE;
		b1=_VF32_LOAD(b);b+=_VF32_SIZE;
		a2=_VF32_LOAD(a);a+=_VF32_SIZE;
		b2=_VF32_LOAD(b);b+=_VF32_SIZE;
		a3=_VF32_LOAD(a);a+=_VF32_SIZE;
		b3=_VF32_LOAD(b);b+=_VF32_SIZE;
			
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
	if(N>=2*_VF32_SIZE){
		a0=_VF32_LOAD(a);a+=_VF32_SIZE;
		b0=_VF32_LOAD(b);b+=_VF32_SIZE;
		a1=_VF32_LOAD(a);a+=_VF32_SIZE;
		b1=_VF32_LOAD(b);b+=_VF32_SIZE;
		
		d0=_VF32_ADD(a0,b0);
		d1=_VF32_ADD(a1,b1);
		
		_VF32_STORE(dest,d0);dest+=_VF32_SIZE;
		_VF32_STORE(dest,d1);dest+=_VF32_SIZE;
		
		N-=2*_VF32_SIZE;
	}
	if(N>=_VF32_SIZE){
		a0=_VF32_LOAD(a);a+=_VF32_SIZE;
		b0=_VF32_LOAD(b);b+=_VF32_SIZE;
	
		d0=_VF32_ADD(a0,b0);
		
		_VF32_STORE(dest,d0);dest+=_VF32_SIZE;
		
		N-=_VF32_SIZE;
	}
	if(N==0) return;
	for(int i=0;i<N;i++){
		dest[i]=a[i]+b[i];
		dest++;a++;b++;
	}
}
void matrixF32_setzero(float *d,int N){
	float *dp=d;
	_VF32 z = _VF32_ZERO();
	for (int i = 0; i < _VF32_SIZE; i++){
		_VF32_STORE(dp, z); dp += N;
	}
}
void matrixF32_madd(float *d, float *a, float *b, int N){
	int w = _VF32_SIZE / 4;
	float *dp=d, *ap0=a, *bp=b;
	_VF32 a0, a1, a2, a3, b0, b1, b2, b3, d0, d1, d2, d3;
	for (int i = 0; i < w; i++){
		b0 = _VF32_LOAD(bp); bp += N;
		b1 = _VF32_LOAD(bp); bp += N;
		b2 = _VF32_LOAD(bp); bp += N;
		b3 = _VF32_LOAD(bp); bp += N;
		ap0 = a + 4 * i;
		dp = d;
		for (int s = 0; s < w; s++){
			float *dp1 = dp;
			float *ap;
			ap = ap0;
			d0 = _VF32_LOAD(dp); dp += N;
			d1 = _VF32_LOAD(dp); dp += N;
			d2 = _VF32_LOAD(dp); dp += N;
			d3 = _VF32_LOAD(dp); dp += N;
//Column1----------------------------------------------
			a0 = _VF32_SET1(ap[0]); 
			a1 = _VF32_SET1(ap[N]); 
			a2 = _VF32_SET1(ap[2*N]); 
			a3 = _VF32_SET1(ap[3*N]); ap ++;
#ifndef MADD_ENABLE
			a0 = _VF32_MUL(a0, b0);	a1 = _VF32_MUL(a1, b0);
			a2 = _VF32_MUL(a2, b0);	a3 = _VF32_MUL(a3, b0);

			d0 = _VF32_ADD(a0, d0);	d1 = _VF32_ADD(a1, d1);
			d2 = _VF32_ADD(a2, d2);	d3 = _VF32_ADD(a3, d3);
#else
			d0 = _VF32_MADD(a0, b0, d0); d1 = _VF32_MADD(a1, b0, d1);
			d2 = _VF32_MADD(a2, b0, d2); d3 = _VF32_MADD(a3, b0, d3);
#endif

//Column2-----------------------------------------------
			a0 = _VF32_SET1(ap[0]);
			a1 = _VF32_SET1(ap[N]);
			a2 = _VF32_SET1(ap[2 * N]);
			a3 = _VF32_SET1(ap[3 * N]); ap ++;

#ifndef MADD_ENABLE
			a0 = _VF32_MUL(a0, b1);	a1 = _VF32_MUL(a1, b1);
			a2 = _VF32_MUL(a2, b1);	a3 = _VF32_MUL(a3, b1);

			d0 = _VF32_ADD(a0, d0);	d1 = _VF32_ADD(a1, d1);
			d2 = _VF32_ADD(a2, d2);	d3 = _VF32_ADD(a3, d3);
#else
			d0 = _VF32_MADD(a0, b1, d0); d1 = _VF32_MADD(a1, b1, d1);
			d2 = _VF32_MADD(a2, b1, d2); d3 = _VF32_MADD(a3, b1, d3);
#endif
//Column3----------------------------------------------
			a0 = _VF32_SET1(ap[0]);
			a1 = _VF32_SET1(ap[N]);
			a2 = _VF32_SET1(ap[2 * N]);
			a3 = _VF32_SET1(ap[3 * N]); ap++;
#ifndef MADD_ENABLE
			a0 = _VF32_MUL(a0, b2);		a1 = _VF32_MUL(a1, b2);
			a2 = _VF32_MUL(a2, b2);		a3 = _VF32_MUL(a3, b2);

			d0 = _VF32_ADD(a0, d0);		d1 = _VF32_ADD(a1, d1);
			d2 = _VF32_ADD(a2, d2);		d3 = _VF32_ADD(a3, d3);
#else
		d0 = _VF32_MADD(a0, b2, d0); d1 = _VF32_MADD(a1, b2, d1);
		d2 = _VF32_MADD(a2, b2, d2); d3 = _VF32_MADD(a3, b2, d3);
#endif
//Column4----------------------------------------------
			a0 = _VF32_SET1(ap[0]);
			a1 = _VF32_SET1(ap[N]);
			a2 = _VF32_SET1(ap[2 * N]);
			a3 = _VF32_SET1(ap[3 * N]); ap++;
#ifndef MADD_ENABLE
			a0 = _VF32_MUL(a0, b3);	a1 = _VF32_MUL(a1, b3);
			a2 = _VF32_MUL(a2, b3);	a3 = _VF32_MUL(a3, b3);

			d0 = _VF32_ADD(a0, d0);	d1 = _VF32_ADD(a1, d1);
			d2 = _VF32_ADD(a2, d2);	d3 = _VF32_ADD(a3, d3);
#else
			d0 = _VF32_MADD(a0, b3, d0); d1 = _VF32_MADD(a1, b3, d1);
			d2 = _VF32_MADD(a2, b3, d2); d3 = _VF32_MADD(a3, b3, d3);
#endif
//-------------------------------------------------------
			_VF32_STORE(dp1,d0); dp1 += N;
			_VF32_STORE(dp1,d1); dp1 += N;
			_VF32_STORE(dp1,d2); dp1 += N;
			_VF32_STORE(dp1,d3); dp1 += N;
			ap0 += 4 * N;
		}

	}
}