#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 1000005
#include <map>
#include <unordered_set>
#include <queue>
#define ll long long int
#define INF ((int)1e9+7)
using namespace std;

int n, m, mod=100003, cnt[MAXN], d[MAXN], vis[MAXN];

struct Edge {
	int to, val;
	Edge() : to(0), val(1) { }
	Edge(int _to) : to(_to), val(1) { }
};

vector<Edge> G[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=m; i++) {
		int from, to;
		scanf("%d %d ", &from, &to);
		G[from].push_back(Edge(to));
		G[to].push_back(Edge(from));
	}

	queue<int> q;
	q.push(1), d[1] = 0, cnt[1] = 1, vis[1] = true;
	for(int i=1; i<=n; i++) d[i] = INF;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		vis[now] = true;
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to, td = G[now][i].val;
			//if(!vis[v]) { vis[v]=true, d[v]=d[now]+td, q.push(v); }
			//if(d[v] == d[now]+td) cnt[v] += cnt[now], cnt[v] %= mod;
			if(d[v] < d[now]+td && !vis[v]) {
				d[v] = d[now]+td;
				cnt[v] = cnt[now];
				vis[v] = true, q.push(v);
			} else if(vis[v] && d[v] == d[now]+td) {
				cnt[v] += cnt[now];
			}
			cnt[v] %= mod;
		}
	}
	for(int i=1; i<=n; i++)
		printf("%d\n", cnt[i]);



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




