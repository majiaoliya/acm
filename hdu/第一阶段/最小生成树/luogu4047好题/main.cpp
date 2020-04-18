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
#include <set>
#include <stack>
#include <math.h>
#include <queue>
#define MAXN ((int)5e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, pre[MAXN], cnt, K;
double sum;
struct Edge {
	int u, v;
	double w;
	bool operator < (const Edge& y) const {
		return w < y.w;
	}
} e[MAXN];

int fa(int x) {
	int ret = x;
	while(~pre[ret]) ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

void krsxxx() {
	sort(e+1, e+1+m);
	memset(pre, -1, sizeof(pre));
	for(int i=1; i<=m && n; i++) {
		int rx = fa(e[i].u), ry = fa(e[i].v);
		if(rx == ry) continue ;
		pre[ry] = rx;
		n --;
		if(n == K-1) {
			sum = e[i].w;
			break;
		}
	}
}

pair<int,int> vs[MAXN];

double dist(int x1, int x2, int y1, int y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &K);
	for(int i=0; i<n; i++) {
		scanf("%d %d ", &vs[i].first, &vs[i].second);
		for(int k=0; k<i; k++) {
			e[++m].u = i, e[m].v = k;
//			e[m] = sqrt((x-x1)^2+(y-y1)^2)
			e[m].w = dist(vs[i].first, vs[k].first,
				   	vs[i].second, vs[k].second);
		}
	}
	krsxxx();
	printf("%.2lf\n", sum);


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


