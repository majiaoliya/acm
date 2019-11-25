#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define MAXN 1000000005
using namespace std;

//线性筛法求素数

int* prime = new int[MAXN], *vis = new int[MAXN], pn = 0, n = MAXN;

void func() {
	for(int i=2; i<=n; i++) {
		if(vis[i]) continue ;
		prime[pn++] = i;
		for(int k=0; k<pn && i*prime[k]<=n; k++) {
			vis[i*prime[k]] = true;
			if(i%prime[k]) break;
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	
	int n;
	func();
	printf("%d", pn);
//	while(scanf("%d", &n) && n) {
//		int cnt = 0;
//		for(int i=0; i<pn; i++) {
////			if(prime[i] > n) break;
////			else cnt ++;
//			printf("%d,", prime[i]);
//		}
//		printf("%d\n", cnt);
//	}
	
	return 0;
}
