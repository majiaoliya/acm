#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
const int maxn = 220;
const int inf = 1<<30;

struct Edge {
	int to, cap, rev;
} ;

vector<Edge> G[maxn];
int used[maxn], n, m;

void add(int from, int to, int cap) {
	G[from].push_back((Edge) {to, cap, G[to].size()});
	G[to].push_back((Edge) {from, 0, G[from].size()-1});
}

int dfs(int v, int t, int f) {
	if(v == t) return f;
	printf("%d->", v);
	used[v] = 1;
	for(int i=0; i<G[v].size(); i++) {
		Edge& e = G[v][i];
		if(!used[e.to] && e.cap>0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
		printf("\n");
	}
	return 0;
}

int ff(int s, int t) {
	int flow = 0;
	while(1) {
		memset(used, false, sizeof(used));
		int f = dfs(s, t, inf);
		if(f == 0) return flow;
		flow += f;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		for(int i=1; i<=n; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			add(a, b, c);
		}
		printf("%d\n", ff(1, 2));
		for(int i=1; i<=n; i++)
			G[i].clear();
	}
	return 0;
}
