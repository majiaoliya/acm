#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <queue>
#include <unordered_set>
#define ll long long int
#define INF (1<<30)
using namespace std;

int n, m, vis[MAXN], d[MAXN];

struct Edge {
	int to, val;
	Edge(int _to=0, int _val=0) : to(_to), val(_val) { }
};

vector<Edge> G[MAXN];

int spfa() {
	queue<int> q;
	for(int i=0; i<=n; i++) d[i] = INF;
	q.push(1), vis[1] = true, d[1] = 0;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		vis[now] = false;
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to, td = G[now][i].val;
			if(d[v] > d[now]+td) {
				d[v] = d[now] + td;
				if(vis[v]) continue ;
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return d[n];
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=0; i<m; i++) {
		int u, v, val;
		scanf("%d %d %d ", &u, &v, &val);
		G[u].push_back(Edge(v, val));
		G[v].push_back(Edge(u, val));
	}
	printf("%d\n", spfa());







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


