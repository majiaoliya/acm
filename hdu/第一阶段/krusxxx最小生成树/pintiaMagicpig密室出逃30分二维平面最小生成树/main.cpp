#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 128
#include <map>
#include <math.h>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, m, cnt;
typedef pair<int,int> pii;
typedef long double ld;

/**
 * 看着像欧拉平面最小生成树 ? 好像不太对劲
 * 居然还真的是, 而且不卡krusxxx,
 */

struct Point {
	ld r, c;
} arr[MAXN];

struct Edge {
	int u, v;
	ld d;
	Edge(int _u=0, int _v=0, ld _d=0) : u(_u), v(_v), d(_d) { }
	bool operator < (const Edge& y) const { return d < y.d; }
} edge[MAXN*MAXN];

ld get_dist(Point& a, Point& b) { //二维平面两点距离公式
	ld xx = (a.r-b.r), yy = (a.c-b.c);
	xx *= xx;
	yy *= yy;
	return sqrt(xx + yy); 
}

int pre[MAXN];

inline void init() {
	memset(pre, -1, sizeof(pre));
}

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

ld krs() {
	init();
	sort(edge, edge+cnt);
	ld sum = 0;
	int k = n - 1;
	for(int i=0; i<cnt && k; i++) {
		bool ok = union_xy(edge[i].u, edge[i].v);
		if(!ok) continue ;
		k--;
		sum += edge[i].d;
	}
	return sum;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d ", &n) && n) {
		scanf("%d ", &m);
		cnt = 0;
		ld len = m;
		for(int i=1; i<=n; i++) {
//			scanf("%d %d ", &arr[i].r, &arr[i].c);
			cin >> arr[i].r >> arr[i].c;
			if(i == 1) continue ;
			for(int k=1; k<i; k++) {
				Edge& ed = edge[cnt];
				ed.u = i, ed.v = k, ed.d = 0x3f3f3f3f;
			   	auto td = get_dist(arr[i], arr[k]); 
				if(ed.d >= td) ed.d = td;
				cnt ++;
			}
		}
		ld sum = krs();
		if(len >= sum) printf("Success!\n");
		else printf("Poor magicpig!\n");
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

