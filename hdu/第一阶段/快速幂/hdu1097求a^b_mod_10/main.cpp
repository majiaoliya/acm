#include<stdio.h>
#include <math.h>
#define ll long long 

ll fp(ll a, ll b, ll mod) {
	ll ret = 1;
	while(b) {
		if(b&1) ret = ret*a % mod;
		b >>= 1;
		a = a*a % mod;
	}
	return ret;
}

int main(){
	freopen("test", "r", stdin);
	ll a, b;
	while(~scanf("%lld %lld", &a, &b)) {
		printf("%lld\n", fp(a, b, 10));
	}
	return 0;
}
