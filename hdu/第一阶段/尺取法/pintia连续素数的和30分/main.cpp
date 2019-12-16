#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100050
#include <map>
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 有一些正整数可以分解为一个或连续多个素数的和。给定一个正整数，有多少种可能的分解方式？例如，53可以分解为 5 + 7 + 11 + 13 + 17和53。整数41有三种分解方式，即2+3+5+7+11+13, 11+13+17和41。而整数3只有一种分解方式，即3。整数20无法分解为连续素数的和。 注意：在分解一个整数时，素数必须是连续的, 因此7 + 13 和 3 + 5 + 5 + 7 都不是20的有效分解方式，因为7和13之间有一个素数11，而 3 + 5 + 5 + 7这种分解方式中5重复出现了。
请编写一个程序，对于给定的一个正整数，输出其有效的分解方式有多少。
 */

int n, m, prime[MAXN], pn, vis[MAXN], psum[MAXN];

void get_prime() {
	vis[0] = vis[1] = true;
	for(int i=2; i<MAXN; i++) {
		if(!vis[i]) prime[++pn] = i;
		for(int k=1; k<=pn && prime[k]*i<MAXN; k++) {
			vis[i*prime[k]] = true;
			if(i%prime[k] == 0) break; 
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	/**
	 * 思路一: 线性筛+前缀和+二分 复杂度O(q*nlogn)
	 */
	/*
	get_prime();
	for(int i=0; i<MAXN; i++) 
		psum[i] = psum[i-1] + prime[i];
	while(~scanf("%d ", &n) && n) {
		int ans = 0;
		for(int i=1; i<=pn && prime[i]<=n; i++) { //枚举左端点
			int key = psum[i-1] + n; 
			int lef = i, rig = pn, mid, ok = 0;
			while(lef <= rig) { //二分右端点
				mid = (lef + rig) >> 1;
				if(psum[mid] == key) { ok = true; break; }
				else if(psum[mid] > key) rig = mid - 1;
				else lef = mid + 1;
			}
			ans += ok;
		}
		printf("%d\n", ans);
	}
	*/

	/**
	 * 思路二:尺取法 复杂度O(q*n)
	 */
	get_prime();
	while(~scanf("%d ", &n) && n) {
		int ans = 0, sum = 0;
		int lef = 1, rig = 0;
		while(lef <= MAXN && prime[lef]<=n) {
			while(rig+1<=MAXN && sum+prime[rig+1]<=n) {
				sum += prime[++rig];
			}
			if(sum == n) ans ++;
			sum -= prime[lef++];
		}
		printf("%d\n", ans);
	}





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


