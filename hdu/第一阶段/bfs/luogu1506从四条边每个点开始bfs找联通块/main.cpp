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
#include <queue>
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, m;
char mtx[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Node {
	int x, y;
} ;
queue<Node> q;

void bfs() {
	int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		if(vis[now.x][now.y]) continue ;
		vis[now.x][now.y] = true;
		for(int i=0; i<4; i++) {
			int nr = now.x+dr[i], nc = now.y+dc[i];
			if(nr>=1 && nr<=n && nc>=1 && nc<=m && !vis[nr][nc] && mtx[nr][nc]=='0')
				q.push({nr, nc});
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m)) {
		memset(vis, false, sizeof(vis));
		for(int i=1; i<=n; i++) scanf("%s\n", mtx[i]+1);
		int r=1, c=1, tdr[]={0,1,0,-1}, tdc[]={1,0,-1,0};
		for(int i=1,k=0; i<=(n<<1)+(m<<1)-4; i++) {
			if(mtx[r][c] == '0') q.push({r, c});
			int nr = r+tdr[k], nc = c+tdc[k];
			if(nr>n || nr<1 || nc>m || nc<1 || vis[nr][nc]) k = (k+1)%4;
			r += tdr[k], c = c+tdc[k];
		}
		//for( ; !q.empty(); q.pop()) 
		//	printf("%d %d\n", q.front().x, q.front().y);
		bfs();
		int ans = 0;
		for(int i=1; i<=n; i++) 
			for(int k=1; k<=m; k++) 
				if(!vis[i][k] && mtx[i][k]=='0') ans ++;
		printf("%d\n", ans);
#ifdef debug
		for(int i=1; i<=n; i++) {
			for(int k=1; k<=m; k++) {
				if(vis[i][k]) printf("-");
				else printf("%c", mtx[i][k]);
			}
			printf("\n");
		}
#endif
	}





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

