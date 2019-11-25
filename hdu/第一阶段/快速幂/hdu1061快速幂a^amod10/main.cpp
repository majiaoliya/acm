
#include<stdio.h>
#include <math.h>
#define ll long long 

int t;

ll fp(ll a, ll b, ll mod=1000000007) {
	ll rs = 1;
	while(b) {
		if(b & 1) rs = rs*a % mod;
		b >>= 1;
		a = a*a%mod;
	}
	return rs;
}

int main(){
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		int x;
		scanf("%d", &x);
		printf("%lld\n", fp(x, x, 10));
	}
}
