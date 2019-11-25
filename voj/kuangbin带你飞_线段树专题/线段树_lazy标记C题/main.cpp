#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#define MAXN 100005
#define ll long long int
using namespace std;

int n, m;
ll sum[MAXN<<2], lazy[MAXN<<2], len[MAXN<<2];

void push_up(int x) { sum[x] = sum[x<<1] + sum[x<<1|1]; }
void push_down(int x) {
	if(lazy[x]) {
		lazy[x<<1] += lazy[x];
		lazy[x<<1|1] += lazy[x];
		sum[x<<1] += lazy[x] * len[x<<1];
		sum[x<<1|1] += lazy[x] * len[x<<1|1];
		lazy[x] = 0;
	}
}

void build(int x, int lef, int rig) {
	len[x] = rig-lef+1;
	if(lef == rig) {
		scanf("%lld", sum+x);
		return ;
	}
	int mid = (lef+rig) >> 1;
	build(x<<1, lef, mid);
	build(x<<1|1, mid+1, rig);
	push_up(x);
}

ll query(int x, int lef, int rig, int L, int R) {
	if(L<=lef && rig<=R) return sum[x];
	push_down(x); //查询之前向下推送
	int mid = (lef+rig) >> 1;
	ll ret = 0;
	if(L<=mid) ret += query(x<<1, lef, mid, L, R);
	if(mid<R) ret += query(x<<1|1, mid+1, rig, L, R);
	return ret;
}

void update(int x, int lef, int rig, int L, int R, ll val) {
	if(L<=lef && rig<=R) {
		lazy[x] += val;
		sum[x] += len[x] * val;
		return ;
	}
	push_down(x); //更新之前向下推
	int mid = (lef+rig) >> 1;
	if(L<=mid)	update(x<<1, lef, mid, L, R, val);
	if(mid<R) update(x<<1|1, mid+1, rig, L, R, val);
	push_up(x);
}
int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		build(1, 1, n);
		char cmd[4];
		while(m--) {
			scanf("%s", cmd);
			if(cmd[0] == 'Q') {
				int lef, rig;
				scanf("%d %d", &lef, &rig);
				printf("%lld\n", query(1, 1, n, lef, rig));
			} else {
				int L, R;
				ll val;
				scanf("%d %d %lld", &L, &R, &val);
				update(1, 1, n, L, R, val);
			}
		}
	}
	return 0;
}
