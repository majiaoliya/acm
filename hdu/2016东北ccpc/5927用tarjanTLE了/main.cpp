/**
  用Tarjan求TLE
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
//#include <algorithm>
#define ll long long int
#define MAXN 100005
using namespace std;
int t, n, q, pre[MAXN], m;

bool is[MAXN]; //是否重要
bool rs[MAXN]; //是否是结果
bool vis[MAXN];

struct Node {
	int x, y, lca;
} query[MAXN];

vector<int> G[MAXN];
vector<int> Q[MAXN];
vector<int> lca_idx[MAXN];

void init(int n) {
	for(int i=0; i<n+2; i++) 
		pre[i]=-1, is[i]=true, G[i].clear(), Q[i].clear(), lca_idx[i].clear(), rs[i]=true, vis[i]=false;
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	return ret;
}


void dfs(int u) {
	vis[u] = true;
	for(int i=0; i<Q[u].size(); i++) {
		int idx = Q[u][i], v;
		if(u == query[idx].x) v = query[idx].y;
		else if(u == query[idx].y) v = query[idx].x;
		if(vis[v]) { 
			query[idx].lca = fa(v);
			lca_idx[query[idx].lca].push_back(idx);
		}
	}
	for(int i=0; i<G[u].size(); i++) {
		int chl = G[u][i];
		if(vis[chl]) continue;
		dfs(chl);
		pre[chl] = u;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	for(int ii=1; ii<=t; ii++) {
		printf("Case #%d:\n", ii);
		scanf("%d %d", &n, &q);
		init(n);
		for(int i=1, x, y; i<n; i++) {
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		for(int i=1, cnt=1; i<=n; i++) {
			for(int k=i+1; k<=n; k++) {
				query[cnt].x = i, query[cnt].y = k;
				Q[query[cnt].x].push_back(cnt);
				Q[query[cnt].y].push_back(cnt);
				cnt ++;
			}
		}
		dfs(1);
		for(int i=1; i<=q; i++) {
			scanf("%d", &m);
			vector<int> not_ipt;
			for(int k=1; k<=n; k++)
				rs[k] = true;
			int ans = n;
			for(int k=1, x; k<=m; k++) {
				scanf("%d", &x);
				not_ipt.push_back(x);
				rs[x] = is[x] = false;
				ans --;
			}
			for(int k=0; k<not_ipt.size(); k++) {
				for(int j=0; j<lca_idx[not_ipt[k]].size(); j++) {
					int idx = lca_idx[not_ipt[k]][j];
					if(idx == -1) continue;
					int chl1 = query[idx].x, chl2 = query[idx].y;
					
					if(is[chl1] && is[chl1]) {
						if(!rs[query[idx].lca]) ans ++;
						rs[query[idx].lca] = true;
					}
				}
			}
			printf("%d\n", ans);
//			printf("set:");
//			for(int i=1; i<=n; i++)
//				if(rs[i]) printf("%d  ", i);
//			printf("\n");
		}
		
	}
	return 0;
}
