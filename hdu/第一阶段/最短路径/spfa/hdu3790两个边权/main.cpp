#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#define INF 9999999
#define MAXN 100005
using namespace std;

const int maxn = 1005;
int n, m, s, e, va[maxn], vb[maxn], vis[maxn];

struct Edge {
	int to, v1, v2;
	Edge() : to(-1), v1(INF), v2(INF) { }
	Edge(int _to, int _v1, int _v2) : to(_to), v1(_v1), v2(_v2) { }
} ;
vector<Edge> G[MAXN];

void init() {
	for(int i=0; i<=n; i++)
		G[i].clear(), va[i] = vb[i] = INF, vis[i] = false;
}

void spfa() {
	queue<int> q;
	q.push(s), va[s] = vb[s] = 0, vis[s] = true;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		vis[now] = false;
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to, v1 = G[now][i].v1, v2 = G[now][i].v2;
			if(va[v] > va[now]+v1) {
				va[v] = va[now] + v1;
				vb[v] = vb[now] + v2;
				if(vis[v]) continue ;
				q.push(v);
				vis[v] = true;
			} else if(va[v] == va[now]+v1) {
				vb[v] = min(vb[v], vb[now]+v2);
				if(vis[v]) continue ;
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	
	while(~scanf("%d %d", &n, &m) && (n+m)) {
		init();
		for(int i=0, x, y, v1, v2; i<m; i++) {
			scanf("%d %d %d %d", &x, &y, &v1, &v2);
			G[x].push_back(Edge(y, v1, v2));
			G[y].push_back(Edge(x, v1, v2));
		}
		scanf("%d %d", &s, &e);
		spfa();
		printf("%d %d\n", va[e], vb[e]);
	}
	return 0;
}
