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
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, m, tree[MAXN<<2], tmp;

void push_up(int rt) { tree[rt] = tree[rt<<1] + tree[rt<<1|1]; }

void build(int rt, int lef, int rig) {
	if(lef == rig) {
		scanf("%d ", tree+rt);
		return ;
	}
	int mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}

void update(int rt, int lef, int rig, int idx, int val) {
	if(lef == rig) {
		tmp = tree[rt];
		tree[rt] = val;
		return ;
	}
	int mid = (lef + rig) >> 1;
	if(idx <= mid) update(rt<<1, lef, mid, idx, val);
	else update(rt<<1|1, mid+1, rig, idx, val);
	push_up(rt);
}

int query(int rt, int lef, int rig, int L, int R) {
	if(L<=lef && rig<=R) return tree[rt];
	int mid = (lef + rig) >> 1, ret = 0;
	if(L <= mid) ret += query(rt<<1, lef, mid, L, R);
	if(mid <= R) ret += query(rt<<1|1, mid+1, rig, L, R);
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d\n", &n);
	build(1, 1, n);
	int q;
	scanf("%d ", &q);
	while(q--) {
		int x, y;
		scanf("%d %d ", &x, &y);
		update(1, 1, n, x, y);
		printf("%d\n", query(1, 1, n, 1, n));
		update(1, 1, n, x, tmp);
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

