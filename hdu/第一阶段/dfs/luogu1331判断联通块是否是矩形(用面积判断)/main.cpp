#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 1005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int row, col, mxh, mnh, mxw, mnw, cnt;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
char mtx[MAXN][MAXN];
bool vis[MAXN][MAXN];

void dfs(int r, int c) {
	vis[r][c] = true;
	cnt ++;
	mnh = min(mnh, r), mxh = max(mxh, r);
	mnw = min(mnw, c), mxw = max(mxw, c);
	for(int i=0; i<4; i++) {
		int nr = r+dr[i], nc = c+dc[i];
		if(nr<0 || nc<0 || nr>row || nc>col || vis[nr][nc]) continue;
		if(mtx[nr][nc] == '#') dfs(nr, nc);
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &row, &col);
	for(int i=1; i<=row; i++)
		scanf("%s ", mtx[i]+1);
	int ans = 0;
	for(int i=1; i<=row; i++) {
		for(int k=1; k<=col; k++) {
			if(vis[i][k] || mtx[i][k]=='.') continue ;
			mxh = mxw = -1, mnh = mnw = MAXN, cnt = 0;
			dfs(i, k);
			int w = mxw - mnw + 1, h = mxh - mnh + 1;
			if(cnt == w*h) //计算联通快的面积
				ans ++;
			else {
				printf("Bad placement.\n");
				return 0;
			}
		}
	}
	printf("There are %d ships.\n", ans);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

