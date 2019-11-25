#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 10005
using namespace std;

int n, q, L, R, x, arr[MAXN], tree[MAXN<<2], lazy[MAXN<<2], tags[MAXN<<2];

void push_up(int rt) {
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}

void push_down(int rt) {
	if(tags[rt]) {
		tags[rt<<1] = tags[rt<<1|1] = tags[rt];
		lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
		if(tags[rt] == 2) tree[rt<<1] ^= x, tree[rt<<1|1] ^= x;
		else if(tags[rt] == 3) tree[rt] |= x, tree[rt<<1|1] |= x;
		else if(tags[rt] == 4) tree[rt] &= x, tree[rt<<1|1] &= x;
		lazy[rt] = tags[rt] = false;
	}
}

void build(int rt, int lef, int rig) {
	if(lef == rig) {
		scanf("%d", arr+rt);
		return ;
	}
	int mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}

void update(int rt, int lef, int rig, int tag) {
	if(L<=lef && rig<=R) {
		lazy[rt] = x;
		tags[rt] = tag;
		if(tag == 2) tree[rt] ^= x;
		else if(tag == 3) tree[rt] |= x;
		else if(tag == 4) tree[rt] &= x;
		return ;
	}
	push_down(rt);
	int mid = (lef + rig) >> 1;
	if(L <= mid) update(rt<<1, lef, mid, tag);
	if(mid < R) update(rt<<1|1, mid+1, rig, tag);
	push_up(rt);
}

int query(int rt, int lef, int rig) {
	if(lef == rig) return tree[rt];

}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	build(1, 1, n);
	scanf("%d", &q);
	int cmd;
	while(q--) {
		scanf("%d", &cmd);
		switch(cmd) {
			case 1:
				scanf("%d %d", &L, &R);
				printf("%d\n", query(L, R));
				break;
			case 2:
				scanf("%d %d %d", &L, &R, &x);
				break;
			case 3:
				scanf("%d %d %d", &L, &R, &x);
				break;
			case 4:
				scanf("%d %d %d", &L, &R, &x);
				break;
		}
	}
	return 0;
}
