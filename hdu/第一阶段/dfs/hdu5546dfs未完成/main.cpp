
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 5005
using namespace std;

char mtx[9][10];
bool vis[9][10];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int cnt = 0;

int dfs(int row, int col) {
	vis[row][col] = true;
	for(int i=0; i<4; i++) {
		int nrow = row+dr[i];
		int ncol = col+dc[i];
		if(nrow<0 || nrow>=9 || ncol<0 || ncol>=9) continue;
		if(vis[nrow][ncol]) continue;
		if('o' == mtx[nrow][ncol]) continue;
		if('.' == mtx[nrow][ncol]) {
			vis[nrow][ncol] = true;
			cnt ++;
		}
		dfs(nrow, ncol);
	}
}

int main()
{
	freopen("test", "r", stdin);
	
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		for(int i=0; i<9; i++) {
			scanf("%s", mtx[i]);
			printf("%s\n", mtx[i]);
		}
		printf("\n");
		bool is_find = false;
		for(int i=0; i<9 && !is_find; i++) {
			for(int k=0; k<9 && !is_find; k++) {
				if('o'==mtx[i][k] && !vis[i][k]) {
					dfs(i, k);
					if(cnt == 1) {
						is_find = true;
					}
				}
			}
		}
		printf("%s\n", is_find ? "Yes" : "No");
	}
	
	return 0;
}



