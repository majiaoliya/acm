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
#define INF (1<<30)
#include <map>
#include <unordered_set>
#include <queue>
#define ll long long int

using namespace std;
// 练习一下蜗牛一般的spfa算法吧

int n, m, S, E, w1[MAXN], w2[MAXN], vis[MAXN];
struct Edge {
	int to, wa, wb;
	Edge(int _to, int _wa, int _wb) : to(_to), wa(_wa), wb(_wb) { }
}; 

vector<Edge> G[MAXN];

inline void init() {
	for(int i=0; i<n+5; i++)
		w1[i] = w2[i] = INF;
}

void spfa() {
	init();
	queue<int> q;
	q.push(S), vis[S] = true, w1[S] = w2[S] = 0;
	while(!q.empty()) {
		int now = q.front();
//		printf("%d size:%d\n", now, q.size());
		q.pop();
		vis[now] = false;
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to, a = G[now][i].wa, b = G[now][i].wb;
			if(w1[v] > w1[now]+a) {
				w1[v] = w1[now] + a;
				w2[v] = w2[now] + b;
				if(vis[v]) continue ;
				vis[v] = true;
				q.push(v);
			} else if(w1[v] == w1[now]+a) {
				w2[v] = min(w2[v], w2[now]+b);
				if(vis[v]) continue ;
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d %d ", &n, &m, &S, &E);
	for(int i=0; i<m; i++) {
		int u, v, x, y;
		scanf("%d %d %d %d ", &u, &v, &x, &y);
		G[u].push_back(Edge(v, x, y));
		G[v].push_back(Edge(u, x, y));
	}
	spfa();
//	forarr(w1, 0, n-1);
	printf("%d %d\n", w1[E], w2[E]);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


