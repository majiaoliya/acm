
#include <iostream> 
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;
#include <iostream>
#include <math.h>
#include <vector>
#define MAXN 1000005
#define ll long long int
using namespace std;

int prime[MAXN], pn;
bool vis[MAXN];

void get_prime(int maxn) {
	for(int i=2; i<=maxn; i++) {
		if(vis[i] == false)
			prime[pn++] = i;
		for(int k=0; k<pn && prime[k]*i<=maxn; k++) {
			vis[prime[k]*i] = true;
			if(i%prime[k] == 0) break;
		}
	}
}

ll fp(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

int main(void) {
//	freopen("test", "r", stdin);
	get_prime(50000);
	int tn = 120;
	for(int i=0; i<pn; i++) {
		int p = prime[i], s = 0;
		for(int k=p; )
		if(s)
			printf("%d %d\n", p, s);
	}	
	return 0;
}


