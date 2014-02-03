#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 501
#define MAX_LEVEL 13
unsigned long long a[MAX_SIZE];
void setArray(long long unsigned n, int level);
void resetArray();
int main(){
	int T,N,rc;
	resetArray();
	setArray(9,0);
	rc = scanf("%d",&T);
	while(T--){
		rc = scanf("%d",&N);
		printf("%llu\n",a[N]);
	}
	return 0;
}
void resetArray(){
	int i;
	for(i=0;i<MAX_SIZE;i++){
		a[i] = 0xffffffffffffffff;
	}
}
void setArray(long long unsigned n, int level){
	long long unsigned i;
	if(level >= MAX_LEVEL ){
		return;
	}
	for(i=1;i<MAX_SIZE;i++){
		if(!(n%i)){
			if(a[i] > n){
				a[i] = n;
			}
		}
	}
	setArray(n*10,level+1);
	setArray(n*10+9,level+1);
}