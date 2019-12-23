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

/**
 * 约翰和奶牛 写臭了的题目
 */

int n, m, arr[MAXN];

bool check(int mid) {
	int lst = 1, cnt = 1;
	for(int i=2; i<=n; i++) {
		if(arr[i]-arr[lst] >= mid) {
			lst = i;
			cnt ++;
		}
	}
	return cnt >= m;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d ", arr+i);
	sort(arr+1, arr+1+n);
	int lef = 0, rig = 1e9+7, mid, ans;
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


