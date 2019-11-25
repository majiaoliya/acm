#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define MAXN 1000005
using namespace std;

struct Query {
	int L, R;
} q[MAXN];

int n, m, mm, lsh[MAXN], arr[MAXN], lazy[MAXN<<2];
int tree[MAXN<<2];

void build(int x, int lef, int rig) {
	tree[x] = arr[lef] = 0;
	if(lef == rig) return ;
	int mid = (lef + rig) >> 1;
	build(x<<1, lef, mid);
	build(x<<1|1, mid+1, rig);
}

void push_down(int x) {
	if(lazy[x]) {
		lazy[x<<1] = lazy[x<<1|1] = lazy[x];
		lazy[x] = 0;
	}
}

void update(int x, int lef, int rig, int L, int R, int val) {
	if(L<=lef && rig<=R) {
		lazy[x] = val;
		return ;
	}
	push_down(x);
	int mid = (lef + rig) >> 1;
	if(L<=mid) update(x<<1, lef, mid, L, R, val);
	if(mid<R) update(x<<1|1, mid+1, rig, L, R, val);
}

void push_all(int x, int lef, int rig) {
	if(lef == rig) {
		arr[lef] = lazy[x];
		return ;
	}
	push_down(x);
	int mid = (lef + rig) >> 1;
	push_all(x<<1, lef, mid);
	push_all(x<<1|1, mid+1, rig);
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d %d", &q[i].L, &q[i].R);
		lsh[++mm] = q[i].L, lsh[++mm] = q[i].R;
	}
	sort(lsh+1, lsh+1+mm);
	mm = std::unique(lsh+1, lsh+1+mm) - (lsh+1);
	build(1, 1, mm);
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		int L = std::lower_bound(lsh+1, lsh+1+n, q[i].L)-lsh-1;
		int R = std::lower_bound(lsh+1, lsh+1+n, q[i].R)-lsh-1;
		update(1, 1, mm, L, R, ++cnt);
	}
	push_all(1, 1, mm);
	set<int> seta;
	for(int i=1; i<=mm; i++)
		seta.insert(arr[i]);
	printf("%d\n", seta.size());
	return 0;
}
