#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#define MAXN 100005

using namespace std;

int n, q, x, arr[MAXN], psum[MAXN];

int binsearch(int lef, int rig, int x) {
	int mid;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(x < psum[mid]) rig = mid - 1;
		else lef = mid + 1;
	}
	if(x > psum[mid]) mid --;
	return mid;
}

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n)) {
		psum[0] = 0;
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			psum[i] = psum[i-1] + arr[i];
		}
		scanf("%d", &q);
		while(q--) {
			scanf("%d", &x);
			int idx = std::lower_bound(psum+1, psum+1+n, x) - psum;
			printf("%d\n", idx);
		}
	}
	return 0;
}

