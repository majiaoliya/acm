#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <math.h>
#include <stdlib.h>
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

/**
 * 题意:二维坐标系上有n个点,每个点每秒会向上下左右4个方向扩散,
 * 问所有点联通的最小时间
 * 可以转化为最小生成树求最长边的问题
 * 两点间的距离应该为他们的曼哈顿距离,还要分奇偶讨论
 */

int n, m;
typedef pair<int,int> pii;
pii p[MAXN];

struct Edge {
	int u, v;
	ll w;
	Edge(int _u=0, int _v=0, int _w=0) : u(_u), v(_v), w(_w) { }
	bool operator < (const Edge& y) const { return w < y.w; }
} edge[MAXN];
#define _abs(x) (x>0 ? x : -x)

ll get_dist(pii a, pii b) { //返回两点的曼哈顿距离
	return abs(a.first-b.first) + abs(a.second-b.second);
}

int pre[MAXN];

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

ll krs() {
	ll ret = 0, k = n-1;
	memset(pre, -1, sizeof(pre));
	sort(edge, edge+m);
	for(int i=0; i<m && k; i++) {
		bool ok = union_xy(edge[i].u, edge[i].v);
		if(!ok) continue ;
		k --;
		ret = max(ret, edge[i].w);
	}
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d ", &p[i].first, &p[i].second);
		for(int k=1; k<i; k++) {
			edge[m].u = i, edge[m].v = k;
			auto len = get_dist(p[i], p[k]);
			if(len & 1) //分奇数和偶数
				edge[m].w = (len>>1) + 1;
			else 
				edge[m].w = (len >> 1);
			m ++;
		}
	}
	ll ans = krs(); //ans=15
	//for(int i=0; i<m; i++)
	//	printf("%d %d %lld\n", edge[i].u, edge[i].v, edge[i].w);
	printf("%lld\n", ans>>1);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

