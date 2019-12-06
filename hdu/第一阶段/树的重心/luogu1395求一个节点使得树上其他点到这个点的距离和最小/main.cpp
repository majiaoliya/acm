#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)5e5+7)
#include <map>
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 题意:给定一颗树,求一个节点,使得其他节点到这个节点的路径和最小
 * 直接dfs求树的重心,再bfs路径和即可
 */

int n, u, v, vis[MAXN], sz[MAXN], ans = 0x3f3f3f3f, id = 0x3f3f3f3f;
vector<int> G[MAXN];

void dfs(int now) { //求树的重心
	vis[now] = true;
	sz[now] = 1;
	int tmax = 0;
	for(int i=0; i<(int)G[now].size(); i++) {
		int chl = G[now][i];
		if(vis[chl]) continue ;
		dfs(chl);
		sz[now] += sz[chl];
		tmax = max(tmax, sz[chl]);
	}
	tmax = max(tmax, n-sz[now]);
	if(tmax<ans || (tmax==ans&&now<id)) {
		ans = tmax;
		id = now;
	}
}

#include <queue>
int sum = 0;
struct Node {
	int v, step;
	Node(int _v=0, int _step=0) : v(_v), step(_step) { }
};
void bfs(int root) {
	queue<Node> q;
	q.push(Node(root, 0)); 
	memset(vis, false, sizeof(vis));
	while(!q.empty()) {
		auto now = q.front(); q.pop();
//		printf("bfs%d\n", now.v);
		vis[now.v] = true;
		sum += now.step;
		for(int i=0; i<(int)G[now.v].size(); i++) {
			int chl = G[now.v][i];
			if(!vis[chl])
				q.push(Node(G[now.v][i], now.step+1));
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<n; i++) {
		scanf("%d %d ", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	//for(int i=1; i<=n; i++)
	//	forvec(G[i]);
	dfs(1);
	bfs(id);
	printf("%d %d\n", id, sum);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

