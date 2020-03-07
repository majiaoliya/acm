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

ll n, m, T, a, b;

/**
 * 题意: 要修长度为n的路, 连续a天好天气,接下来连续b天坏天气(ab不断重复)
 *       每天修1段,好天气修好路,坏天气修坏路,要保证一半的路是好路
 *       问要修最少多少天
 * 思路: 二分答案 check(mid)判断mid天是否可以修完至少一半的好路
 */

bool check(ll mid) { //判断mid天是否可以至少一半的好路
	ll sum = a + b;
	ll ans = (mid / sum) * a;
	ans += min(a, mid%sum);
	return ans>=((n+1)>>1) && mid>=n;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld ", &T);
	while(T--) {
		scanf("%lld %lld %lld ", &n, &a, &b);
		ll lef = 0, rig = 1e18, mid, ans = 0;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(check(mid)) ans = mid, rig = mid - 1;
			else lef = mid + 1;
		}
		printf("%lld\n", ans);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

