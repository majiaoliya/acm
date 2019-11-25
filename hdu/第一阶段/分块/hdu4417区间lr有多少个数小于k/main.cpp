#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#define MAXN 100010
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

ll T, n, m, arr[MAXN], b[MAXN], belong[MAXN], block, num, l[MAXN], r[MAXN];
ll L, R, K;

ll work(ll x, ll y, ll h) {
	ll ans = 0;
	if(belong[L] == belong[R]) {
		for( ; L<=R; L++) if(arr[L] <= K) ans ++;
		return ans;
	}
	for(int i=L; i<=r[belong[L]]; i++) if(arr[i]<=K) ans ++;
//	printf("%lld ", ans);
	for(int i=belong[L]+1; i<belong[R]; i++) {
		int lef = l[i], rig = r[i], mid, cnt = 0;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(b[mid] <= K) cnt = mid-l[i]+1, lef = mid + 1;
			if(b[mid] > K) rig = mid - 1;
		}
		ans += rig-l[i]+1;
//		printf("第%d块%d个比%lld小, ", i, cnt, K);
	}
//	printf("\n");

	for(int i=l[belong[R]]; i<=R; i++) if(arr[i]<=K) ans ++;
	return ans;
}

void reset(int k) {
	int lef = (k-1)*block+1, rig = min(k*block, n);
	sort(b+lef, b+rig+1);
	l[k] = lef, r[k] = rig;
}

int main() {
#ifdef debug
	freopen("out", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld ", &T);
	int t = 1; 
	while(t<=T) {
		printf("Case %d:\n", t);
		t ++;
		scanf("%lld %lld ", &n, &m);
		block = sqrt(n*1.);
		num = n/block;
		if(n%block) num ++;

		for(int i=1; i<=n; i++) {
			scanf("%lld ", arr+i);
			b[i] = arr[i];
			belong[i] = (i-1)/block+1;
		}
		for(int i=1; i<=num; i++) {
			reset(i);
			//l[i] = (i-1)*block+1, r[i] = i*block;
			//if(i==num) r[i] = n;
			//sort(b+l[i], b+r[i]+1);
		}

		for(int i=1; i<=m; i++) {
			scanf("%lld %lld %lld ", &L, &R, &K);
			L ++, R ++;
//			printf("query (%lld %lld )\n", L, R);
			ll ans = work(L, R, K);
			printf("%lld\n", ans);
		}
	}






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

