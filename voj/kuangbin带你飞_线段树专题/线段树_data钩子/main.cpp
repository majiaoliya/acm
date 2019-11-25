#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#define MAXN 100005
#define ll long long int
using namespace std;

int n, m, t;
ll sum[MAXN<<2], lazy[MAXN<<2], len[MAXN<<2], arr[MAXN];

void push_up(int x) { sum[x] = sum[x<<1] + sum[x<<1|1]; }

//void push_down(int x) {
//	if(lazy[x]) {
//		lazy[x<<1] = lazy[x];
//		lazy[x<<1|1] = lazy[x];
//		sum[x<<1] = lazy[x] * len[x<<1];
//		sum[x<<1|1] = lazy[x] * len[x<<1|1];
//		lazy[x] = 0;
//	}
//}

void init(int n) {
	for(int i=1; i<=n; i++)
		arr[i] = 1;
}

void push_down(int node, int len) {
    if(lazy[node]) {
        lazy[node<<1] = lazy[node<<1|1] = lazy[node];
        sum[node<<1] = lazy[node]*(len-(len>>1));
        sum[node<<1|1] = lazy[node]*(len>>1);
        lazy[node] = 0;
    }
}

void build(int x, int lef, int rig) {
	len[x] = rig - lef + 1;
	if(lef == rig) {
		sum[x] = arr[lef];
		return ;
	}
	int mid = (lef+rig) >> 1;
	build(x<<1, lef, mid);
	build(x<<1|1, mid+1, rig);
	push_up(x);
}

void update(int x, int lef, int rig, int L, int R, int val) {
	if(L<=lef && rig<=R) {
		lazy[x] = val;
		sum[x] = val * len[x];
		return ;
	}
	if(lef == rig) return;
	push_down(x, rig-lef+1);
	int mid = (lef+rig) >> 1;
	if(L<=mid) update(x<<1, lef, mid, L, R, val);
	if(R>mid) update(x<<1|1, mid+1, rig, L, R, val);
	push_up(x);
}

ll query(int x, int lef, int rig, int L, int R) {
	if(L<=lef && rig<=R) return sum[x];
	push_down(x, rig-lef+1);
	int mid = (lef+rig) >> 1;
	ll ret = 0;
	if(L<=mid) ret += query(x<<1, lef, mid, L, R);
	if(mid<R) ret += query(x<<1|1, mid+1, rig, L, R);
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	for(int i=1; i<=t; i++) {
		scanf("%d", &n);
		init(n);
		build(1, 1, n);
		scanf("%d", &m);
		int L, R, val;
		for(int k=1; k<=m; k++) {
			scanf("%d %d %d", &L, &R, &val);
			update(1, 1, n, L, R, val);
		}
		printf("Case %d: The total value of the hook is %lld.\n", i, sum[1]);
	}
	return 0;
}
