#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <unordered_set>
#define ll long long int
#define max(x, y) ( x > y ? x : y )
#define min(x, y) ( x < y ? x : y )
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

const int maxn = 3e5+10;

int n, m, tree[maxn<<2];

void push_up(int x) {
	tree[x] = max(tree[x<<1], tree[x<<1|1]);
}

void build(int x, int lef, int rig) {
	if(lef == rig) {
		scanf("%d", tree + x);
		return ;
	}
	int mid = (lef + rig) >> 1;
	build(x<<1, lef, mid);
	build(x<<1|1, mid+1, rig);
	push_up(x);
}

void update(int x, int lef, int rig, int idx, int val) {
	if(lef == rig) {
		tree[x] = val;
		return ;
	}
	int mid = (lef + rig) >> 1;
	if(idx <= mid) update(x<<1, lef, mid, idx, val);
	else update(x<<1|1, mid+1, rig, idx, val);
	push_up(x);
}

int query(int x, int lef, int rig, int L, int R) {
	if(L<=lef && rig<=R) 
		return tree[x];
	int mid = (lef + rig) >> 1;
	int lmax = 0, rmax = 0;
	if(L<=mid) lmax = query(x<<1, lef, mid, L, R);
	if(R>mid) rmax = query(x<<1|1, mid+1, rig, L, R);
	return max(lmax, rmax);
}

int main() {
	freopen("test", "r", stdin);
	
	while(~scanf("%d %d", &n, &m)) {
		build(1, 1, n);
		int a, b;
		char cmd[4];
		while(m--) {
			scanf("%s %d %d", cmd, &a, &b);
			if(cmd[0] == 'Q') printf("%d\n", query(1, 1, n, min(a, b), max(a, b)));
			else update(1, 1, n, a, b);
		}	
	}
	
	return 0;
}



