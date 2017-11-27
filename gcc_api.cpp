
#ifdef _x86_PERFORMANCE
long long int get_cycle(){
	unsigned int lo,hi;                           
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo; 
}
long long int get_freq(){
}
#endif
#ifdef _ARM_PERFORMANCE
long long int get_cycle(){
}
long long int get_freq(){
}
#endif
