/*
#include<stdio.h>

#define M 1000000007

int fp(int a,int b){
    long long ret=1,pow=a;//ret：返回值；pow：基底
    while(b!=0){
		if(b&1) ret=(ret*pow)%M; 
		pow=(pow*pow)%M;
		b>>=1;//相当于b>>1
    }
	return (int)ret;
}

int main(){

    int a,b;

    scanf("%d%d",&a,&b);

    printf("%d\n",fp(a,b));

}

*/

#include<stdio.h>
#include <math.h>

#define M 1000000007

long long fp(long long x, long long y) {
	long long rs = 1;
	while(y) {
		if(y%2 == 1) rs *
	}
}

int main(){

    

}
