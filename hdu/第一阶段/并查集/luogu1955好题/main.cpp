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
#include <map>
#include <queue>
#define MAXN ((int)1e6+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int a, b, n, m, q, pn, pre1[MAXN], ok; //pre2是不等集合
int A[MAXN], B[MAXN];

int fa(int* pre, int x) {
	int ret = x;
	while(~pre[ret]) ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

void union_xy(int* pre, int x, int y) {
	int rx = fa(pre, x), ry = fa(pre, y);
	if(rx != ry) pre[ry] = rx;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &q);
	while(q--) {
		scanf("%d ", &n);
		ok = true;
		memset(pre1, -1, sizeof(pre1));
		m = pn = 0;
		map<int, int> mp;
		for(int i=1; i<=n; i++) {
			int op;
			scanf("%d %d %d ", &a, &b, &op);
			if(mp.end() == mp.find(a)) {
				mp[a] = ++pn;
			}
			if(mp.end() == mp.find(b)) {
				mp[b] = ++pn;
			}
			int mpa = mp[a], mpb = mp[b];
			if(op) union_xy(pre1, mpa, mpb);
			else {
				m ++;
				A[m] = a, B[m] = b;
			}
		}
		for(int i=1; i<=m; i++) {
			int mpa = mp[A[i]], mpb = mp[B[i]];
			int rx = fa(pre1, mpa), ry = fa(pre1, mpb);
			if(rx == ry) { ok = false; break; }
		}
		printf("%s\n", ok ? "YES" : "NO");
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


