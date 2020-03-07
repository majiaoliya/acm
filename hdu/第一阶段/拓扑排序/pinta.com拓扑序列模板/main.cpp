#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100005
#include <map>
#include <queue>
#define ll long long int

using namespace std;

int T, n, m;

int ind[MAXN], pn, ans[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];

void init() {
	memset(ind, 0, sizeof(ind));
	memset(ans, 0, sizeof(ans));
	pn = 0;
}

queue<int> q;
int topsort() { //拓扑排序
	int cnt = 0;
	while(!q.empty()) { 
		int now = q.front(); q.pop();
		ans[pn++] = now;
		cnt ++;
		for(int i=0; i<(int)G[now].size(); i++) {
			int chl = G[now][i];
			ind[chl] --;
			if(!ind[chl]) q.push(chl);
		}
	}
	return cnt; //小于n个点出队列就是有环
}

bool cmp(int a, int b) { return a < b; }

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &T);
	while(T--) {
		scanf("%d %d ", &n, &m);
		init();
		for(int i=0; i<m; i++) {
			int from, to;
			scanf("%d %d ", &to, &from);
			G[from].push_back(to);
			ind[to] ++;
		}
		for(int i=1; i<=n; i++) {
			if(!ind[i]) q.push(i);
			sort(G[i].begin(), G[i].end(), cmp);
		}
#ifdef debug2
		for(int i=1; i<=n; i++) {
			printf("%d:", i);
			for(int k=0; k<(int)G[i].size(); k++) {
				printf("->%d ", G[i][k]);
			}
			printf("\n");
		}
#endif
		int cnt = topsort();
		if(cnt < n) printf("-1 \n");
		else {
			for(int i=0; i<pn; i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

