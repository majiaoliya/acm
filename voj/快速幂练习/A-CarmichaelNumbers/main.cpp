#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 65005
#define ll long long int
using namespace std;

int n, pn, prime[MAXN];
bool vis[MAXN];

void get_prime() { //线性筛
	vis[0] = vis[1] = true;
	for(int i=2; i<MAXN; i++) {
		if(vis[i] == false)
			prime[pn++] = i;
		for(int k=0; k<pn && prime[k]*i<MAXN; k++) {
			vis[prime[k]*i] = true;
			if(i%prime[k] == 0) break;
		}
	}
}

ll fp(ll a, ll b, ll mod) { //快速幂
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
//	freopen("out", "w", stdout);
	get_prime();
	while(EOF != scanf("%d", &n) && n) {
		if(!vis[n]) {
			printf("%d is normal.\n", n);
			continue;
		}
		bool ok = true;
		for(int i=2; i<n; i++) 
			if(i != fp(i, n, n)) { ok = false; break; }
		if(ok) printf("The number %d is a Carmichael number.\n", n);
		else printf("%d is normal.\n", n);
	}
	
	return 0;
}
