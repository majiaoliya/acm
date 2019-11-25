#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define MAXN 25
using namespace std;

char mtx[MAXN][MAXN];
int r, c, cnt;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void dfs(int row, int col) {
	if(row<1 || row>r || col<1 || col>c) return ;
	if(mtx[row][col] != '.') return ;
	mtx[row][col] = '!'; //vis
	cnt ++;
	for(int i=0; i<4; i++) {
		int nrow = row+dr[i], ncol = col+dc[i];
		if(nrow<1 || nrow>r || ncol<1 || ncol>c) continue ;
		if(mtx[nrow][ncol] != '.') continue ;
		dfs(nrow, ncol);
	}
}

int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &c, &r); ) {
		if(r==0 && c==0) break;
		int s_row = 0, s_col = 0;
		cnt = 0;
		for(int i=1; i<=r; i++) {
			scanf("%s", mtx[i]+1);
			for(int k=1; k<=c; k++) 
				if(mtx[i][k] == '@')
					s_row = i, s_col = k, mtx[i][k] = '.';
		}
//		printf("%d %d\n", s_row, s_col);	
		dfs(s_row, s_col);
		printf("%d\n", cnt);
	}
	
	return 0;
}








