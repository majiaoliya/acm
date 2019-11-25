/**
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#define ll long long int
#define MAXN 200005
using namespace std;

ll t, n, m, mm, arr[MAXN], lsh[MAXN], tree[MAXN<<2];

#define push_up (tree[x] = tree[x<<1] + tree[x<<1|1])

void update(ll x, ll lef, ll rig, ll idx) {
	if(lef == rig) {
		tree[x] ++;
		return ;
	}
	ll mid = (lef + rig) >> 1;
	if(idx<=mid) update(x<<1, lef, mid, idx);
	else update(x<<1|1, mid+1, rig, idx);
	push_up;
}

ll query(ll x, ll lef, ll rig, ll k) {
	if(lef == rig) return lef;
	ll mid = (lef + rig) >> 1;
	ll rson = tree[x<<1|1];
	if(rson >= k) return query(x<<1|1, mid+1, rig, k);
	else return query(x<<1, lef, mid, k);
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld", &n, &m);
		memset(tree, false, sizeof(tree));
		for(int i=1; i<=n; i++) {
			scanf("%lld", arr+i);
			lsh[i] = arr[i];
		}
		sort(lsh+1, lsh+1+n);
		mm = unique(lsh+1, lsh+1+n) - (lsh+1);
		ll sum = 0, c = 0;
		for(int i=1; i<=n; i++) {
			sum += arr[i];
			int idx = lower_bound(lsh+1, lsh+1+mm, arr[i]) - lsh;
			update(1, 1, mm, idx);
			ll temp = sum;
			if(c++) printf(" ");
			if(temp <= m) printf("0");
			else {
				ll k = 1;
				while(k < n) {
					temp -= lsh[query(1, 1, mm-1, k)];
					if(temp <= m) {
						printf("%lld", k);
						break;
					}
					k ++;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
*/




#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int
#define MAXN 200005
ll n, m, mm, arr[MAXN], lsh[MAXN];

struct Node {
	int lef, rig, sum, num;
} tree[MAXN<<2];

void build(int x, int lef, int rig) {
	tree[x].lef = lef, tree[x].rig = rig;
	tree[x].sum = tree[x].num = 0;
	if(lef == rig) return ;
	int mid = (lef + rig) >> 1;
	build(x<<1, lef, mid);
	build(x<<1|1, mid+1, rig);
}

#define push_up (tree[x].num = tree[x<<1].num + tree[x<<1|1].num, tree[x].sum = tree[x<<1].sum + tree[x<<1|1].sum)

void update(int x, int idx) {
	int lef = tree[x].lef, rig = tree[x].rig;
	if(lef == rig) {
		tree[x].num ++;
		tree[x].sum += lsh[idx];
		return ;
	}
	int mid = (lef + rig) >> 1;
	if(idx<=tree[x<<1].rig) update(x<<1, idx);
	else update(x<<1|1, idx);
//	push_up;
	tree[x].sum = tree[x<<1].sum + tree[x<<1|1].sum;
	tree[x].num = tree[x<<1].num + tree[x<<1|1].num;
}

int min(int x, ll y) { return x < y ? x : y; }

int query(int x, int val) {
	int lef = tree[x].lef, rig = tree[x].rig;
	if(tree[x].sum <= val) return tree[x].num;
	if(lef == rig) 
		return min(tree[x].num, val/lsh[lef]);
	if(tree[x<<1].sum >= val)
		return query(x<<1, val);
	else 
		return tree[x<<1].num + query(x<<1|1, val-tree[x<<1].sum);
}

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld", &n, &m);
		for(int i=1; i<=n; i++) {
			scanf("%lld", arr+i);
			lsh[i] = arr[i];
		}
		sort(lsh+1, lsh+1+n);
		mm = unique(lsh+1, lsh+1+n) - (lsh+1);
		build(1, 1, mm);
		int sum = 0, pos;
		for(int i=1; i<=n; i++) {
			sum += arr[i];
			if(i == 1)
			   	printf("0 ");
			else 
				printf("%d ", i-1-query(1, m-arr[i]));
			
			pos = lower_bound(lsh+1, lsh+1+mm, arr[i]) - lsh;
			update(1, pos);
		}
		printf("\n");
	}
	return 0;
}
