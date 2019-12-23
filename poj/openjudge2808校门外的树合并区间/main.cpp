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
 * 给一个很长的区间[0,n]初始值都为1
 * 给出m个区间[l,r] 每次把[l,r]填为0 问最后有几个1
 * 数据很小可以暴力 正解是把每个区间合并后统计答案
 * 线段树+离散化是不是也能搞一下 ?
 */

int n, m;
typedef pair<int,int> pii;

pii arr[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int l, r;
		scanf("%d %d ", &l, &r);
		if(l > r) swap(l, r);
		arr[i].first = l, arr[i].second = r;
	}
	sort(arr+1, arr+1+m); //排序后合并线段
	vector<pii> vec; //合并后的线段
	for(int i=1; i<=m; i++) {
		if(vec.empty()) { vec.push_back(arr[i]); continue ; }
		else {
			pii& lst = vec.back();
			if(arr[i].first > lst.second)
				vec.push_back(arr[i]);
			else
				lst.second = max(lst.second, arr[i].second);
		}
	}
	int ans = n+1;
	for(int i=0; i<(int)vec.size(); i++) { //统计答案
		auto x = vec[i];
		ans -= (x.second - x.first + 1);
	}
	printf("%d\n", ans);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


