//#include <iostream>
//#include <algorithm>
//#include <math.h>
//#include <string.h>
//#include <vector>
//#define MAXN 205
//using namespace std;

//struct XY {
//	int row, col;
//};

//char mtx[MAXN][MAXN];
//bool vis[MAXN][MAXN];
//int r, c, min_value = 999999999;
//vector<XY> sv;

//int dr[] = {1, -1, 0, 0};
//int dc[] = {0, 0, 1, -1};

//void dfs(int row, int col, int count) {
//	if(row<1 || row>r || col<1 || col>c) return ;
//	if(mtx[row][col] == '#') return ;
//	if(vis[row][col]) return ;
//	if(count >= min_value) return ; //减掉比当前长的路
//	if(mtx[row][col] == 'x') {
//		count ++;
//	} else if(mtx[row][col] == 'a') {
//		if(min_value > count)
//			min_value = count; 
//		return ;
//	}
//	
//	vis[row][col] = true;
//	for(int i=0; i<4; i++) {
//		int nrow = row+dr[i], ncol = col+dc[i];
//		if(nrow<1 || nrow>r || ncol<1 || ncol>c) continue ;
//		if(vis[nrow][ncol]) continue ;
//		if(mtx[nrow][ncol] == '#') continue ;
//		dfs(nrow, ncol, count+1);
//	}
//	vis[row][col] = false;
//}

//int main()
//{
//	freopen("test", "r", stdin);
//	for( ; EOF != scanf("%d %d", &r, &c); ) {
//		sv.clear();
//		min_value = 999999999;
//		for(int i=1; i<=r; i++) {
//			scanf("%s", mtx[i]+1);
//			for(int k=1; k<=c; k++) {
//				if(mtx[i][k] == 'r') {
//					XY xy;
//					xy.row = i, xy.col = k;
//					sv.push_back(xy);
//				} 
//			}
//		}
//		for(int i=0; i<sv.size(); i++) {
//			memset(vis, false, sizeof(vis));
//			dfs(sv[i].row, sv[i].col, 0);
//		}
//		printf("%d\n", min_value);
//	}
//	
//	return 0;
//}






//改成从a点开始搜索
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#define MAXN 205
using namespace std;

char mtx[MAXN][MAXN];
bool vis[MAXN][MAXN];
int r, c, min_value = 999999999, s_row, s_col;

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void dfs(int row, int col, int count) {
	if(row<1 || row>r || col<1 || col>c) return ;
	if(count > min_value) return ;
	if(vis[row][col]) return ;
	if(mtx[row][col] == '#') return ;
	if(mtx[row][col] == 'r') {
		if(count < min_value) {
			min_value = count; 
//			printf("%d %d\n", row, col);
		}
		return ;
	} else if(mtx[row][col] == 'x') {
		count ++;
	}
	
	vis[row][col] = true;
	for(int i=0; i<4; i++) {
		int nrow = row+dr[i], ncol = col+dc[i];
		//这一段会报错 ??? why -_-
//		if(nrow<1 || nrow>r || ncol<1 || nrow>c) continue ; 
//		if(vis[nrow][ncol]) continue ;
//		if(mtx[nrow][ncol] == '#') continue ;
		dfs(nrow, ncol, count+1);
	}
	vis[row][col] = false;
}

int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &r, &c); ) {
		min_value = 999999999;
		memset(vis, false, sizeof(vis));
		
		for(int i=1; i<=r; i++) {
			scanf("%s", mtx[i]+1);
			for(int k=1; k<=c; k++) 
				if(mtx[i][k] == 'a') s_row = i, s_col = k;
		}
		dfs(s_row, s_col, 0);
		if(min_value == 999999999) 
			printf("Poor ANGEL has to stay in the prison all his life.\n"); 
		else
			printf("%d\n", min_value);
	}
	
	return 0;
}

