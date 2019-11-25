//#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN ((int)1e6+7)
int n, k, a[MAXN], q[MAXN];

int binsearch0(int lef, int rig, int key) {
	int ret = lef-1, mid;
	while(lef<=rig) {
		mid = (lef + rig) >> 1;
		if(a[q[mid]] <= key) ret = mid, lef = mid+1;
		else rig = mid - 1;
	}
	return ret;
}

int binsearch1(int lef, int rig, int key) {
	int ret = lef-1, mid;
//	printf("binsearch1 lef:%d rig:%d key:%d ", lef, rig, key);
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(a[q[mid]] >= key) ret = mid, lef = mid+1;
		else rig = mid - 1;
	}
//	printf(" ret:%d\n", ret);
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) scanf("%d", a+i);
	int lef = 0, rig = -1;
	for(int i=0; i<n; i++) {
		if(lef<=rig && q[lef]<i-k+1) lef ++;
//		while(lef<=rig && a[q[rig]]>=a[i]) rig --;
		rig = binsearch0(lef, rig, a[i]);
		q[++rig] = i;
		if(i>=k-1) printf("%d ", a[q[lef]]);
	}
	puts("");
	lef = 0, rig = -1;
	for(int i=0; i<n; i++) {
		if(lef<=rig && q[lef]<i-k+1) lef ++;
//		while(lef<=rig && a[q[rig]]<=a[i]) rig --;
		rig = binsearch1(lef, rig, a[i]);
		q[++rig] = i;
		if(i>=k-1) printf("%d ", a[q[lef]]);
	}
	puts("");
	return 0;
}
