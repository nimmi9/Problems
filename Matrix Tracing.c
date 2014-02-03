#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE_MplusN 10000000
#define MAX_SIZE 1000000
unsigned long long PRIME = 1000000007;
unsigned long long Fact[MAX_SIZE_MplusN];
unsigned long long iFact[MAX_SIZE];
unsigned long long NpowMmoduloP(unsigned long long,unsigned long long);
unsigned long long Amodulo_inverseP(unsigned long long);
void preProcessing();
int main() {
	unsigned int T,m,n,i;
	preProcessing();
	i = scanf("%u",&T);
	while(T--){
		i = scanf("%u",&m);
		i = scanf("%u",&n);
		m--;
		n--;
		printf("%llu\n",(((Fact[m+n]*iFact[m])%PRIME)*iFact[n])%PRIME);
	}
	return 0;
}


void preProcessing(){
	unsigned long long i=2;
	Fact[0] = 1;
	iFact[0] = 1;
	Fact[1] = 1;
	iFact[1] = 1;
	while(i<MAX_SIZE_MplusN){
		Fact[i] = (Fact[i-1]*i)%PRIME; 
		i++;
	}
	i = 2;
	while(i<MAX_SIZE){
		iFact[i] = ( Amodulo_inverseP(i) * iFact[i-1] ) % PRIME;
		i++;
	}
}

unsigned long long Amodulo_inverseP(unsigned long long A){
	return NpowMmoduloP(A,PRIME-2);
}

unsigned long long NpowMmoduloP(unsigned long long N,unsigned long long M){
	unsigned long long square;
	if(M == 1){
		return N%PRIME;
	}
	square = NpowMmoduloP(N,M>>1);
	square = (square * square) % PRIME;
	if(M&1){
		return (square*N) % PRIME;
	}else{
		return square;
	}
}
