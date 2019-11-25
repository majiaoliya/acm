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

ll n, m, sum[MAXN], lazy[MAXN], cmd, L, R, val, len[MAXN];

inline void push_up(ll rt) { sum[rt] = sum[rt<<1] + sum[rt<<1|1]; }

inline void push_down(ll rt) {
	if(lazy[rt]) {
		lazy[rt<<1] += lazy[rt];
		lazy[rt<<1|1] += lazy[rt];
		sum[rt<<1] += lazy[rt]*len[rt<<1];
		sum[rt<<1|1] += lazy[rt]*len[rt<<1|1];
		lazy[rt] = 0;
	}
}

void build(ll rt, ll lef, ll rig) {
	len[rt] = rig - lef + 1;
	if(lef == rig) {
		scanf("%lld ", sum+rt);
		return ;
	}
	ll mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}

void update(ll rt, ll lef, ll rig) {
	if(L<=lef && rig<=R) {
		lazy[rt] += val;
		sum[rt] += val*len[rt];
		return ;
	}
	push_down(rt);
	ll mid = (lef + rig) >> 1;
	if(L <= mid) update(rt<<1, lef, mid);
	if(mid < R) update(rt<<1|1, mid+1, rig);
	push_up(rt);
}

ll query(ll rt, ll lef, ll rig) {
	if(L<=lef && rig<=R) return sum[rt];
	push_down(rt);
	ll mid = (lef + rig) >> 1, ret = 0;
	if(L <= mid) ret += query(rt<<1, lef, mid);
	if(mid < R) ret += query(rt<<1|1, mid+1, rig);
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld %lld ", &n, &m);
	build(1, 1, n);
	while(m--) {
		scanf("%lld %lld %lld ", &cmd, &L, &R);
		if(cmd == 2) {
			printf("%lld\n", query(1, 1, n));
		} else {
			scanf("%lld ", &val);
			update(1, 1, n);
		}
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

