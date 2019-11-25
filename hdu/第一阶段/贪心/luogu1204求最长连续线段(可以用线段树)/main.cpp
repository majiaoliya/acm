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
typedef pair<int,int> pii;
pii arr[MAXN];

bool cmp(pii& x, pii& y) {
	return x.second < y.second;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) 
		scanf("%d %d ", &arr[i].first, &arr[i].second);
	sort(arr+1, arr+1+n);
	int ans1 = 0, ans2 = 0;
	pii lst = arr[1];
	for(int i=2; i<=n; i++) {
		if(arr[i].first <= lst.second) { //第i条可以和上一条合并
			lst.second = max(lst.second, arr[i].second);
		} else { //无法和上一条合并
			ans1 = max(ans1, lst.second-lst.first);
			ans2 = max(ans2, arr[i].first-lst.second);
			lst = arr[i];
		}
	}
	ans1 = max(ans1, lst.second-lst.first);
	printf("%d %d\n", ans1, ans2);



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

