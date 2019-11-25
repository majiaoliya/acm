#include <iostream>
#include <string.h>
#define MAXN 100010
#define ll long long int
using namespace std;

ll n;
ll arr[MAXN], sum[MAXN<<2], lazy[MAXN<<2];

void push_up(ll node) {
	sum[node] = sum[node<<1] + sum[node<<1|1];
}

void push_down(ll node, ll len) {
	if(lazy[node]) {
		lazy[node<<1] = lazy[node<<1|1] = lazy[node];
		sum[node<<1] = lazy[node]*(len-(len>>1));
		sum[node<<1|1] = lazy[node]*(len>>1);
		lazy[node] = 0;
	}
}

void build(ll node, ll start, ll end) {
	if(start == end) {
		sum[node] = arr[start];
		return ;
	}
	ll mid = (start+end)>>1, lef = node<<1, rig = node<<1|1;
	build(lef, start, mid);
	build(rig, mid+1, end);
	push_up(node);
}

void update(ll node, ll start, ll end, ll l, ll r) {
	if(start>=l && end<=r) {
		if(start == end) { arr[start] += lazy[node]; }
		lazy[node] += 1;
		sum[node] += lazy[node]*(end-start+1);
		return ;
	}
	push_down(node, end-start+1);
	ll mid = (start+end)>>1, lef = node<<1, rig = node<<1|1;
	if(l<=mid)
		update(lef, start, mid, l, r);
	if(r>mid)
		update(rig, mid+1, end, l, r);
	push_up(node);
}

ll query(ll node, ll start, ll end, ll l, ll r) {
	if(start>=l && end<=r) {
		return sum[node];
	}
	push_down(node, end-start+1);
	ll rs = 0, mid = (start+end)>>1;
	if(l<=mid)
		rs += query(node<<1, start, mid, l, r);
	if(r>mid)
		rs += query(node<<1|1, mid+1, end, l, r);
	return rs;
}

int main(void) {
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%lld", &n), n; ) {
		memset(arr, false, n+5);
		for(int i=1; i<=n; i++) {
			ll l, r;
			scanf("%lld %lld", &l, &r);
			update(1, 1, n, l, r);
		}
		for(ll i=1, c=0; i<=n; i++) {
			if(c++) printf(" ");		
			printf("%lld", query(1, 1, n, i, i));
		}
		printf("\n");
	}
	
	return 0;
}








