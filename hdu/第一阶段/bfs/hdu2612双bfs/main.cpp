#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#include <vector>
#define MAXN 205
#define Z(x) ( x==1 ? 0 : 1)

using namespace std;

int n, m;

char mtx[MAXN][MAXN];
bool vis[MAXN][MAXN];
int sum[MAXN][MAXN];
int cnt[MAXN][MAXN];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

struct Node {
	int x, y, step;
};

bool check(int x, int y) {
	char c = mtx[x][y];
	if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && c!='Y' && c!='M' && c!='#')
	   	return true;
	return false;
}

void bfs(int sx, int sy) {
	Node x, nx;
	x.x = sx, x.y = sy, x.step = 0;
	queue<Node> q;
	q.push(x);
	memset(vis, false, sizeof(vis));
	while(!q.empty()) {
		x = q.front();
		q.pop();
		if(vis[x.x][x.y]) continue ;
		vis[x.x][x.y] = true;
		if(mtx[x.x][x.y] == '@') {
			sum[x.x][x.y] += x.step;
			cnt[x.x][x.y] ++;
#ifdef DEBUG
			printf("(%d,%d) += %d == %d\n", x.x, x.y, x.step, sum[x.x][x.y]);
#endif
		}	
		nx.step = x.step + 1;
		for(int i=0; i<4; i++) {
			nx.x = x.x+dx[i], nx.y = x.y+dy[i];
			if(!check(nx.x, nx.y)) continue ;
			q.push(nx);
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	while(EOF!=scanf("%d %d", &n, &m)) {
		for(int i=0; i<n; i++)
			scanf("%s", mtx[i]);
		int Yx, Yy, Mx, My;
		memset(cnt, false, sizeof(cnt));
		for(int i=0; i<n; i++)
			for(int k=0; k<m; k++) {
				sum[i][k] = 0;
				if(mtx[i][k] == 'Y') Yx = i, Yy = k;
				if(mtx[i][k] == 'M') Mx = i, My = k;
			}
		bfs(Yx, Yy);
		bfs(Mx, My);
		int rs = 999999999;
		for(int i=0; i<n; i++)
			for(int k=0; k<m; k++)
				if(cnt[i][k] == 2)
					rs = min(sum[i][k], rs);
		printf("%d\n", rs==0x3f3f3f3f ? rs : rs*11);
#ifdef DEBUG
		for(int i=0; i<n; i++) {
			for(int k=0; k<m; k++) {
				printf("%d ", sum[i][k]);
			}
			printf("\n");
		}
#endif
	}
	return 0;
}

