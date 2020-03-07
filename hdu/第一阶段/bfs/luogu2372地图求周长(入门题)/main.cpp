#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define MAXN (32)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给定一个地图和起点, 可以向8个方向走,求联通快的周长
 * 周长只能取4个方向的
 */

int n, m, x, y;
char mtx[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ans[MAXN][MAXN];

int dr[] = { 1, -1, 0, 0, 1, -1, 1, -1};
int dc[] = { 0, 0, 1, -1, 1, -1, -1, 1};

struct Node {
	int r, c;
} ;

void bfs() {
	queue<Node> q;
	q.push({x, y});
	vis[x][y] = true;
	while(!q.empty()) {
		Node& now = q.front();
		for(int i=0; i<8; i++) {
			int nr = now.r+dr[i], nc = now.c+dc[i];
			if(i<4 && mtx[nr][nc] != 'X') ans[nr][nc] ++;
			if(mtx[nr][nc] == 'X' && !vis[nr][nc]) {
				q.push({nr, nc});
				vis[nr][nc] = true;
			}
		}
		q.pop();
	}
	
	int sum = 0;
	for(int i=0; i<=n+1; i++) 
		for(int k=0; k<=m+1; k++) sum += ans[i][k];
#ifdef debug
	for(int i=0; i<=n+1; i++) 
		forarr(ans[i], 0, m+1);
#endif
	printf("%d\n", sum);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d %d ", &n, &m, &x, &y);
	for(int i=1; i<=n; i++) scanf("%s ", mtx[i]+1);
	bfs();







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


