#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define MAXN 100005
using namespace std;

int n, mm, arr[MAXN], tree[MAXN], lsh[MAXN];
char c;

void push_up(int x) {
	tree[x] = tree[x<<1] + tree[x<<1|1];
}

void update(int x, int lef, int rig, int idx) {
	if(lef == rig) {
		tree[x] ++;
		return ;
	}
	int mid = (lef + rig) >> 1;
	if(idx<=mid) update(x<<1, lef, mid, idx);
	else update(x<<1|1, mid+1, rig, idx);
	push_up(x);
}

int query(int x, int lef, int rig, int k) {
	if(lef == rig) return lef;
	int mid = (lef + rig) >> 1, rsum = tree[x<<1|1];
	if(rsum >= k) return query(x<<1|1, mid+1, rig, k);
	else return query(x<<1, lef, mid, k-rsum);
}

int main(void) {
	freopen("test", "r", stdin);
	c = getchar();
	int x;
	while(true) {
		if(scanf("%d", &x) <= 0) break;
		c = getchar();
		n ++;
		arr[n] = lsh[n] = x;
		if(c == ']') break;
	}
	sort(lsh+1, lsh+n+1);
	mm = std::unique(lsh+1, lsh+1+n) - (lsh+1);
	memset(tree, false, sizeof(tree));
	for(int i=1; i<=n; i++) {
		int idx = std::lower_bound(lsh+1, lsh+1+mm, arr[i]) - lsh;
		update(1, 1, mm, idx);
	}
	printf("%d\n", lsh[query(1, 1, mm, 3)]);
	return 0;
}
