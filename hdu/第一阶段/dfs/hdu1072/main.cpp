#include <iostream>
#define MAX 10
#define MAX_TIME 6
using namespace std;
int n, m, t, rs_cnt, start_row, start_col;
bool is_find = false;

int mtx[MAX][MAX];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void dfs(int row, int col, int t, int cnt) {
	if(row<0 || row>=n || col<0 || col>=m || is_find) return; //越界
	if(t<0) return; //超时
	if(mtx[row][col] == 3 && t>=0) {
		is_find = true;
		printf("%d\n", cnt);
		return ;
	} else if(mtx[row][col] == 4) {
		mtx[row][col] = 1;
		t = MAX_TIME;
	}
	for(int i=0; i<4; i++) {
		dfs(row+dr[i], col+dc[i], t-1, cnt+1);
	}
}

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);

	for( ; t--; ) {
		t = MAX_TIME, is_find = false;
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++)
			for(int k=0; k<m; k++) {
				scanf("%d", mtx[i]+k);
				if(mtx[i][k] == 2) 
					start_row = i, start_col = k;
			}
		dfs(start_row, start_col, t, 0);
	}
	
	return 0;
}
