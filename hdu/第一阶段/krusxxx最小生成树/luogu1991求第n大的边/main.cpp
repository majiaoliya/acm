#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 1005
#include <map>
#include <math.h>
#include <unordered_set>
#define ll long long int

using namespace std;

/**
 * luogu1991无线通信网
 * n个二维坐标系的点构成一张无向完全图, 每两个点(u,v)之间通信要花费w, 
 * 你有(S-1)次机会把两个点(u,v)的通信花费变为0, 
 * 问这张图中任意两个直连点(u,v)的最大通信花费最小是多少?
 * 为啥答案是mst的第n大边?
 * 一个树删掉n跳边一定出现n+1个联通块
 * 每次都删除最长边, 剩下的最长边就是答案
 */

int n, m, S;
pair<int, int> arr[MAXN];

double myabs(double x) { return x > 0.00000001 ? x : -x; }

double getdist(pair<int, int>& a, pair<int, int>& b) {
	double x = myabs(a.first - b.first); double y = myabs(b.second - a.second);
	return sqrt(x*x+y*y);
}

int pre[MAXN];

struct Edge {
	int u, v;
	double dist;
	bool operator < (const Edge& y) const { return this->dist < y.dist; }
} e[MAXN*MAXN];

inline void init() { memset(pre, -1, sizeof(pre)); }

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

double krs() {
	vector<double> vec;
	int k = n-1;
	init();
	for(int i=1; i<=m && k; i++) {
		if(union_xy(e[i].u, e[i].v)) vec.push_back(e[i].dist), k--;
	}
	int pos = vec.size()-1;
//	for( ; --S; ) pos --;
	return vec[pos-(S-1)];
}

int main() {
#ifdef debug
//	freopen("test", "r", stdin);
	freopen("/home/majiao/下载/testdata(5).in", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &S, &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d ", &arr[i].first, &arr[i].second);
		for(int k=1; k<i; k++) {
			++m;
			e[m].u = i, e[m].v = k;
			e[m].dist = getdist(arr[i], arr[k]);
		}
	}
	sort(e+1, e+1+m);
	//for(int i=1; i<=m; i++)
	//	printf("%d %d %lf\n", e[i].u, e[i].v, e[i].dist);
	printf("%.2lf\n", krs());






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

