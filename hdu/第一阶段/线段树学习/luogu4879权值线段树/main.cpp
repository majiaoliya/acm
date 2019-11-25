#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)5e5+7)
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

ll n, m, L, R, idx;
ll sum[MAXN<<2], cnt[MAXN<<2], arr[MAXN];
char cmd;

void push_up(ll rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
	cnt[rt] = cnt[rt<<1] + cnt[rt<<1|1];
}

void build(ll rt, ll lef, ll rig) {
	if(lef == rig) {
		sum[rt] = arr[lef];
		if(arr[lef]) cnt[rt] = 1;
		return ;
	}
	ll mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}

void change(ll rt, ll lef, ll rig, ll x, ll val) {
	if(lef == rig) {
		sum[rt] -= val;
		return ;
	}
	ll mid = (lef + rig) >> 1;
	if(x <= mid) change(rt<<1, lef, mid, x, val);
	else change(rt<<1|1, mid+1, rig, x, val);
	push_up(rt);
}

void insert(ll rt, ll lef, ll rig, ll x, ll val) {
	if(lef == rig) {
		sum[rt] = val;
		cnt[rt] = 1;
		return ;
	}
	ll mid = (lef + rig) >> 1;
	if(x <= mid) insert(rt<<1, lef, mid, x, val);
	else insert(rt<<1|1, mid+1, rig, x, val);
	push_up(rt);
}

void del(ll rt, ll lef, ll rig, ll k) {
	if(lef == rig) {
		sum[rt] = cnt[rt] = 0;
		return ;
	}
	ll mid = (lef + rig) >> 1;
	if(k <= cnt[rt<<1]) del(rt<<1, lef, mid, k);
	else del(rt<<1|1, mid+1, rig, k-cnt[rt<<1]);
	push_up(rt);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	scanf("%lld %lld ", &n, &m);
	for(int i=1; i<=n; i++) scanf("%lld ", arr+i);
	L = 1, R = MAXN - 3;
	build(1, L, R);
	while(m--) {
		scanf("%c ", &cmd);
//		forarr(arr, 1, 16, "arr");
		if(cmd == 'Q') printf("%lld\n", sum[1]);
		ll idx, val;
		if(cmd == 'C') {
			scanf("%lld %lld ", &idx, &val);
			change(1, L, R, idx, val);
		} else if(cmd == 'I') {
			scanf("%lld %lld ", &idx, &val);
			insert(1, L, R, idx, val);
		} else if(cmd == 'D') {
			scanf("%lld ", &idx);
			del(1, L, R, idx);
		}
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

