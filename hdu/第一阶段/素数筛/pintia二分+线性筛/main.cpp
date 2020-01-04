#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#define MAXN ((int)1e6+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int prime[MAXN], pn, vis[MAXN], n;
void get_prime() {
	vis[0] = vis[1] = true;
	for(int i=2; i<MAXN; i++) {
		if(!vis[i]) prime[pn++] = i;
		for(int k=0; k<pn && i*prime[k]<MAXN; k++) {
			vis[i*prime[k]] = true;
			if(i%prime[k] == 0) break;
		}
	}
}

int bin_search(int key, int lef, int rig) {
	int mid;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(key == prime[mid]) return true;
		else if(key < prime[mid]) rig = mid - 1;
		else lef = mid + 1;
	}
	return false;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	get_prime();
	while(~scanf("%d ", &n) && n) {
		/**
		  O(nlogn)的老蜗牛算法
		for(int i=0; i<pn; i++) {
			int key = n - prime[i];
			if(bin_search(key, i, pn-1)) {
				printf("%d = %d + %d\n", n, prime[i], key);
				break ;
			}
		}
		*/

		//尺取法 O(n) 啥情况呀 ? 反而不如二分 ???
		int lef = 0, rig = -1;
		while(lef < pn) {
			while(rig+1<pn && prime[lef]+prime[rig+1] <= n) rig ++;
			if(n == prime[lef]+prime[rig]) {
				printf("%d = %d + %d\n", n, prime[lef], prime[rig]);
				break ;
			}
			lef ++;
		}
		
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


