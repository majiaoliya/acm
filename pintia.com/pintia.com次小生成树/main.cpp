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
#include <unordered_set>
#define ll long long int

using namespace std;
/**
 * pta最小生成树的唯一性
 * 给定一张图(不一定联通),如果只有一个最小生成树打印yes, 有多个最小生成树打印no
 * 思路: 求次小生成树,次小不等于最小就只有一颗最小生成树
 * 求次小树的方法:
 * 	>先求最小生成树
 * 	>从非树边里拿一条边(u,v)拼到树上,于是一定形成了环,
 * 	>从环中选择一条最长的树边删去,就是次小生成树
 */
int n, m, mtx[MAXN][MAXN]/*邻接矩阵存长度*/, vis[MAXN]/*vis搜索环上的树边要用*/;
struct Edge {
	int u, v, vis;
	bool operator < (const Edge& y) const { return mtx[u][v] < mtx[y.u][y.v]; }
} edge[MAXN*MAXN];

vector<int> G[MAXN];

int pre[MAXN];
inline void init() {
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1) ret = pre[ret];
	if(x != ret) pre[x] = ret;
	return ret;
}

bool union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry) {
		pre[ry] = rx;
		return true;
	}
	return false;
}

int tmax;
void dfs(vector<int>& tmp, int now, int U, int V) {
	if(now == V) {
		tmax = -1;
		for(int i=0; i<(int)tmp.size(); i++) tmax = max(tmax, tmp[i]);
		return ;
	}
	for(int i=0; i<(int)G[now].size(); i++) {
		int chl = G[now][i];
		if(vis[chl]) continue ;
		vis[chl] = true;
		tmp.push_back(mtx[now][chl]);
		dfs(tmp, chl, U, V);
		tmp.pop_back();
		vis[chl] = false;
	}
}

int ans = -1, mst, k;
void krs() {
	mst = 0, k = n-1;
	init();
	sort(edge+1, edge+1+m);
	for(int i=1; i<=m; i++) {
		if(!k) { //生成了最小生成树
			vector<int> tmp;
			dfs(tmp, edge[i].u, edge[i].u, edge[i].v); //dfs出(u,v)环里的最长树边
			for(int i=1; i<=m; i++) {
				if(!edge[i].vis) {
					//次小树=最小树 + 新边 - 环(u,v)的最长树边
					ans = mst + mtx[edge[i].u][edge[i].v] - tmax;
					break;
				}
			}
			break;
		} else {
			bool ok = union_xy(edge[i].u, edge[i].v);
			if(!ok) continue ;
//			printf("union_xy(%d %d)\n", edge[i].u, edge[i].v);
			mst += mtx[edge[i].u][edge[i].v];
			k --;
			edge[i].vis = true;
			G[edge[i].u].push_back(edge[i].v); //生成最小生成树的过程中建图
			G[edge[i].v].push_back(edge[i].u);
		}
	}
}
#define QAQ (0)
int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	scanf("%d %d ", &n, &m);
	memset(pre, -1, sizeof(pre));
	for(int i=1; i<=m; i++) {
		int u, v, w;
		scanf("%d %d %d ", &u, &v, &w);
		mtx[u][v] = mtx[v][u] = w;
		edge[i].u = u, edge[i].v = v;
		union_xy(u, v);
	}
	int cnt = 0;
	for(int i=1; i<=n; i++)
		if(-1 == pre[i]) cnt ++;
	if(cnt > 1) {
		printf("No MST\n%d", cnt);
		return QAQ;
	}
	krs();
	printf("%d\n%s", mst, ans!=mst ? "Yes" : "No");





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return QAQ;
}

