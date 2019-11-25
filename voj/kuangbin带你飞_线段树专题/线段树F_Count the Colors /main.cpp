#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#define MAXN 8005
#define MID (int mid = (lef+rig) >> 1; )
using namespace std;

int n, arr[MAXN], tree[MAXN<<2], lazy[MAXN<<2];

void init() {
	for(int i=0; i<=8000; i++)
		lazy[i] = -1, tree[i] = 0, arr[i] = -1;
}

void push_down(int x) {
	if(lazy[x] != -1) {
		lazy[x<<1] = lazy[x<<1|1] = lazy[x];
		lazy[x] = -1;
	}
}

void update(int x, int lef, int rig, int L, int R, int val) {
	if(L<=lef && rig<=R) {
		lazy[x] = val;
		return ;
	}
	push_down(x);
	int mid = (lef+rig) >> 1;
	if(L<=mid) update(x<<1, lef, mid, L, R, val);
	if(mid<R) update(x<<1|1, mid+1, rig, L, R, val);
}

void query(int x, int lef, int rig, int L, int R) {
	if(lef == rig) {
		arr[lef] = lazy[x];
		return ;
	}
	push_down(x);
	int mid = (lef+rig) >> 1;
	if(L<=mid) query(x<<1, lef, mid, L, R);
	if(mid<R) query(x<<1|1, mid+1, rig, L, R);
}

int main(void) {
	freopen("test", "r", stdin);
	while(EOF!=scanf("%d", &n)) {
		init();
		for(int i=1, L, R, col; i<=n; i++) {
			scanf("%d %d %d", &L, &R, &col);
			update(1, 1, 8000, L+1, R, col);
		}
		query(1, 1, 8000, 1, 8000);
		for(int i=1; i<=8000; i++)
			printf("%d  ", arr[i]);
		printf("\n");
	}
	return 0;
}



