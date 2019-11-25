#include <iostream>
#include <set>
#include <vector>
#define MAXN 10005
using namespace std;

int n, m, id, rs;
//bool mtx[MAXN][MAXN];
bool vis[MAXN];

vector<int> G[MAXN];

bool find(int id, int chl) {
	bool ret = false;
	for(int i=0; i<G[id].size(); i++)
		if(G[id][i] == chl) {
			ret = true;
			break;
		}
	return ret;
}

void dfs(int x) {
	vis[x] = true;
	for(int i=0; i<G[x].size(); i++) {
		int chl = G[x][i];
		if(vis[chl]) continue ;
//		if(!mtx[id][chl]) rs ++;
		if(!find(id, chl)) rs ++;
		dfs(chl);
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d %d", &n, &id, &m);
	for(int i=1, x, y; i<=m; i++) {
		scanf("%d,%d", &x, &y);
//		mtx[x][y] = mtx[y][x] = true;
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(id);
	printf("%d\n", rs);
	return 0;
}
