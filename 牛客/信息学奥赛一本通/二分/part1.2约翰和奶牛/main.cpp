#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)1e5+7)
#include <map>
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 约翰和奶牛,n个牛棚,放m头牛(一个坑最多一头牛),使得每头牛距离最远
 * 直接二分答案O(n)check
 */
int n, m, arr[MAXN];

bool check(int mid) {
	int sum = arr[1], cnt = 1;
	for(int i=2; i<=n; i++) {
		if(arr[i]-sum >= mid) {
			sum = arr[i];
			cnt ++;
			continue ;
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
	int lef = 0, rig = 1e9+7, mid, ans = 0;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		bool ok = check(mid);
		if(ok) {
			ans = mid;
			lef = mid + 1;
		} else 
			rig = mid - 1;
	}
	printf("%d\n", ans);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

