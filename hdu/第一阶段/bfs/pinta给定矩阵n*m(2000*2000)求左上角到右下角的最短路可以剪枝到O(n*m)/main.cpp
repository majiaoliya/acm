#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 2048
#include <map>
#include <queue>
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给定一个n*m(最大2000*2000)的二维矩阵,问左上角到右下角的最小步数
 * bfs+剪枝
 * 给矩阵每个点mtx[i][j]设置权值w[i][j]如果当前步数大于w[i][j]就减掉不要
 * 这样剪枝可以到O(n*m)
 */

bool vis[MAXN][MAXN];
char mtx[MAXN][MAXN];
int n, m;
int w[MAXN][MAXN]; //第mtx[i][j]的最小步数
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

struct Node {
	int r, c, step;
	Node(int _r, int _c, int _step) : r(_r), c(_c), step(_step) { }
	//bool operator < (const Node& node) const {
	//	return w[r][c] < w[node.r][node.c];
	//}
} ;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++)
		scanf("%s ", mtx[i]+1);
	memset(w, 0x3f3f3f3f, sizeof(w));
	w[1][1] = 0;
//	priority_queue<Node> q;
	queue<Node> q;
	q.push(Node(1, 1, 0));
	int ans = -1;
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		int r = now.r, c = now.c;
//		printf("%d %d step:%d\n", r, c, now.step);
		vis[r][c] = false;
		if(r == n && c == m) {
			ans = now.step;
			break;
		}
		for(int i=0; i<4; i++) {
			int nr = r+dr[i], nc = c+dc[i], nstep = now.step+1;
			if(nr>0 && nc>0 && nr<=n && nc<=m && !vis[nr][nc]) {
				if(mtx[nr][nc] == '*') continue ;
				//如果当前步数大于到mtx[nr][nc]的最小步数就剪枝
				if(nstep < w[nr][nc]) { 
					w[nr][nc] = nstep;
					q.push(Node(nr, nc, nstep));
				}
			}
		}
	}
	printf("%d\n", ans);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


