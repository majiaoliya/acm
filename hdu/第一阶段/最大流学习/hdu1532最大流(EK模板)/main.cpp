#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
const int MAXN = 220;
const int inf = 1e8;

int n, m, a, b, c, g[MAXN][MAXN], flow[MAXN], pre[MAXN];
bool vis[MAXN];

int bfs() {
	memset(vis, false, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	for(int i=1; i<=n; i++)
		flow[i] = inf;
	vis[1] = true;
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=1; i<=n; i++) {
			if(!vis[i] && g[u][i]>0) {
				vis[i] = true;
				flow[i] = min(flow[u], g[u][i]);
				pre[i] = u;
				q.push(i);
			}
		}
	}
	if(!vis[n] || n==1) return -1;
	return flow[n];
}

int ek() {
	int maxflow = 0, d, res, tmp;
	while(-1 != (d=bfs())) {
		maxflow += d;
		tmp = n;
		while(tmp != 1) {
			res = pre[tmp];
			g[res][tmp] -= d;
			g[tmp][res] += d;
			tmp = res;
		}
	}
	return maxflow;
}

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &m, &n)) {
		memset(g, false, sizeof(g));
		for(int i=1; i<=n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			g[a][b] += c;
		}
		printf("%d\n", ek());
	}
	return 0;
}
