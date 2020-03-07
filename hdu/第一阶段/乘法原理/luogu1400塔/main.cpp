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
#include <set>
#include <stack>
#include <queue>
#define MAXN ((int)6e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 
 * 有N(2<=N<=600000)块砖，要搭一个N层的塔，
 * 要求：如果砖A在砖B上面，那么A不能比B的长度+D要长。
 * 问有几种方法,输出 答案 mod 1000000009的值.
 * 
 * 对于每一个砖, 可以把他插入长度比它大d以内的所有砖上,不管原来的塔形状如何
 * 都不会影响他的插入位置
 * 乘法原理
 */

ll n, d, arr[MAXN];

int binsearch(ll* a, int lef, int rig, ll key) { //二分右边界
	int mid = (lef + rig) >> 1, ret = -1;
	while(lef<=rig) {
		mid = (lef + rig) >> 1;
		if(a[mid] <= key) ret = mid, lef = mid + 1;
		else rig = mid - 1;
	}
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld %lld ", &n, &d);
	for(int i=1; i<=n; i++) scanf("%lld ", arr+i);
	sort(arr+1, arr+1+n);
	ll ans = 1, mod = 1000000009;
	for(int i=1; i<=n; i++) { //第i块砖的方案个数
		int rig = binsearch(arr, i, n, arr[i]+d);
		if(~rig) {
			ans *= (rig-i+1); //乘法原理
			ans %= mod;
		}
	}
	printf("%lld\n", ans%mod);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


