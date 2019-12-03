#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 505
#include <map>
#include <queue>
#include <unordered_set>
#define INF (0x3f3f3f3f)
#define QAQ (0)
#define ll long long int

using namespace std;

/**
 * 给定一张图,有点权和边权,求节点数量最小的最短路,边长=点权+边权
 * 先把起点和终点的点权设置为0在求最短路就行了td=edge(u,v)+w[u]
 */

map<string, int> mp;
string str[MAXN];
string from, to;

int n, m, w[MAXN], d[MAXN], vis[MAXN], sum[MAXN], pre[MAXN], s, e;

struct Edge {
	int to, d;
	Edge(int _to=0, int _d=0) : to(_to), d(_d) { }
} ;

vector<Edge> G[MAXN];
string path[MAXN];

int spfa() {
	queue<int> q;
	for(int i=0; i<=n; i++) d[i] = INF;
	s = mp[from], e = mp[to];
	q.push(s); vis[s] = true; d[s] = 0, w[s] = 0, w[e] = 0;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		vis[now] = true;
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to, td = G[now][i].d + w[now];
			if(d[v] > d[now]+td) {
				d[v] = d[now] + td;
				pre[v] = now;
				sum[v] = sum[now] + 1;
				if(vis[v]) continue ;
				vis[v] = true;
				q.push(v);
			} else if(d[v] == d[now]+td) {
				if(sum[v] > sum[now]+1) {
					sum[v] = sum[now] + 1;
					pre[v] = now;
					if(vis[v]) continue ;
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if(d[e] == INF) return -1;

	int now = e, cnt = sum[e];
	while(now) {
		path[cnt] = str[now];
//		cout << "path[" << cnt << "]=" << str[now] << endl; 
		now = pre[now];
		cnt --;
	}
	return d[e];
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> str[i] >> w[i];
		mp[str[i]] = i;
	}
	cin >> m;
	for(int i=1; i<=m; i++) {
		int d;
		cin >> from >> to >> d;
		int u = mp[from], v = mp[to];
		G[u].push_back(Edge(v,d));
		G[v].push_back(Edge(u,d));
	}
	cin >> from >> to;
#ifdef debug2
	for(int i=1; i<=n; i++) {
		cout << i << " " << G[i].size() << ":";
		for(int k=0; k<(int)G[i].size(); k++)
			cout << "->" << G[i][k].to;
		cout << endl;
	}
#endif
	int ans = spfa();
	if(ans == -1) {
		cout << "Why not go home by plane?";
		return QAQ;
	}
	cout << ans << endl;
	for(int i=0; i<=sum[e]; i++) {
		if(i) cout << "->";
		cout << path[i];
	}




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

