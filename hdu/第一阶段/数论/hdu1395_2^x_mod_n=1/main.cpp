#include <iostream>
#include <algorithm>
#include <math.h>
#define ll long long int
using namespace std;

ll n;

ll fp(ll a, ll b, ll mod) {
	ll rs = 1;
	while(b) {
		if(b & 1) rs = rs * a % mod;
		b >>= 1;
		a = a*a % mod;
	}
	return rs;
}

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%lld", &n)) {
		//2^x mod n = 1 如果n是偶数或1一定不成立
		if(n==1 || (n&1)==0) printf("2^? mod %lld = 1\n", n);
		else {
			for(ll i=1; ; i++) {
				ll x = fp(2, i, n);
				if(x == 1) {
					printf("2^%lld mod %lld = 1\n", i, n);
					break;
				}
			}
		}
	}
	return 0;
}
