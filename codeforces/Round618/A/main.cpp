//#define debug
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
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

ll n, m, T, a, b, x;

/**
 * 题意: 给定一个数组arr[], 可以给某一个数字加一,求最小操作次数使得arr乘积不为0并且
 *       arr和不为0
 * 思路: 每个数只要为0就操作一次,和为0再操作一次
 */

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld ", &T);
	while(T--) {
		scanf("%lld ", &n);
		ll ans = 0, sum = 0;
		for(int i=1; i<=n; i++) {
			scanf("%lld ", &x);
			if(!x) ans ++, x ++;
			sum += x;
		}
		if(!sum) ans ++;
		printf("%lld\n", ans);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

