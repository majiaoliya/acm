#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)5e5+7)
#include <map>
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 *
 * 给定一个无向带权连通图，每条边是黑色或白色
 * 要求一棵最小权的恰好有k条白色边的生成树。题目保证有解。
 * 太难了....
 * 做法:给每条白边加上一个值x,然后求最小生成树,如果白边数量少了说明加的值大了,
 * 反之,白边数量多了说明加的值小了,x可以二分出来...
 * 注意: 有可能存在白边加值后等于某条黑边的情况,这时候要把白边放前面才能ac
 */
int n, m, K, x; //n个点,m条边,恰好要K条白边,白边要加的值

struct Edge {
	int u, v, w, color, cmp;
	bool operator< (const Edge& y) const { 
		if(cmp == y.cmp) //白边加值后和某条黑边相等时要把白边提前才能ac
			return color < y.color;
		return cmp < y.cmp; 
	}
} e[MAXN*10];

int pre[MAXN], sum;

void init() {
	memset(pre, -1, sizeof(pre));
	sum = 0;
	for(int i=1; i<=m; i++) //每条白边加上一个值x
		e[i].cmp = e[i].w + (e[i].color==0 ? x : 0);
	sort(e+1, e+1+m);
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

int krs() {
	init();
	int ret = 0; //返回这颗生成树有几条白边
	int k = n-1;
	for(int i=1; i<=m && k; i++) {
		bool ok = union_xy(e[i].u, e[i].v);
		if(!ok) continue ;
		k --;
		sum += e[i].cmp;
		ret += (e[i].color==0);
//		printf("union_xy(%d,%d)\n", e[i].u, e[i].v);
	}
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);

	clock_t stime = clock();
#endif
	scanf("%d %d %d ", &n, &m, &K);
	for(int i=1; i<=m; i++)
		scanf("%d %d %d %d ", &e[i].u, &e[i].v, &e[i].w, &e[i].color);
	
	//通过给白边加值控制白边排序后的位置
	int lef = -120, rig = 120, mid, ans_mid;
	while(lef <= rig) { //二分这个加上白边的值
		mid = (lef + rig) / 2;
		x = mid;
		int cnt = krs();
		if(cnt >= K) { 
			ans_mid = mid;
			lef = mid + 1;
	   	} else if(cnt < K) rig = mid - 1;
	}
	x = ans_mid;
	krs();
	printf("%d\n", sum-K*x);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

