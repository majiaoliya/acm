#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define MAXN 105
using namespace std;

int r, c, cnt;
char mtx[MAXN][MAXN];

int dr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dc[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void dfs(int row, int col) {
	if(mtx[row][col] != '@') return ;
	
	mtx[row][col] = 'a' + cnt;
	for(int i=0; i<8; i++) {
		int nrow = row+dr[i], ncol = col+dc[i];
		if(nrow>=1 && nrow<=r && ncol>=1 && ncol<=c) {
			if(mtx[nrow][ncol] != '@') continue ;
			dfs(nrow, ncol);
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &r, &c), (r+c); ) {
		memset(mtx, false, sizeof(mtx));
		cnt = 0;
		for(int i=1; i<=r; i++)
			scanf("%s", mtx[i]+1);
		for(int i=1; i<=r; i++) {
			for(int k=1; k<=c; k++) {
				if(mtx[i][k]=='@') {
					cnt ++;
					dfs(i, k);
				}
			}
		}
//		printf("\n");
//		for(int i=1; i<=r; i++) {
//			printf("%s\n", mtx[i]+1);
//		}
		printf("%d\n", cnt);
	}
	
	return 0;
}








