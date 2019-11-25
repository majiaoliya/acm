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

int n, m, arr[MAXN];

int check(int mid) {
	int sum = 0, cnt = 0;
	for(int i=1; i<=n; i++) {
		if(sum+arr[i] <= mid) sum += arr[i];
		else cnt ++, sum = arr[i];
	}
	return cnt >= m;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	int lef = 1e9+7, rig = 0, mid, ans = -1;
	for(int i=1; i<=n; i++) scanf("%d ", arr+i), lef=min(lef, arr[i]), rig+=arr[i];
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(check(mid)) ans = mid, lef = mid + 1;
		else rig = mid - 1;
	}
	printf("%d\n", lef);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

