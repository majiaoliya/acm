#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 32
using namespace std;

int n, dr[] = {1, -1, 0, 0}, dc[] = { 0, 0, 1, -1 };
int mtx[MAXN][MAXN], vis[MAXN][MAXN];

void dfs(int r, int c) {
	if(vis[r][c] || mtx[r][c]==1) return ;
	vis[r][c] = true;
//	mtx[r][c] = 1;
	for(int i=0; i<4; i++) {
		int nr = dr[i]+r, nc = dc[i]+c;
		if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc])
			dfs(nr, nc);
	}
}

int main() {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int k=0; k<n; k++)
			scanf("%d", &mtx[i][k]);
	int tmp = 0, drr[] = { 0, 1, 0, -1 }, dcc[] = { 1, 0, -1, 0 }, r = 0, c = 0;
	for(int i=0; i<(n-1)*4; i++) {
//		printf("[%d, %d]\n", r, c);
		if(!vis[r][c] && mtx[r][c]!=1)
			dfs(r, c);
		int nr = r+drr[tmp], nc = c+dcc[tmp];
		if(nr==n || nr<0 || nc==n || nc<0) tmp = (++tmp) % 4;
		r = r+drr[tmp], c = c+dcc[tmp];
	}
	for(int i=0; i<n; i++)
		for(int k=0; k<n; k++)
			if(!vis[i][k] && mtx[i][k]!=1)
				printf("%d%c", 2, k==n-1 ? '\n':' ');
			else
				printf("%d%c", mtx[i][k], k==n-1 ? '\n':' ');
	return 0;
}
