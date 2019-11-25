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
#define ll long long 

ll fp(ll a, ll b, ll mod) { // 1e9
	ll rs = 1;
	while(b) {
		if(b & 1) rs = rs*a%mod;
		b >>= 1;
		a = a*a%mod;
	}
	return rs;
}

/**
  求a, 2a, 4a, 8a, 16a 
  快速乘法
 */
 ll mul(ll a, ll b, ll mod) {
 	ll rs = 0;
 	while(b) {
 		if(b & 1) rs = (rs+a)%mod;
 		b >>= 1;
 		a = (a+a) % mod;
 	}
 	return rs;
 }

int main(){

	printf("%lld\n", fp(3, 2, 10));
	printf("%lld\n", mul(3, 2, 10));
}
