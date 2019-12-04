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
#define INF 0x3f3f3f3f
#include <map>
#include <queue>
#define ll long long int

using namespace std;

int n, m, s, t;
/**
 * 紫书上的最大流EK板子
 */
struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) { }
} ;

struct EK {
	int n, m;
	vector<Edge> edges; //边数的两倍
	vector<int> G[MAXN]; //邻接表,G[i][j]表示节点i的第j条边在e数组的序号
	int a[MAXN]; //当起点到i上的可改进量
	int p[MAXN]; //最短路树上的入弧编号

	void init(int n) {
		for(int i=0; i<n; i++) G[i].clear();
		edges.clear();
	}

	void addedge(int from, int to, int cap) {
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}

	int max_flow(int s, int t) {
		int flow = 0;
		for( ; ; ) {
			memset(a, 0, sizeof(a));
			queue<int> Q;
			Q.push(s); a[s] = INF; 
			while(!Q.empty()) {
				int x = Q.front(); Q.pop();
				for(int i=0; i<(int)G[x].size(); i++) {
					Edge& e = edges[G[x][i]];
					if(!a[e.to] && e.cap>e.flow) {
						p[e.to] = G[x][i];
						a[e.to] = min(a[x], e.cap-e.flow);
						Q.push(e.to);
					}
				}
				if(a[t]) break;
			}
			if(!a[t]) break;
			for(int u=t; u!=s; u=edges[p[u]].from) {
				edges[p[u]].flow += a[t];
				edges[p[u]^1].flow -= a[t];
			}
			flow += a[t];
		}
		return flow;
	}
};

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d %d ", &n, &m, &s, &t);
	EK ek;
	ek.init(n);
	for(int i=1; i<=m; i++) {
		int u, v, w;
		scanf("%d %d %d ", &u, &v, &w);
		ek.addedge(u, v, w);
	}
	printf("%d\n", ek.max_flow(s, t));







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

