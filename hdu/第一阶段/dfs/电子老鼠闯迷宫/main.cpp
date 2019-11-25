#include <iostream>
using namespace std;
 
int n;
int s_row, s_col, e_row, e_col;

char mtx[15][15];
bool vis[15][15];	
int min_step = 13*13;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void dfs(int row, int col, int step) {
	if(row<1 || row>12 || col<1 || col>12) return; //越界返回
	if(row==e_row && col==e_col) {
		cout << "find path:" << step << endl;
		if(step < min_step) min_step = step; //更新
		for(int i=1; i<=12; i++)
			cout << mtx[i]+1 << endl;
		cout << endl;
		return ;
	}
	if(mtx[row][col] == 'X' || vis[row][col]) return ; //到墙壁
	vis[row][col] = true, mtx[row][col] = '*';
	for(int i=0; i<4; i++) dfs(row+dr[i], col+dc[i], step+1);
	vis[row][col] = false, mtx[row][col] = '.';
} 

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d %d %d", &s_row, &s_col, &e_row, &e_col);
	cin.ignore();
	for(int i=1; i<=12; i++) {
		cin.getline(mtx[i]+1, 15);
	}
	cout << endl;
	dfs(s_row, s_col, 0);
	
	return 0;
}
