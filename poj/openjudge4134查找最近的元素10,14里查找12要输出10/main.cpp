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
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

ll n, arr[MAXN], q, x;

ll slove(ll x) {
	ll lef = 1, rig = n, mid, l = 0, r = 0;
	while(lef <= rig) { //找到第一个大于x的数
		mid = (lef + rig) >> 1;
		if(arr[mid] > x) r = mid, rig = mid - 1;
		else lef = mid + 1;
	}
	lef = 1, rig = n;
	while(lef <= rig) { //找到最后一个小于等于x的数
		mid = (lef + rig) >> 1;
		if(arr[mid] <= x) l = mid, lef = mid + 1;
		else rig = mid - 1;
	}
	if(!l) return arr[1];
	if(!r) return arr[n];
	//一定要等于的情况 10 14 之间 key=12应该输出10
	return abs(x-arr[l]) <= abs(x-arr[r]) ? arr[l] : arr[r];
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld ", &n);
	for(int i=1; i<=n; i++) scanf("%lld ", arr+i);
	scanf("%lld ", &q);
	while(q--) {
		scanf("%lld ", &x);
		printf("%lld\n", slove(x));
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


