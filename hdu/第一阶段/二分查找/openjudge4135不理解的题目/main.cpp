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
 * poj4135月度开销
 * 把一个数组切成m段,最小化每段最大和
 * 这题要确定左边界
 */
int n, m, arr[MAXN];

bool check(int mid) {
	int sum = 0, cnt = 1;
	for(int i=1; i<=n; i++) {
		if(sum+arr[i] <= mid) sum += arr[i];
		else {
			cnt ++;
			sum = arr[i];
		}
	}
	return cnt <= m;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	int sums = 0, lmax = -1;
	for(int i=1; i<=n; i++) 
		scanf("%d ", arr+i), sums += arr[i], lmax=max(lmax, arr[i]);
	int lef = lmax, rig = sums, mid, ans = 0;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(check(mid)) ans = mid, rig = mid - 1;
		else lef = mid + 1;
	}
	printf("%d\n", ans);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


