#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 505
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

//krsxxx次小生成树
//题意: 给定一个图(不一定联通) 问是否只有一颗最小生成树
//思路: 先判联通,再求最小生成树,再求次小生成树, 
//      如果次小生成树边权和等于最小生成树边权和 就输出no
int n, m, pre[MAXN], Max[MAXN][MAXN];
vector<int> G[MAXN];

void init() {
	memset(pre, -1, sizeof(pre));
	memset(Max, 0x3f, sizeof(Max));
}

struct Edge {
	int u, v, w, vis;
	bool operator < (const Edge& y) const { return this->w < y.w; }
} edge[MAXN*MAXN];

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

int krs() {
	sort(edge, edge+m);
	init();
	int sum = 0, cnt = n-1;
	for(int i=0; i<m && cnt; i++) {
		auto ok = union_xy(edge[i].u, edge[i].v);
		if(!ok) continue ;
		sum += edge[i].w;
		edge[i].vis = true;
		cnt --;

	}
	return sum;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m)) {
		int u, v, w;
		for(int i=0; i<m; i++) {
			scanf("%d %d %d ", &u, &v, &w);
			edge[i].u = u, edge[i].v = v, edge[i].w = w, edge[i].vis = false;
			G[u].push_back(v), G[v].push_back(u);
		}
		int mst = krs();
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



