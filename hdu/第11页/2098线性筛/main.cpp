#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 10005
using namespace std;

int n, t;
int pn, prime[MAXN];
bool vis[MAXN];

void get_prime() {
	vis[0] = vis[1] = true;
	for(int i=2; i<MAXN; i++) {
		if(vis[i] == false)
			prime[pn++] = i;
		for(int k=0; k<pn && prime[k]*i<MAXN; k++) {
			vis[prime[k]*i] = true;
			if(i%prime[k] == false) break;
		}
	}
}
int main(void) {
	freopen("test", "r", stdin);
	get_prime();
//	for(int i=0; i<pn; i++)
//		printf("%d ", prime[i]);
	while(cin>>n && n) {
		int cnt = 0;
		for(int i=0; i<pn && prime[i]<(n>>1); i++) {
			if(vis[n-prime[i]] == false) {
//				printf("%d = %d + %d\n", n, prime[i], n-prime[i]);
				cnt ++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
