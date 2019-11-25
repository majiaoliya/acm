#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAXN 200005
#define ll long long 
using namespace std;

int n, mm, q, lsh[MAXN], arr[MAXN], arr2[MAXN], tree[MAXN<<2];

void update(int x, int lef, int rig, int val) {
	if(lef == rig) {
		tree[x] ++;
		return;
	}
	int mid = (lef + rig) >> 1;
	if(val <= mid) update(x<<1, lef, mid, val);
	else update(x<<1|1, mid+1, rig, val);
	tree[x] = tree[x<<1] + tree[x<<1|1];
}

struct Node {
	int lev, idx, lef, rig;
};
#include <queue>
#define lson (x.idx<<1)
#define rsun (x.idx<<1|1)
void level_order() {
	queue<Node> q;
	Node x, nx;
	int lcnt = 1;
	x.lev = 1, x.idx = 1, x.lef = 1, x.rig = mm;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
		q.pop();
		if(lcnt != x.lev) {
			lcnt = x.lev;
			printf("\n");
		}
		printf("[lef:%d rig:%d sum:%d]", x.lef, x.rig, tree[x.idx]);
		int mid = (x.lef + x.rig) >> 1;
		nx.lef = x.lef, nx.rig = mid;
		nx.lev = x.lev + 1;
		nx.idx = x.idx<<1;
		if(nx.idx <= (mm<<2)) q.push(nx);
		nx.lef = mid + 1, nx.rig = x.rig;
		nx.idx = x.idx<<1|1;
		if(nx.idx <= (mm<<2)) q.push(nx);
	}
}

int query(int x, int lef, int rig, int k) {
	if(lef == rig) 
		return lef;
	int mid = (lef + rig) >> 1;
	int rsum = tree[x<<1|1];
	if(k<=rsum) return query(x<<1|1, mid+1, rig, k);
	else return query(x<<1, lef, mid, k-rsum);
}

void dsp(int x, int lef, int rig) {
	printf("(L:%d R:%d val:%d)\n", lef, rig, tree[x]);
	if(lef == rig) return ;
	int mid = (lef + rig) >> 1;
	dsp(x<<1, lef, mid);
	dsp(x<<1|1, mid+1, rig);
}

int main(void) {
	freopen("test", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &q);
		memset(tree, false, sizeof(tree));
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			arr2[i] = lsh[i] = arr[i];
		}
		sort(lsh+1, lsh+1+n);
#ifdef dbg
		for(int i=n, j=1; i>=1; i--, j++) {
			printf("[%d,%d] ", j, lsh[i]);
		}
		printf("\n离散化:\n");
#endif
		mm = unique(lsh+1, lsh+1+n) - (lsh+1);
#ifdef dbg
		for(int i=1; i<=mm; i++) {
			printf("%d ", lsh[i]);
		}
#endif
		//sort(arr2+1, arr2+1+n);
		for(int i=1; i<=n; i++) {
			int idx = std::lower_bound(lsh+1, lsh+1+mm, arr2[i])-(lsh);
#ifdef dbg
			printf("try update %d idx:%d\n", arr2[i], idx);
#endif
			update(1, 1, mm, idx);
		}
		printf("\n");
//		dsp(1, 1, mm);
#ifdef dbg
		level_order();
#endif
		while(q--) {
			int L, R, k;
			scanf("%d %d %d", &L, &R, &k);
			printf("第%d大 = %d\n", k, lsh[query(1, 1, mm, k)]);
		}
	}
	return 0;
}





