#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define MAXN 100005
#define IS_PRIME(i) (vis[i]==false ? true : false)
using namespace std;

int pn, prime[MAXN], vis[MAXN], n;

void get_prime() {
	vis[0] = vis[1] = true;
	for(int i=2; i<MAXN; i++) {
		if(vis[i] == false)
			prime[pn++] = i;
		for(int k=0; k<pn && i*prime[k]<MAXN; k++) {
			vis[i*prime[k]] = true;
			if(i%prime[k] == 0) break;
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	get_prime();
	for( ; EOF != scanf("%d", &n); ) {
		for(int i=n>>1; i>=0; i--) {
			if(IS_PRIME(i) && IS_PRIME(n-i)) {
				printf("%d %d\n", i, n-i);
				break;
			}
		}
	}
	return 0;
}
