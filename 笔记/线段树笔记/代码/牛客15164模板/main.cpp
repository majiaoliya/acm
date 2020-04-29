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
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int tree[MAXN<<2], n, m;

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

int op, x, y;
void update(int rt, int lef, int rig) {
	if(lef == rig) {
		tree[rt] += y;
		return ;
	}
	int mid = (lef + rig) >> 1;
	if(x<=mid) update(rt<<1, lef, mid);
	else update(rt<<1|1, mid+1, rig);
	push_up(rt);
}
#define L x
#define R y
int query(int rt, int lef, int rig) {
	if(L<=lef && rig<=R) return tree[rt];
	int mid = (lef + rig) >> 1;
	int sum = 0;
	if(L <= mid) sum += query(rt<<1, lef, mid);
	if(mid < R) sum += query(rt<<1|1, mid+1, rig);
	return sum;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	build(1, 1, n);
	while(m--) {
		scanf("%d %d %d ", &op, &x, &y);
		if(op == 1) update(1, 1, n);
		else 
			printf("%d\n", query(1, 1, n));
	}





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

