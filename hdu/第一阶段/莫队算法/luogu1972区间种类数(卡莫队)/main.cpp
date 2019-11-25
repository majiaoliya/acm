#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <set>
#include <algorithm>
#define MAXN 1000005
#define ll long long int
using namespace std;

int n, m, arr[MAXN], res, ans[MAXN], block = 500;
int cnt[MAXN];
struct Q {
	int l, r, id;
	bool operator < (const Q& o) const {
		//同一块按右端点排 , 不同块按块排
		return (l/500)==(o.l/500) ? (r<o.r) : ((l/500)<(o.l/500));
	}
} q[MAXN];

bool cmp (const Q& a, const Q& b) {
    return (a.l / block) ^ (b.l / block)? a.l < b.l : (a.l / block) & 1? a.r < b.r: a.r > b.r;
}

void add(int idx) {
	cnt[arr[idx]] ++;
	if(cnt[arr[idx]] == 1) res ++;
}

void sub(int idx) {
	cnt[arr[idx]] --;
	if(cnt[arr[idx]] == 0) res --;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", arr+i);

	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].id = i;
	}

	sort(q, q+m, cmp);
//	for(int i=0; i<m; i++)
//		printf("[%d,%d], ", q[i].l, q[i].r);
//	printf("\n");
	int l = 1, r = 0;
	for(int i=0; i<m; i++) {
	//	while(l<q[i].l) { sub(l), l--; }
	//	while(l>q[i].l) { add(++l); }
	//	while(r<q[i].r) { add(++r); }
	//	while(r>q[i].r) { sub(r), r--; }
		while(r<q[i].r) { r++, add(r); }
		while(r>q[i].r) { sub(r), r--; }
		while(l<q[i].l) { sub(l), l++; }
		while(l>q[i].l) { l--, add(l); }
		ans[q[i].id] = res;	
	}
	for(int i=0; i<m; i++)
		printf("%d\n", ans[i]);

	return 0;
}
