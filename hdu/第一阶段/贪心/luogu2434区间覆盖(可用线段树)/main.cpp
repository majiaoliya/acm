#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)1e6+7)
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

/**
 * 给定一些线段, 线段会重叠, 输出所有不想交的线段
 * 先按左端点排序在按右端点排序, 贪心的求答案
 */

int n;
pair<int, int> arr[MAXN];
vector<pair<int,int> > ans;

bool cmp(pair<int,int>& a, pair<int,int>& b) {
	return a.first==b.first ? a.second<b.second : a.first<b.first;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) scanf("%d %d ", &arr[i].first, &arr[i].second);
	sort(arr+1, arr+1+n, cmp);
	auto now = arr[1];
	arr[n+1] = {1000005, 1000005};
	for(int i=2; i<=n+1; i++) {
		if(arr[i].first <= now.second) {
			now.second = max(now.second, arr[i].second);
		} else {
			ans.push_back(now);
			now = arr[i];
		}
	}
	for(auto x : ans) 
		printf("%d %d\n", x.first, x.second);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

