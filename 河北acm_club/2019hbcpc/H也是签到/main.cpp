#include <stdio.h>
#include <iostream>
#include <string>
//#include <math.h>
#define MAXN 105
#define ll long long
using namespace std;

ll my_pow(ll i, ll k) {
	if(!k) return 0;
	ll rs = 1;
	for( ; k--; ) 
		rs *= i;
	return rs;
}

ll sum(ll x) {
	ll rs = 0;
	while(x) {
		rs += x%10;
		x /= 10;
	}
	return rs;
}

int n, t, k;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &k);
		ll x = my_pow(n, k);
		x = sum(x);
		while(x/10) 
			x = sum(x);
		printf("%lld\n", x);
	}
	return 0;
}
