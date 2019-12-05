#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 64
#define QAQ (0)
#define T_T (0)
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;
/**
 * 给定一个字符串矩阵mtx[][]和一个字符串str,可以向上下左右对角8个方向走,问是否有一条路恰好是给定字符串str
 * 直接dfs就行了
 */

char str[] = "DSWYBS";
char mtx[MAXN][MAXN];
bool vis[MAXN][MAXN];

int n, m, ok, er, ec, len = strlen(str);
int dr[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dc[] = {0, 0, 1, -1, 1, -1, -1, 1};
vector<pair<int,int> > ans;

void dfs(int r, int c, int k) {
	if(ok) return ;
	if(k == len) {
		ok = true;
		er = ans.back().first, ec = ans.back().second;
//		printf("%d %d %c\n", r, c, mtx[r][c]);
		return ;
	}
	if(mtx[r][c] != 'S') vis[r][c] = true;
	if(mtx[r][c] != str[k]) return ;
	for(int i=0; i<8; i++) {
		int nr = r+dr[i], nc = c+dc[i];
		if(nr<0 || nc<0 || nr>=n || nc>=m || vis[nr][nc]) continue ;
		ans.push_back({r, c});
		dfs(nr, nc, k+1);
		ans.pop_back();
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=0; i<n; i++) 
		scanf("%s ", mtx[i]);
	for(int i=0; i<n; i++) {
		for(int k=0; k<m; k++) {
			if(mtx[i][k] != 'D') continue ;
			dfs(i, k, 0);
			if(ok) {
				int sum = i + k + er + ec;
				printf("%d %d\n%d %d\n%d", i, k, er, ec, sum);
				return QAQ;
			}
		}
	}
	printf("DSWYBS\n");







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return T_T;
}

