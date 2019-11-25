//#include <iostream>
//#include <string.h>
//#include <queue>
//
//using namespace std;
//const int maxn = 220;
//const int inf = 0x7f7f7f7f;
//
//int G[maxn][maxn]; 
//int flow[maxn]; //源点到汇点的流量
//int pre[maxn]; //上一步的增广路是那一条链
//int n, m;
//
//queue<int> q;
//
//int bfs(int s, int t) {
//	while(!q.empty()) q.pop();
//	memset(pre, -1, sizeof(pre));
//	pre[s] = 0, flow[s] = inf;
//	q.push(s);
//	while(!q.empty()) {
//		int p = q.front(); q.pop();
//		if(p == t) { break; }
//		for(int u=1; u<=n; u++) {
//			if(u!=s && G[p][u]>0 && pre[u]==-1) {
//				pre[u] = p;
//				flow[u] = min(flow[p], G[p][u]);
//				q.push(u);
//			}
//		}
//	}
//	if(pre[t] == -1) return -1;
//	return flow[t];
//}
//
//int EK(int s, int t) { 
//	int delta = 0; //当前残余网络被更新了多少
//	int tot = 0; //总的最大流是多少
//	while(1) {
//		delta = bfs(s, t);
//		if(delta == -1) break; //找不到曾广路就退出
//		int p = t;
//		while(p != s) {
//			G[pre[p]][p] -= delta;
//			G[p][pre[p]] += delta;
//			p = pre[p];
//		}
//		tot += delta;
//	}
//	return tot;
//}
//
//int main(void) {
//	freopen("test", "r", stdin);
//	while(~scanf("%d %d", &m, &n)) {
//		memset(G, false, sizeof(G));
//		memset(flow, false, sizeof(flow));
//		int u, v, w;
//		for(int i=0; i<m; i++) {
//			scanf("%d %d %d", &u, &v, &w);
//			G[u][v] += w;
//		}
//		printf("%d\n", EK(1, n));
//	}
//	return 0;
//}


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int maxn = 220;
const int inf = 1<<30;
int G[maxn][maxn], flow[maxn], pre[maxn];
int n, m;
queue<int> q;

int bfs(int s, int t) {
	q = queue<int>();
	memset(pre, -1, sizeof(pre));
	pre[s] = 0, flow[s] = inf;
	q.push(s);
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		if(p == t) break;
		for(int u=1; u<=n; u++) {
			if(u!=s && G[p][u]>0 && pre[u]==-1) {
				pre[u] = p;
				flow[u] = min(flow[p], G[p][u]);
				q.push(u);
			}
		}
	}
	if(pre[t] == -1) return -1;
	return flow[t];
}

int EK(int s, int t) {
	int delta = 0, tot = 0;
	while(1) {
		delta = bfs(s, t);
		if(delta == -1) break;
		int p = t;
		while(p != s) {
			G[pre[p]][p] -= delta; //他用矩阵的(上或下)三角存正向边
			G[p][pre[p]] += delta; //用矩阵的(上或下)三角存反向边
			p = pre[p];
		}
		tot += delta;
	}
	return tot;
}

int main(void) {
	freopen("test", "r", stdin);
	
	while(~scanf("%d %d", &m, &n)) {
		memset(flow, false, sizeof(flow));
		memset(G, false, sizeof(G));
		for(int i=0, u, v, w; i<m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			G[u][v] += w;
		}
		printf("%d\n", EK(1, n));
	}
	
	
	return 0;
}
