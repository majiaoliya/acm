#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

#define INF (2147483647-1)
#define ll long long
#define MAXN 128
struct Node {
	double x, y;
} arr[MAXN];

struct Edge {
	int to;
	double val;
	Edge() : to(-1), val(INF) { }
	Edge(int _to, double _val) : to(_to), val(_val) { }
} ;

int n, m, vis[MAXN], st, ed; //st起点 ed终点
double d[MAXN];
vector<Edge> G[MAXN];

void init() {
	for(int i=0; i<MAXN; i++)
		G[i].clear(), d[i] = INF*1., vis[i] = false;
}

double dist(int a, int b) {
	double x1=arr[a].x, x2=arr[b].x, y1=arr[a].y, y2=arr[b].y;
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void spfa() {
	queue<int> q;
	q.push(st), vis[st] = true, d[st] = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		vis[now] = false;
		for(int i=0; i<(int)G[now].size(); i++) {
			int v = G[now][i].to;
			if(d[v] > d[now]+G[now][i].val) {
				d[v] = d[now] + G[now][i].val;
				if(vis[v]) continue ;
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	init();
	for(int i=1; i<=n; i++)
		scanf("%lf %lf\n", &arr[i].x, &arr[i].y);
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
//		printf("a:%d b:%d dist:%lf\n", a, b, dist(a, b));
		G[a].push_back(Edge(b, dist(a, b)));
		G[b].push_back(Edge(a, dist(a, b)));
	}
	scanf("%d %d", &st, &ed);
	spfa();
	printf("%.2f\n", d[ed]);
	//for(int i=0; i<=n; i++)
	//	printf("%.3lf, ", d[i]);
	return 0;
}
