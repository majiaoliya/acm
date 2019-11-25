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
#include <unordered_set>
#define ll long long int

using namespace std;

int n, m, tree[MAXN<<2], L, R;
void push_up(int rt) { tree[rt] = __gcd(tree[rt<<1], tree[rt<<1|1]); }

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

int query(int rt, int lef, int rig) {
	if(L<=lef && rig<=R) return tree[rt];
	int mid = (lef + rig) >> 1, ret = 0;
	if(L <= mid) ret = query(rt<<1, lef, mid);
	if(mid < R) ret = __gcd(ret, query(rt<<1|1, mid+1, rig));
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	build(1, 1, n);
	while(m--) {
		scanf("%d %d ", &L, &R);
		printf("%d\n", query(1, 1, n));
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

