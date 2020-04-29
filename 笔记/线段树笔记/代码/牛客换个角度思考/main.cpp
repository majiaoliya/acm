#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define ull unsigned long long int
#define QAQ (0)

#pragma GCC optimize(2)

using namespace std;

int n, m, a[MAXN<<2], tmp[MAXN<<2];
vector<int> vec[MAXN<<2];

void build(int rt, int lef, int rig) {
	if(lef == rig) {
		vec[rt].push_back(a[lef]);
		return ;
	}
	for(int i=lef; i<=rig; i++) vec[rt].push_back(a[i]);
	sort(vec[rt].begin(), vec[rt].end());
	int mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
}

int bsearch(int rt, int K) {
	vector<int>& rv = vec[rt];
	int lef = 0, rig = rv.size()-1, mid, rs = -1;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(rv[mid] <= K) {
			rs = mid;
			lef = mid + 1;
		} else {
			rig = mid - 1;
		}
	}
	return rs + 1;
}

int query(int rt, int lef, int rig, int L, int R, int K) {
	if(L<=lef && rig<=R) 
		return bsearch(rt, K);
	int mid = (lef + rig) >> 1, ret = 0;
	if(L <= mid) ret += query(rt<<1, lef, mid, L, R, K);
	if(mid < R) ret += query(rt<<1|1, mid+1, rig, L, R, K);
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d ", a+i);
	build(1, 1, n);
	while(m--) {
		int L, R, K;
		scanf("%d %d %d ", &L, &R, &K);
		printf("%d\n", query(1, 1, n, L, R, K));
	}




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



