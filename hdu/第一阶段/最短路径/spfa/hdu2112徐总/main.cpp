#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#define INF 9999999
#define MAXN 10005
using namespace std;

int n, m, d[MAXN], vis[MAXN];

struct Edge {
	int to, val;
	Edge() : to(-1), val(INF) { }
	Edge(int _to, int _val) : to(_to), val(_val) { }
} ;

vector<Edge> G[MAXN];
map<string, int> mp;

void init() {
	for(int i=0; i<MAXN; i++)
		G[i].clear(), d[i] = INF, vis[i] = false;
}

//void spfa() {
//	queue<int> q;
//	q.push(1), vis[1] = true, d[1] = 0;
//	while(!q.empty()) {
//		int now = q.front();
//		q.pop();
//		vis[now] = false;
//		for(int i=0; i<(int)G[now].size(); i++) {
//			int v = G[now][i].to, td = G[now][i].val;
//			if(d[v] > d[now]+td) {
//				d[v] = d[now] + td;
//				if(vis[v]) continue ;
//				vis[v] = true;
//				q.push(v);
//			}
//		}
//	}
//}

void spfa() {
	queue<int> q;
	q.push(1), vis[1] = true, d[1] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		vis[now] = false;
//		printf("%d:%lld\n", now, G[now].size());
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to, td = G[now][i].val;
			if(d[v] > d[now]+td) {
				d[v] = d[now]+td;
				if(vis[v]) continue ;
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d\n", &m) && m!=-1) {
		mp.clear();
		init();
		n = 0;
		char x[32], y[32];
		int val, flag = false;
		scanf("%s %s\n", x, y);
		if(string(x) == string(y)) flag = true;
		mp[x] = ++n, mp[y] = ++n;
		for(int i=0; i<m; i++) {
			scanf("%s %s %d\n", x, y, &val);
			int& rx = mp[x], &ry = mp[y];
			if(!rx) rx = ++n;
			if(!ry) ry = ++n;
			G[rx].push_back(Edge(ry, val));
			G[ry].push_back(Edge(rx, val));
		}
		if(!flag) spfa();
		else { printf("0\n"); continue ;}
//		for(int i=0; i<=n; i++)
//			printf("%d, ", d[i]);
		printf("%d\n", d[2]==INF ? -1 : d[2]);
	}
	return 0;
}
