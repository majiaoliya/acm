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

int n, m;
typedef pair<int,int> pii;
pii arr[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif 
	//按终点排序后扫描每个线段,当前线段开始时间大于等于前一个的结束时间
	//ans ++
	while(~scanf("%d ", &n) && n) {
		for(int i=1; i<=n; i++)
			scanf("%d %d ", &arr[i].first, &arr[i].second);
		sort(arr+1, arr+1+n, [&](pii& a, pii& b) { return a.second < b.second;});
		int ans = 1, id = 1;
		for(int i=2; i<=n; i++) {
			if(arr[i].first >= arr[id].second) ans ++, id = i;
		}
		printf("%d\n", ans);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


