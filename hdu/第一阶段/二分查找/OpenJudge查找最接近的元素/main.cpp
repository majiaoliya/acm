#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int len, n, m, arr[MAXN];

int lef(int x) {
	int lef = 1, rig = n-1, mid, idx = -1;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(arr[mid] <= x) idx = mid, lef = mid + 1;
		else rig = mid - 1;
	}
	return idx;
}

int rig(int x) {
	int lef = 1, rig = n-1, mid, idx = -1;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(arr[mid] >= x) idx = mid, rig = mid - 1;
		else lef = mid + 1;
	}
	return idx;
}

#define abs(x) (x > 0 ? x : -x)
int main(void) {
	freopen("test", "r", stdin);

	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", arr+i);
	scanf("%d", &m);
	while(m--) {
		int x, rs;
		scanf("%d", &x);
		int l = lef(x);
		int r = l+1;
		if(l == -1) rs = arr[0];
		else {
			if(r<=n && abs(arr[r]-x)<abs(arr[l]-x)) rs = arr[r];
			else rs = arr[l];
		}
		printf("%d\n", rs);
//		printf("l:%d, r:%d  %d\n", l, r, rs);
	}
	return 0;
}
