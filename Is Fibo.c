#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 64
unsigned long F[MAX_SIZE];
int bSearch(unsigned long,int,int);
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    unsigned long T,N;
    int i;
    F[0] = 0;
    F[1] = 1;
    i = 2;
    while(i<MAX_SIZE){
        F[i] = F[i-1] + F[i-2];
        i++;
    }
    i = scanf("%lu",&T);
    while(T--){
        i = scanf("%lu",&N);
        if(bSearch(N,0,MAX_SIZE)){
            printf("IsFibo\n");
        }else{
            printf("IsNotFibo\n");
        }
    }
    return 0;
}

int bSearch(unsigned long N,int l,int h){
    int m;
    if(l>h){
        return 0;
    }
    m = (l+h)/2;
    if(F[m] == N){
        return 1;
    }else if(F[m] > N){
        return bSearch(N,l,m-1);
    }else{
        return bSearch(N,m+1,h);
    }
    
}
