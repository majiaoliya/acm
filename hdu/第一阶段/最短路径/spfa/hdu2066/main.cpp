//#include <iostream>
//#include <queue>
//#include <vector>
//#define MAXN 1005
//#define OO 0x3f3f3f3f
//using namespace std;

//int n, m, T, S, D;
//
//struct Edge {
//	int to, val;
//	Edge() : to(0), val(0) { }
//	Edge(int _to, int _val) : to(_to), val(_val) { }
//} ;
//
//vector<Edge> G[MAXN];
//vector<int> query;
//
//int inq[MAXN], d[MAXN];
//
//inline void init() {
//	n = MAXN;
//	for(int i=0; i<=n+1; i++)
//		G[i].clear(), inq[i] = false, d[i] = OO;
//}
//
//void spfa() {
//	queue<int> q;
//	q.push(0), d[0] = 0, inq[0] = true;
//	while(!q.empty()) {
//		int now = q.front();
//		q.pop();
//		inq[now] = false;
//		for(int i=0; i<(int)G[now].size(); i++) {
//			int v = G[now][i].to;
//			if(d[v] > d[now]+G[now][i].val) {
//				d[v] = d[now]+G[now][i].val;
//				if(inq[v]) continue ;
//				inq[v] = true;
//				q.push(v);
//			}
//		}
//	}
//}
//
//int main(void) {
//	freopen("test", "r", stdin);
//	while(~scanf("%d %d %d", &T, &S, &D)) {
//		init();
//		for(int i=1; i<=T; i++) {
//			int x, y, val;
//			scanf("%d %d %d", &x, &y, &val);
//			G[x].push_back(Edge(y, val));
//			G[y].push_back(Edge(x, val));
//		}
//		for(int i=0, to; i<S; i++) {
//			scanf("%d", &to);
//			G[0].push_back(Edge(to, 0));
//			G[to].push_back(Edge(0, 0));
//		}
//		spfa();
//		int ret = OO;
//		for(int i=0, to; i<D; i++) {
//			scanf("%d", &to);
//			ret = min(ret, d[to]);
//		}
//		for(int i=0; i<100; i++)
//			printf("%d ", d[i]);
//		printf("%d\n", ret);
//	}
//	return 0;
//}












#include <iostream>
#include <queue>
using namespace std;
const int maxn = 10000;
const int MAXN = 0xffffff;

int n, T, S, D, d[maxn], vis[maxn];

struct Edge {
	int to, val;
	Edge() : to(-1), val(MAXN) { }
	Edge(int _to, int _val) : to(_to), val(_val) { }
} ;

vector<Edge> G[maxn];

void init() {
	for(int i=0; i<=n+1; i++)
		G[i].clear(), d[i] = MAXN, vis[i] = false;
}

void spfa() {
	queue<int> q;
	q.push(0), vis[0] = true, d[0] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		vis[now] = false;
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
	n = 1024;
	while(~scanf("%d %d %d", &T, &S, &D)) {
		init();
		for(int i=0, a, b, t; i<T; i++) {
			scanf("%d %d %d", &a, &b, &t);
			G[a].push_back(Edge(b, t));
			G[b].push_back(Edge(a, t));
		}
		for(int i=0, x; i<S; i++) {
			scanf("%d", &x);
			G[0].push_back(Edge(x, 0));
			G[x].push_back(Edge(0, 0));
		}
		spfa();
		int minv = MAXN;
		for(int i=0, x; i<D; i++) {
			scanf("%d", &x);
			minv = min(d[x], minv);
		}
		printf("%d\n", minv);
	}
	return 0;
}
