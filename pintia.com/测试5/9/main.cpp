#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#define MAXN 100
using namespace std;

int n, m;

set<int> G[MAXN];

bool vis[MAXN];

vector<int> rs[MAXN];

void dfs(int x, int i) {
	if(vis[x]) return;
	vis[x] = true;
	rs[i].push_back(x);
	set<int>::iterator it = G[x].begin();
	while(it != G[x].end()) {
		int chl = *it;
		it ++;
		if(vis[chl]) continue;
		dfs(chl, i);
	}
}

void bfs(int r, int idx) {
	queue<int> q;
	q.push(r);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = true;
		rs[idx].push_back(x);
		set<int>::iterator it = G[x].begin();
		while(it != G[x].end()) {
			int chl = *it;
			it ++;
			if(vis[chl]) continue;
			q.push(chl);
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].insert(y);
		G[y].insert(x);
	}
	
	int idx = 0;
	for(int i=0; i<n; i++) {
		if(!vis[i]) {
			dfs(i, idx);
			idx ++;
		}
	}
	
	memset(vis, false, sizeof(vis));
	for(int i=0; i<n; i++) {
		if(!vis[i]) {
			bfs(i, idx);
			idx ++;
		}
	}
	
	for(int i=0; i<idx; i++) {
		printf("{");
		for(int k=0; k<rs[i].size(); k++) {
			printf(" %d", rs[i][k]);
		}
		printf(" }\n");
	}
	
	return 0;
}

