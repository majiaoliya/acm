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
#include <queue>
#define MAXN ((int)32+7)
#define ll long long int
#define ld long double
#define QAQ (0)

using namespace std;
// pat白骑士的移动 (30分) 第二场现场赛

int n = 8;
char mtx[MAXN][MAXN];

struct Node {
	int r, c, step;
	Node(int _r, int _c, int _s) : r(_r), c(_c), step(_s) { }
} ;

queue<Node> q;

void check(int r, int c) {
	if(mtx[r][c] == 'R') {
		for(int i=r-1; i>0 && mtx[i][c]=='.'; i--) mtx[i][c] = 'X'; 
		for(int i=r+1; i<=n && mtx[i][c]=='.'; i++) mtx[i][c] = 'X';
		for(int i=c-1; i>0 && mtx[r][i]=='.'; i--) mtx[i][c] = 'X'; 
		for(int i=c+1; i<=n && mtx[r][i]=='.'; i++) mtx[i][c] = 'X';
	} else if(mtx[r][c] == 'B') {
		//处理对角线
		for(int i=r-1, k=c-1; i>0 && k>0 && mtx[i][k]=='.'; i--, k--) 
			mtx[i][k] = 'X';
		for(int i=r+1, k=c-1; i<=n && k>0 && mtx[i][k]=='.'; i++, k--) 
			mtx[i][k] = 'X';
		for(int i=r+1, k=c+1; i<=n && k<=n && mtx[i][k]=='.'; i++, k++) 
			mtx[i][k] = 'X';
		for(int i=r-1, k=c+1; i>0 && k<=n && mtx[i][k]=='.'; i--, k++) 
			mtx[i][k] = 'X';
	}
}

int dr[] = { 1, 2, -1, -2, -1, -2, 1, 2 };
int dc[] = { 2, 1, -2, -1, 2, 1, -2, -1 };

int bfs() {
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		int r = now.r, c = now.c;
		if(mtx[r][c] == 'K') return now.step;
		mtx[r][c] = '*';
		for(int i=0; i<8; i++) {
			int nr = r+dr[i], nc = c+dc[i];
			if(nr>=1 && nc>=1 && nr<=n && nc<=n) {
				if(mtx[nr][nc]=='.')
					q.push(Node(nr, nc, now.step+1));
				else if(mtx[nr][nc]=='K') return now.step + 1;
			}
		}
	}
	return -1;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	for(int i=1; i<=n; i++) {
		scanf("%s ", mtx[i]+1);
		for(int k=1; k<=n; k++) //从皇后开始日字型跳到最近的马上
			if(mtx[i][k] == 'Q') q.push(Node(i, k, 0));
	}
	for(int i=1; i<=n; i++) //先过滤掉所有有可能被吃掉的位置
		for(int k=1; k<=n; k++)
			check(i, k);
	int ans = bfs();
	if(-1 == ans) printf("Checkmate\n");
	else printf("%d\n", ans);
#ifdef debug
	for(int i=1; i<=n; i++) printf("%s\n", mtx[i]+1);
#endif




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


