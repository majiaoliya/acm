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

int n, m;
ll arr[MAXN];

bool check(ll mid) {
	ll lst = arr[1], cnt = 1;
	for(int i=2; i<=n; i++) {
		if(arr[i]-lst < mid) cnt ++;
		else lst = arr[i];
	}
	return cnt >= m;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++) scanf("%lld ", arr+i);
	sort(arr+1, arr+1+n);
	ll lef = 0, rig = 1000000005, mid, ans = 0;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		printf("mid %lld\n", mid);
		if(check(mid)) ans = mid, rig = mid - 1;
		else lef = mid + 1;
	}
	printf("%lld\n", ans);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

