#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 200005
#include <map>
#include <unordered_set>
#define INF (99999999)
#include <queue>

#define ll long long int

using namespace std;

int n, m, vis[MAXN];
double d[MAXN];

struct Edge {
	int to;
	double val;
//	Edge() : to(-1), val(INF) { }
	Edge(int _to, double _val) : to(_to), val(_val) { }
} ;

vector<Edge> G[MAXN];

void spfa(int s) {
	queue<int> q;
	q.push(s), d[s] = 1, vis[s] = 1;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		vis[now] = false;
//		forit(d, 0, 10, "d");
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to;
			double td = G[now][i].val;
			if(d[v] < d[now]*td) {
				d[v] = d[now]*td;
				if(vis[v]) continue ;
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

void pg() {
	for(int i=1; i<=n; i++) {
		printf("%d: ", i);
		for(int k=0; k<G[i].size(); k++) {
			printf("->%lf ", G[i][k].val);
		}	
		printf("\n");
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int from, to, val;
		scanf("%d %d %d ", &from, &to, &val);
		G[from].push_back(Edge(to, 1-val/100.0));
		G[to].push_back(Edge(from, 1-val/100.0));
	}
	int s, e;
	scanf("%d %d ", &s, &e);
	spfa(s);
	printf("%.8lf\n", 100/d[e]);
	



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

