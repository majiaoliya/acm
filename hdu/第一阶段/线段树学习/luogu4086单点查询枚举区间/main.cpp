//luoguP4086
#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100050
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, m, minx[MAXN<<2], arr[MAXN], L, R, psum[MAXN];

inline void push_up(int rt) { minx[rt] = min(minx[rt<<1], minx[rt<<1|1]); }

void build(int rt, int lef, int rig) {
	if(lef == rig) {
		scanf("%d ", arr+lef);
		minx[rt] = arr[lef];
		return ;
	}
	int mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}

int query(int rt, int lef, int rig) {
	if(L<=lef && rig<=R) return minx[rt];
	int mid = (lef + rig) >> 1, ret = 0x3f3f3f3f;
	if(L <= mid) ret = query(rt<<1, lef, mid);
	if(mid < R) ret = min(query(rt<<1|1, mid+1, rig), ret);
	return ret;
}

int main() {
#ifdef debug
//	freopen("test", "r", stdin);
	freopen("/home/majiao/下载/testdata(7).in", "r", stdin);
//	freopen("/home/majiao/下载/testdata.out", "r", stdin);
//	freopen("out", "w", stdout);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	build(1, 1, n);
	for(int i=1; i<=n; i++) psum[i] = psum[i-1] + arr[i];
	double ans = -1;
	vector<int> vec;
	for(int i=1; i<=n-2; i++) {
		L = i+1, R = n;
		double tmin = query(1, 1, n);
		double tsum = psum[n] - psum[i];
		int len = i==n-2 ? 1 : R-L;
		double key = (tsum-tmin) / len;
//		printf("%d key:%.2lf [%d %d] len:%d\n", i, key, L, R, len);
		if(key < ans) continue ;
		if(key > ans) vec.clear();
		ans = max(ans, key);
		vec.push_back(i);
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<(int)vec.size(); i++) {
		printf("%d\n", vec[i]);
	}
	
//	vector<int> a;
//	int x;
//	while(~scanf("%d ", &x)) a.push_back(x);
//	printf("int arr[]={");
//	for(int i=0; i<(int)a.size(); i++) {
//		if(i) printf(",");
//		printf("%d", a[i]);
//	}
//	printf("};");


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

