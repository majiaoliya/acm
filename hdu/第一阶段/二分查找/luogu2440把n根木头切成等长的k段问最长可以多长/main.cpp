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
 * 给定n,k, 把n根长度不一的木头成等长的k段, 求这k段木头的最大长度
 * 二分,如果用n根木头切成mid长度的子段数量大于等于k就尝试更大的mid值
 * 1e5个1e9相加是否爆int ?
 * 不知道,开longlong保险一点
 */

ll T, n, K, arr[MAXN];

bool check(ll mid) {
	ll ret = 0;
	for(ll i=1; i<=n; i++)
		ret += arr[i]/mid;
	return ret >= K;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld %lld ", &n, &K);
	ll sum = 0;
	for(int i=1; i<=n; i++) {
		scanf("%lld ", arr+i);
		sum += arr[i];
	}

	int lef = 1, rig = sum+1, mid, ans = 0;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(check(mid)) ans = mid, lef = mid + 1;
		else rig = mid - 1;
	}
	printf("%d\n", ans);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

