#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#define MAXN 50005
using namespace std;

int t, n;
int sum[MAXN*4], arr[MAXN];

void push_up(int xnode) {
	sum[xnode] = sum[xnode<<1] + sum[(xnode<<1)+1];
}

void build(int xnode, int lef, int rig) {
	if(lef == rig) {
		sum[xnode] = arr[lef];
		return ;
	}
	int mid = (lef+rig) >> 1;
	build(xnode<<1, lef, mid);
	build((xnode<<1)+1, mid+1, rig);
	push_up(xnode);
}

//void update(int xnode, int lef, int rig, int idx, int val) {
//	if(lef == rig) {
//		sum[xnode] += val;
//		return;
//	}
//	int mid = (lef+rig) >> 1;
//	if(idx<=mid) update(xnode<<1, lef, mid, idx, val);
//	else update((xnode<<1+1), mid+1, rig, idx, val);
//	push_up(xnode);
//}

void update(int xnode, int lef, int rig, int idx, int val) {
	if(lef == rig) {
		sum[xnode] += val;
		return;
	}
	int mid = (lef+rig) >> 1;
	if(idx<=mid) update(xnode<<1, lef, mid, idx, val);
	else update((xnode<<1)+1, mid+1, rig, idx, val);
	push_up(xnode);
}

int query(int xnode, int lef, int rig, int L, int R) {
	if(L<=lef && rig<=R) return sum[xnode];
	else if(R<lef || L>rig) return 0;
	int mid = (lef+rig) >> 1, ret = 0;
	if(L<=mid)
		ret += query(xnode<<1, lef, mid, L, R);
	if(R>mid)
		ret += query((xnode<<1)+1, mid+1, rig, L, R);
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	for(int i=1; i<=t; i++) {
		printf("Case %d:\n", i);
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		char cmd[16];
//		memset(sum, false, sizeof(sum));
		build(1, 1, n);
		while(~scanf("%s", cmd) && cmd[0]!='E') {
			int L, R, idx, value;
			if(cmd[0] == 'Q') { //Query
				scanf("%d %d", &L, &R);
				printf("%d\n", query(1, 1, n, L, R));
			} else if(cmd[0] == 'A') { //Add
				scanf("%d %d", &idx, &value);
				update(1, 1, n, idx, value);
			} else { //Sub
				scanf("%d %d", &idx, &value);
				update(1, 1, n, idx, -value);
			}
		}
	}
	return 0;
}
