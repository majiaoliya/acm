//luogu1621
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
#define QAQ (0)

using namespace std;

int A, B, pre[MAXN], pn, vis[MAXN], K, ans;

int fa(int x) {
	int ret = x;
	while(~pre[ret]) ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry) pre[ry] = rx, ans --;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d ", &A, &B, &K);
	memset(pre, -1, sizeof(pre));
	vis[0] = vis[1] = true;
	ans = B-A+1;
	for(int i=2; i<=B; i++) {
		if(vis[i]) continue ;
		if(i >= K) { //合并
			for(int k=(i<<1); k<=B; k+=i)  {
				vis[k] = true;
				if(k-i >= A) union_xy(k, k-i);
			}
		} else {
			for(int k=(i<<1); k<=B; k+=i)
				vis[k] = true;
		}
	}
	printf("%d\n", ans);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


