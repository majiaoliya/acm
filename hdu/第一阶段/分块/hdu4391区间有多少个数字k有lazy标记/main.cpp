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
#include <math.h>
#include <unordered_set>
//#define ll long long int

using namespace std;

int n, m, block, num, arr[MAXN], belong[MAXN];

struct Node {
	int l, r, lazy;
	map<int, int> mp;
} b[MAXN];

void build() {
	block = sqrt(n);
	if(n%block) num = n/block + 1;
	else num = n/block;
	for(int i=1; i<=num; i++)
		b[i].l = (i-1)*block+1, b[i].r = i*block, b[i].mp.clear(), b[i].lazy = -1;
	b[num].r = n;
	for(int i=1; i<=n; i++) belong[i] = (i-1)/block + 1;
}

void push_down(int now) {
	if(-1 == b[now].lazy) return ;
	for(int i=b[now].l; i<=b[now].r; i++) arr[i] = b[now].lazy;
	b[now].mp.clear(); 
	b[now].mp[b[now].lazy] = (b[now].r - b[now].l + 1);
	b[now].lazy = -1;
}

void update(int x, int y, int k) {
	int xx = belong[x], yy = belong[y];
	push_down(xx), push_down(yy);
	if(xx == yy) {
		for(int i=x; i<=y; i++) {
			b[xx].mp[arr[i]] --;
			arr[i] = k;
			b[xx].mp[arr[i]] ++;
		}
		return ;
	}
	for(int i=x; i<=b[xx].r; i++) {
		b[xx].mp[arr[i]] --;
		arr[i] = k;
		b[xx].mp[arr[i]] ++;
	}
	for(int i=b[yy].l; i<=y; i++) {
		b[yy].mp[arr[i]] --;
		arr[i] = k;
		b[yy].mp[arr[i]] ++;
	}
	for(int i=xx+1; i<yy; i++) b[i].lazy = k;
}

int query(int x, int y, int k) {
	int xx = belong[x], yy = belong[y], ret = 0;
	push_down(xx), push_down(yy);
	if(xx == yy) {
		for(int i=x; i<=y; i++) ret += (k == arr[i]);
		return ret;
	}
	for(int i=x; i<=b[xx].r; i++) ret += (k == arr[i]);
	for(int i=b[yy].l; i<=y; i++) ret += (k == arr[i]);
	for(int i=xx+1; i<yy; i++)
		if(-1 == b[i].lazy) {
			if(b[i].mp.find(k) != b[i].mp.end()) ret += b[i].mp[k];
		} else if(k == b[i].lazy) {
			ret += (b[i].r - b[i].l + 1);
		}
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m)) {
		build();
		for(int i=1; i<=n; i++) {
			scanf("%d ", arr+i);
			b[belong[i]].mp[arr[i]] ++;
		}
		while(m--) {
			int op, L, R, k;
			scanf("%d %d %d %d ", &op, &L, &R, &k);
			L ++, R ++;
			if(op == 1) update(L, R, k);
			else printf("%d\n", query(L, R, k));
		}
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

