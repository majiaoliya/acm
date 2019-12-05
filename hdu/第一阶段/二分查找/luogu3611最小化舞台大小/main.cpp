#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

ll n, m, K, arr[MAXN];

bool check(ll mid) {
	int cnt = 0, lst = 0;
	for(int i=1; i<(m+2); i++)
		if(arr[i]-arr[lst] < mid) cnt ++;
		else lst = i;
//	printf("mid:%lld del:%d\n", mid, cnt);
	return cnt <= K;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld %lld %lld ", &n, &m, &K);
	for(int i=1; i<=m; i++) scanf("%lld ", arr+i);
	sort(arr+1, arr+1+m);
	arr[m+1] = n;
	ll lef = 0, rig = n+7, mid, ans = 0;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(check(mid)) ans = mid, lef = mid + 1;
		else rig = mid - 1;
	}
	printf("%lld\n", ans);


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


