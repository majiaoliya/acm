#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAXN 16
using namespace std;

vector<int> G[MAXN];
int n, m;
bool vis[MAXN];

void dfs(int x, vector<int>& trs) {
	if(vis[x]) return ;
	vis[x] = true;
	trs.push_back(x);
	for(int i=0; i<G[x].size(); i++) {
		int chl = G[x][i];
		dfs(chl, trs);
	}
}

void bfs(int root, vector<int>& trs) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if(vis[x]) continue;
		vis[x] = true;
		trs.push_back(x);
		for(int i=0; i<G[x].size(); i++) {
			int chl = G[x][i];
			q.push(chl);
		}
	}
}

int main() { 
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=0; i<n; i++)
		sort(G[i].begin(), G[i].end());
	vector<vector<int>> rs;
	for(int i=0; i<n; i++) {
		if(!vis[i]) {
			vector<int> trs;
			dfs(i, trs);
			rs.push_back(trs);
		}
	}
	memset(vis, false, sizeof(vis));
	for(int i=0; i<n; i++) {
		if(!vis[i]) {
			vector<int> trs;
			bfs(i, trs);
			rs.push_back(trs);
		}
	}
	for(int i=0; i<rs.size(); i++) {
		int c = 0;
		printf("{ ");
		for(int k=0; k<rs[i].size(); k++) {
			if(c++) printf(" ");
			printf("%d", rs[i][k]);
		}
		printf(" }\n");
	}
	return 0;
}


