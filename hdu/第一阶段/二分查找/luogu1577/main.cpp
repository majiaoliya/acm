#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 200005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, l[MAXN], r[MAXN], len[MAXN];

bool check(long double k) {
	long double sum = 0;
	for(int i=1; i<=n; i++) {
		sum += len[i]/k;
		if(sum > r[i]) return false;
		if(sum < l[i]) sum = l[i];
	}
	return true;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	scanf("%d ", &n);
	for(int i=1; i<=n; i++) scanf("%d %d %d ", l+i, r+i, len+i);
	long double lef = 0, rig = 1e9+7, mid, ans = 0;
	while(rig-lef >= 0.00001) {
		mid = (lef + rig) / 2;
		if(check(mid)) ans = mid, rig = mid;
		else lef = mid;
	}
	printf("%.2Lf\n", ans);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

