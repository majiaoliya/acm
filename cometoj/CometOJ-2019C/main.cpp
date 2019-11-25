#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
#define ll long long int
const int MAXN = 200005;

int n, m, x;
struct Node {
	int l, r;
	Node() : l(0), r(0) { }
	Node(int _l, int _r) : l(_l), r(_r) { }
} a[MAXN], b[MAXN];
queue<Node> q1, q2;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	int l, r;
	for(int i=1; i<=n; i++) {
		scanf("%d %d", &l, &r);
		a[i].l = l, a[i].r = r;
	}
	for(int i=1; i<=m; i++) {
		scanf("%d %d", &l, &r);
		b[i].l = l, b[i].r = r;
	}
	
	int ans = 0;
	for(int i=1; i<=n; i++) {
		int lef = 1, rig = m, mid, lidx = -1, ridx = -1;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(b[mid].l>a[i].r) {
				rig = mid - 1;
			} else {
				ridx = mid;
				lef = mid + 1;
			}
		}
		lef = 1, rig = m;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(b[mid].r < a[i].l) {
				lef = mid + 1;
			} else {
				lidx = mid;
				rig = mid - 1;
			}
		}
//		printf("%d %d\n", lidx, ridx);
		if(lidx==-1 || ridx==-1) continue;
		ans += ridx - lidx + 1;
	}
	printf("%d\n", ans);

	return 0;
}
