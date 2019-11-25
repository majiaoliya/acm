#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXN 100005
#define ll long long int
using namespace std;

int n, m, x, tot;

int pre[MAXN<<2], suf[MAXN<<2], mlen[MAXN<<1];
int len[MAXN<<2];

void build(int x, int lef, int rig) {
	len[x] = rig - lef + 1;
	pre[x] = suf[x] = mlen[x] = (rig - lef + 1);
	if(lef == rig) return ;
	int mid = (lef + rig) >> 1;
	build(x<<1, lef, mid);
	build(x<<1|1, mid+1, rig);
}

void push_up(int x) {
	pre[x] = pre[x<<1];
	suf[x] = suf[x<<1|1];
	mlen[x] = max(mlen[x<<1], mlen[x<<1|1]);
	mlen[x] = max(mlen[x], suf[x<<1] + pre[x<<1|1]);
	
	if(pre[x<<1] == len[x<<1])
		pre[x] += pre[x<<1|1];
	if(suf[x<<1|1] == len[x<<1|1])
		suf[x] += suf[x<<1];
}

void update(int x, int lef, int rig, int idx, int val) {
	if(lef == rig) {
		pre[x] = suf[x] = mlen[x] = val;
		return ;
	}
	int mid = (lef + rig) >> 1;
	if(idx<=mid) update(x<<1, lef, mid, idx, val);
	else update(x<<1|1, mid+1, rig, idx, val);
	push_up(x);
}

int query(int x, int lef, int rig, int idx, int val) {
	if(lef == rig) return mlen[x];
	int mid = (lef + rig) >> 1;
	if(idx <= mid) 
}

int main(void) {
	freopen("test", "r", stdin);
	char op[6];
	while(EOF != scanf("%d%d", &n, &m)) {
		build(1, 1, n);
	}
	return 0;
}
