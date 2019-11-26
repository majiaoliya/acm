#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, arr[MAXN], tree[MAXN<<2];

inline void push_up(int rt) { tree[rt] = min(tree[rt<<1], tree[rt<<1|1]); }

void build(int rt, int lef, int rig) {
	if(lef == rig) {
		scanf("%d ", arr+lef);
		tree[rt] = arr[lef];
		return ;
	}
	int mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}
int idx, key;
int query(int rt, int lef, int rig) {
	if(lef == rig) {
		idx = lef;
		return lef;
	}
	int mid = (lef + rig) >> 1;
	if(tree[rt<<1|1] < key) {
		return query(rt<<1|1, mid+1, rig);
	}
	else {
		return query(rt<<1, lef, mid);
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	build(1, 1, n);
	for(int i=1; i<=n; i++) {
		key = arr[i];
		int id = query(1, 1, n);
		if(id < i) printf("-1 ");
		else printf("%d ", id-i-1);
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

