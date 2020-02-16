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

//区间修改,区间查询

int n, m, sum[MAXN<<2], lazy[MAXN<<2], len[MAXN<<2];

void build(int rt, int lef, int rig) {
	len[rt] = rig - lef + 1;
	if(lef == rig) return ;
	int mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
}

void push_down(int rt) {
	if(lazy[rt]) {
		sum[rt] = len[rt];
		lazy[rt<<1] = lazy[rt<<1|1] = true;
		sum[rt<<1] = len[rt<<1];
		sum[rt<<1|1] = len[rt<<1|1];
//		sum[rt<<1] = sum[rt<<1|1] = l; 
		lazy[rt] = false;
	}
}

void push_up(int rt) { sum[rt] = sum[rt<<1] + sum[rt<<1|1]; }

void update(int rt, int lef, int rig, int L, int R) {
	if(L<=lef && rig<=R) {
		lazy[rt] = true;
		sum[rt] = len[rt];
//		printf("%d %d : %d\n", lef, rig, sum[rt]);
		return ;
	}
	push_down(rt);
	int mid = (lef + rig) >> 1;
	if(L <= mid) update(rt<<1, lef, mid, L, R);
	if(mid < R) update(rt<<1|1, mid+1, rig, L, R);
	push_up(rt);
}

int query(int rt, int lef, int rig, int L, int R) {
	if(L<=lef && rig<=R) return sum[rt];
	int mid = (lef + rig) >> 1, ret = 0;
	push_down(rt);
	if(L<=mid) ret = query(rt<<1, lef, mid, L, R);
	if(mid<R) ret += query(rt<<1|1, mid+1, rig, L, R);
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	n ++; //+1  因为题目下标从0开始到n, 
	build(1, 1, n);
	while(m--) {
		int L, R;
		scanf("%d %d ", &L, &R);
		L ++, R ++;
		update(1, 1, n, L, R);
	}
	printf("%d\n", n-query(1, 1, n, 1, n));


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



