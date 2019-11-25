//#include <iostream>
//#include <string.h>
//#define MAXN 100010
//#define ll long long 
//using namespace std;

////ll n, m;
////ll arr[MAXN], sum[MAXN<<2], lazy[MAXN<<2];

////void push_up(ll node) {
////	sum[node] = sum[node<<1] + sum[node<<1|1];
////}

////void push_down(ll node, ll len) {
////	if(lazy[node]) {
////		ll lef = node<<1, rig = node<<1|1;
////		lazy[lef] += lazy[node];
////		lazy[rig] += lazy[node];
////		sum[lef] += lazy[node]*(len-(len>>1));
////		sum[rig] += lazy[node]*(len>>1);
////		lazy[node] = 0;
////	}
////}

////void build(ll node, ll start, ll end) {
////	lazy[node] = 0;
////	if(start == end) {
////		sum[node] = arr[start];
////		return ;
////	}
////	ll mid = (start+end)>>1;
////	build(node<<1, start, mid);
////	build(node<<1|1, mid+1, end);
////	push_up(node);
////}

////void update(ll node, ll start, ll end, ll l, ll r, ll val) {
////	if(start>=l && end<=r) {
////		lazy[node] = val;
////		sum[node] += val*(end-start+1);
////		return ;
////	}
////	push_down(node, end-start+1);
////	ll mid = (start+end)>>1;
////	if(l<=mid)
////		update(node<<1, start, mid, l, r, val);
////	if(r>mid)
////		update(node<<1|1, mid+1, end, l, r, val);
////	push_up(node);
////}

////ll query(ll node, ll start, ll end, ll l, ll r) {
////	if(start>=l && end<=r) {
////		return sum[node];
////	}
////	push_down(node, end-start+1);
////	ll mid = (start+end)>>1, rs = 0;
////	if(l<=mid)
////		rs += query(node<<1, start, mid, l, r);
////	if(r>mid)
////		rs += query(node<<1|1, mid+1, end, l, r);
////	return rs;
////}

//ll n, m;
//ll arr[MAXN], sum[MAXN<<2], lazy[MAXN];

//void push_up(ll node) {
//	sum[node] = sum[node<<1] | sum[node<<1|1];
//}

//void push_down(ll node, ll len) {
//	if(lazy[node]) {
//		lazy[node<<1] += lazy[node];
//		lazy[node<<1|1] += lazy[node];
//		sum[node<<1] = lazy[node]*(len-(len>>1));
//		sum[node<<1|1] = lazy[node]*(len>>1);
//		lazy[node] = 0;
//	}
//}

//void build(ll node, ll start, ll end) {
//	lazy[node] = 0;
//	if(start == end) {
//		sum[node] = arr[start];
//		return ;
//	}
//	ll mid = (start+end)>>1;
//	build(node<<1, start, mid);
//	build(node<<1|1, mid+1, end);
//	push_up(node);
//}

//void update(ll node, ll start, ll end, ll l, ll r, ll val) {
//	if(start>=l && end<=r) {
//		lazy[node] += val;
//		sum[node] += val*(end-start+1);
//		return ;
//	}
//	push_down(node, end-start+1);
//	ll mid = (start+end)>>1, lef = node<<1, rig = node<<1|1;
//	if(l<=mid)
//		update(lef, start, mid, l, r, val);
//	if(r>mid)
//		update(rig, mid+1, end, l, r, val);
//	push_up(node);
//}

//ll query(ll node, ll start, ll end, ll l, ll r) {
//	if(start>=l && end<=r) {
//		return sum[node];
//	}
//	push_down(node, end-start+1);
//	ll mid = (start+end)>>1, lef = node<<1, rig = node<<1|1, rs = 0;
//	if(l<=mid)
//		rs += query(lef, start, mid, l, r);
//	if(r>mid)
//		rs += query(rig, mid+1, end, l, r);
//	return rs;
//}

//int main(void) {
//	freopen("test", "r", stdin);
//	
//	scanf("%lld", &n);
//	for(int i=1; i<=n; i++)
//		scanf("%lld", arr+i);
//	build(1, 1, n);
//	scanf("%lld", &m);
//	for( ; m--; ) {
//		ll l, r, val;
//		scanf("%lld %lld %lld", &l, &r, &val);
//		update(1, 1, n, l, r, val);
//		printf("%lld\n", query(1, 1, n, 1, n));
//	}
//	return 0;
//}







#include <iostream>
#define MAXN 100005
using namespace std;

int n, m;
int arr[MAXN];
struct Node {
	int start, end, lazy, sum;
} tree[MAXN<<2];

void push_up(int node) {
	tree[node].sum = tree[node<<1].sum + tree[node<<1|1].sum;
}

void push_down(int node) {
	if(tree[node].lazy) {
		int len = tree[node].end - tree[node].start + 1;
		tree[node<<1].lazy += tree[node].lazy;
		tree[node<<1|1].lazy += tree[node].lazy;
		tree[node<<1].sum += tree[node].lazy*(len-(len>>1));
		tree[node<<1|1].sum += tree[node].lazy*(len>>1);
		tree[node].lazy = 0;
	}
}

void build(int node, int start, int end) {
	tree[node].lazy = 0;
	tree[node].start = start, tree[node].end = end;
	if(start == end) {
		tree[node].sum = arr[start];
		return;
	}
	int mid = (start+end)>>1;
	build(node<<1, start, mid);
	build(node<<1|1, mid+1, end);
	push_up(node);
}

void update(int node, int l, int r, int val) {
	if(tree[node].start==l && tree[node].end==r) {
		tree[node].lazy += val;
		tree[node].sum += val*(tree[node].end-tree[node].start+1);
		return ;
	}
	if(tree[node].start == tree[node].end) return ;
	int mid = (tree[node].start+tree[node].end)>>1;
	push_down(node);
	if(r<=mid)
		update(node<<1, l, r, val);
	else if(l>mid)
		update(node<<1|1, l, r, val);
	else {
		update(node<<1, l, r, val);
		update(node<<1|1, l, r, val);
	}
	push_up(node);
}

int query(int node, int l, int r) {
	if(tree[node].start>=l && tree[node].end<=r) {
		return tree[node].sum;
	}
	int mid = (tree[node].start+tree[node].end)>>1;
	push_down(node);
	if(r<=mid)
		return query(node<<1, l, r);
	else if(l>mid)
		return query(node<<1|1, l, r);
	else {
		return query(node<<1, l, r) + query(node<<1|1, l, r);
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	build(1, 1, n);
	scanf("%d", &m);
	for( ; m--; ) {
		int l, r, val;
		scanf("%d %d %d", &l, &r, &val);
		update(1, l, r, val);
		printf("%lld\n", query(1, l, r));
	}
	
	return 0;
}


























