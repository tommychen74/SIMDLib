#include "stdafx.h"
#include <windows.h>

long long int get_cycle(){
	LARGE_INTEGER Time;
	QueryPerformanceCounter(&Time);
	return Time.QuadPart;
}
long long int get_freq(){
	LARGE_INTEGER nFreq;
	QueryPerformanceFrequency(&nFreq);
	return nFreq.QuadPart;
}