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
struct Edge {
	int from, to;
	bool operator < (Edge& x) const {
		if(from == x.from) return to < x.to;
		return from < x.from;
	}
} edge[MAXN];

int pre[MAXN], vis[MAXN];

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1) ret = pre[ret];
	if(x != ret) pre[x] = ret;
	return ret;
}

bool union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry) {
		pre[ry] = rx;
		return true;
	}
	return false;
}

bool krs() {
	memset(pre, -1, sizeof(pre));
	int cnt = 0;
	for(int i=1; i<=m; i++) {
		if(vis[i]) continue ;
		if(union_xy(edge[i].from, edge[i].to)) cnt ++;
		if(cnt == n-1) break;
	}
	return cnt == n-1;
}

//给定一个图, 求出所有割边.
//枚举删除每条边的情况, 看看删边后能否构成生成树
int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
	   	scanf("%d %d ", &edge[i].from, &edge[i].to);
		if(edge[i].from > edge[i].to) swap(edge[i].from, edge[i].to);
	}
	sort(edge+1, edge+1+m);
	
	vector<Edge> ans;
	for(int i=1; i<=m; i++) {
		vis[i] = true;
		if(!krs()) ans.push_back(edge[i]);
		vis[i] = false;
	}
	for(int i=0; i<(int)ans.size(); i++)
		printf("%d %d\n", ans[i].from, ans[i].to);

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

