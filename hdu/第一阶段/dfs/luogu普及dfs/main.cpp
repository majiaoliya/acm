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
#define MAXN (128)
#define ll long long int
#define QAQ (0)

using namespace std;

//这个dfs不能拐弯,方向始终唯一

int n;
int dr[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dc[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dir[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
char mtx[MAXN][MAXN];
bool vis[MAXN][MAXN];
string str = "yizhong";

vector<pair<int,int> > vec;

void dfs(int r, int c, int pos, int dir) {
	if(pos == 7) {
		for(auto x : vec) 
			vis[x.first][x.second] = true;
		vis[r][c] = true;
		return;
	}
	int nr = r + dr[dir], nc = c + dc[dir];
	if(nr<0 || nr>=n || nc<0 || nc>=n) return ;
	if(mtx[nr][nc] != str[pos]) return ;
	vec.push_back({r, c});
	dfs(nr, nc, pos+1, dir);
	vec.pop_back();

	//for(int i=0; i<8; i++) {
	//	int nr = r + dr[i], nc = c + dc[i];
	//	if(i != dir) continue ;
	//	if(nr<0 || nr>=n || nc<0 || nc>=n) continue ;
	//	dfs(nr, nc, pos+1, i);
	//}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=0; i<n; i++) scanf("%s ", mtx[i]);
	for(int i=0; i<n; i++)
		for(int k=0; k<n; k++) {
			if(mtx[i][k] != 'y') continue ;
			for(int d=0; d<8; d++)
				dfs(i, k, 1, d);
		}
	for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++) {
			if(vis[i][k]) printf("%c", mtx[i][k]);
			else printf("*");
		}
		printf("\n");
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

