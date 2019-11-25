#include <iostream>
#include <limits.h>
#include <vector>
#include <string.h>
//#include <Test.h>
#define MAXN 1024
#define OO 99999999

using namespace std;

int mtx[MAXN][MAXN], t, n, m, s, kk, xi, dist[MAXN];
vector<int> v;

void djk() {
	bool vis[MAXN];
//	memset(vis, false, sizeof(vis));
	for(int i=1; i<=n; i++) {
		vis[i] = false;
		dist[i] = mtx[n][i];
	}
	vis[s] = true;
	for(int i=1; i<=n; i++) {
		int min = OO, min_id = n;
		for(int k=1; k<=n; k++) {
			if(!vis[k] && min>dist[k]) {
				min = dist[k];
				min_id = k;
			}
		}
		vis[min_id] = true;
		for(int k=1; k<=n; k++) {
			int t = dist[min_id] + mtx[min_id][k];
			if(!vis[k] && t<dist[k]) {
				dist[k] = t;
			}
		}
	}
	for(int i=1; i<=n; i++)
		printf("%d %d %d\n", n, i, dist[i]);
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		v.clear();
		memset(mtx, false, sizeof(mtx));
		for(int i=1; i<=n; i++)
			dist[i] = 99999999;
		scanf("%d %d %d %d %d", &n, &m, &s, &kk, &xi);
		for(int i=1, tmp; i<=kk; i++)
			scanf("%d", &tmp), v.push_back(tmp);
		for(int i=1; i<=m; i++) {
			int x, y, val;
			scanf("%d %d %d", &x, &y, &val);
			mtx[x][y] = mtx[y][x] = mtx[x][y]==0 ? val : min(val, mtx[x][y]);
		}
		djk();
	}
	return 0;
}
