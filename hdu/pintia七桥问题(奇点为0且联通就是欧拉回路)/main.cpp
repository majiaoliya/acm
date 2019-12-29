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
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, ind[MAXN], u, v, pre[MAXN];

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1) ret = pre[ret];
	if(x != ret) pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry) pre[ry] = rx;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	memset(pre, -1, sizeof(pre));

	while(m --) {
		scanf("%d %d ", &u, &v);
		union_xy(u, v);
		ind[u] ++, ind[v] ++;
	}
	int cnt = 0, cnt2 = 0;
	for(int i=1; i<=n; i++) if(-1 == pre[i]) cnt ++;
	if(cnt > 1) {
		printf("0\n");
		return 0;
	}
	for(int i=1; i<=n; i++)
		if(ind[i] & 1) cnt2 ++;
	//没有奇点(入度是奇数)且联通 就是欧拉回路
	printf("%d\n", cnt2 ? 0 : 1);

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


