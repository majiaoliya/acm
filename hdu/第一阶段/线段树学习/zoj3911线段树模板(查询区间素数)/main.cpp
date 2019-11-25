/**
#include <iostream>
#include <string.h>
#define ll long long 
using namespace std;
#define MAXN (110000)
#define MAXNN (11000000)
#define is_prime(i) (!vis[i])

int pn, prime[MAXNN], t, n, q, a, L, R, idx, val;
bool vis[MAXNN];
int arr[MAXN];

void getprime() {
	vis[0] = vis[1] = true;
	for(int i=2; i<MAXNN; i++) {
		if(vis[i] == false) prime[pn++] = i;
		for(int k=0; k<pn && i*prime[k]<MAXNN; k++) {
			vis[i*prime[k]] = true;
			if(i % prime[k] == 0) break;
		}
	}
}

struct Node {
	int sum, lazy, val, len;
} tree[MAXN<<2];

inline void push_up(int rt) { tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum; }
inline void push_down(int rt) {
	if(tree[rt].lazy) {
		tree[rt<<1].lazy = tree[rt<<1|1].lazy = tree[rt].lazy;
		tree[rt].val = tree[rt].lazy;
		int tv = tree[rt].val;
		tree[rt].sum = is_prime(tv) ? (tree[rt].len) : 0;
		tree[rt].lazy = false;
	}
}

void build(int rt, int lef, int rig) {
	tree[rt].len = (rig - lef) + 1; //区间长度
	if(lef == rig) {
		scanf("%d ", &val);
		tree[rt].val = val;
		tree[rt].lazy = false;
		tree[rt].sum = is_prime(val);
		return;
	}
	int mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}

void update_lr(int rt, int lef, int rig) {
	if(L<=lef && rig<=R) {
		if(lef == rig) tree[rt].sum = is_prime(val);
		tree[rt].val = tree[rt].lazy = val;
		return ;
	}
	push_down(rt);
	int mid = (lef + rig) >> 1;
	if(L <= mid) update_lr(rt<<1, lef, mid);
	if(mid < R) update_lr(rt<<1|1, mid+1, rig);
	push_up(rt);
}

void update_p(int rt, int lef, int rig) {
	if(lef == rig) {
		tree[rt].val += val;
		tree[rt].sum = is_prime(tree[rt].val);
		return ;
	}
	int mid = (lef + rig) >> 1;
	if(L <= mid) update_p(rt<<1, lef, mid);
	else update_p(rt<<1|1, mid+1, rig);
	push_up(rt);
}

int query(int rt, int lef, int rig) {
	if(L<=lef && rig<=R) return tree[rt].sum;
	int ret = 0, mid = (lef + rig) >> 1;
	push_down(rt);
	if(L <= mid) ret += query(rt<<1, lef, mid);
	if(mid < R) ret += query(rt<<1|1, mid+1, rig);
	return ret;
}

void dsp() {
	for(int i=1; i<=n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	getprime();
	char cmd[4];
	while(t--) {
		scanf("%d %d", &n, &q);
		build(1, 1, n);
		while(q--) {
			scanf("%s\n", cmd);
			if(cmd[0] == 'A') { //单点更新
				scanf("%d %d\n", &val, &L);
				R = L;
				update_p(1, 1, n);
			} else if(cmd[0] == 'R') { //区间更新
				scanf("%d %d %d\n", &val, &L, &R);
				update_lr(1, 1, n);
			} else {
				scanf("%d %d\n", &L, &R);
//				printf("try query %d %d\n", L, R);
				printf("%d\n", query(1, 1, n));
			}
		}
	}
	return 0;
}
*/





#include <iostream>
#include <string.h>
#define ll long long 
using namespace std;
#define MAXN (110000)
#define MAXNN (11000000)
#define is_prime(i) (!vis[i])

int pn, prime[MAXNN], t, n, q, L, R, idx, val;
bool vis[MAXNN];
int arr[MAXN];

void getprime() {
	vis[0] = vis[1] = true;
	for(int i=2; i<MAXNN; i++) {
		if(vis[i] == false) prime[pn++] = i;
		for(int k=0; k<pn && i*prime[k]<MAXNN; k++) {
			vis[i*prime[k]] = true;
			if(i % prime[k] == 0) break;
		}
	}
}

struct Node {
	int sum, val, lazy, len;
} tree[MAXN<<2];

void push_up(int rt) { tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum; }
void push_down(int rt) {
	if(tree[rt].lazy) {
		tree[rt<<1].lazy = tree[rt<<1|1].lazy = tree[rt].lazy;
		tree[rt<<1|1].val = tree[rt<<1|1].val = tree[rt].val;
		tree[rt<<1].sum = tree[rt<<1].len * is_prime(tree[rt].lazy);
		tree[rt<<1|1].sum = tree[rt<<1|1].len * is_prime(tree[rt].lazy);
		tree[rt].lazy = 0;
	}
}

void build(int rt, int lef, int rig) {
	tree[rt].len = rig - lef + 1;
	tree[rt].lazy = tree[rt].val = 0;
	tree[rt].sum = 0;
	if(lef == rig) {
		scanf("%d ", &val);
		tree[rt].val = val;
		tree[rt].sum = is_prime(val);
		return ;
	}
	int mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}

void update_p(int rt, int lef, int rig) {
	if(lef == rig) {
		tree[rt].val += val;
		tree[rt].sum = is_prime(tree[rt].val);
		return ;
	}
	push_down(rt);
	int mid = (lef + rig) >> 1;
	if(idx <= mid) update_p(rt<<1, lef, mid);
	else update_p(rt<<1|1, mid+1, rig);
	push_up(rt);
}

void update_lr(int rt, int lef, int rig) {
	if(L<=lef && rig<=R) {
		tree[rt].sum = tree[rt].len * is_prime(val);
		tree[rt].val = tree[rt].lazy = val;
		return ;
	}
	push_down(rt);
	int mid = (lef + rig) >> 1;
	if(L <= mid) update_lr(rt<<1, lef, mid);
	if(mid < R) update_lr(rt<<1|1, mid+1, rig);
	push_up(rt);
}

int query(int rt, int lef, int rig) {
	if(L<=lef && rig<=R) return tree[rt].sum;
	push_down(rt);
	int mid = (lef + rig) >> 1, ret = 0;
	if(L <= mid) ret += query(rt<<1, lef, mid);
	if(mid < R) ret += query(rt<<1|1, mid+1, rig);
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	getprime();
	char cmd[4];
	while(t--) {
		scanf("%d %d\n", &n, &q);
		build(1, 1, n);
		while(q--) {
			scanf("%s ", cmd);
			if(cmd[0] == 'A') { // update_p
				scanf("%d %d\n", &val, &idx);
				update_p(1, 1, n);
			} else if(cmd[0] == 'Q') { // query
				scanf("%d %d\n", &L, &R);
				printf("%d\n", query(1, 1, n));
			} else { //update_lr
				scanf("%d %d %d\n", &val, &L, &R);
				update_lr(1, 1, n);
			}
		}
	} 
	return 0;
}

