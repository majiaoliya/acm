//#include <iostream>
//#include <algorithm>
//#include <string.h>
//#define MAXN 1005
//using namespace std;

//int r, c, is_find;
//int x1, y1, x2, y2;

//int mtx[MAXN][MAXN];

//int dx[] = {1, -1, 0, 0};
//int dy[] = {0, 0, 1, -1};
//bool vis[MAXN][MAXN];

//void dfs(int x, int y) {
//	if(is_find) return ;
//	if(x<1 || x>r || y<1 || y>c) return ;
//	if(vis[x][y]) return ;
//	if(x!=x1 || y!=y1) 
//		if(mtx[x][y] != 0) return;
//	if(x==x2 && y==y2) { //到终点
//		is_find = true;
//		return ;
//	}
//	for(int i=0; i<4; i++) {
//		if(!vis[x][y]) {
//			int nx = x+dx[i], ny = y+dy[i];
//			if(nx==x2 && ny==y2) {
//				is_find = true;
//				break;
//			}
//			vis[x][y] = true;
//			dfs(nx, ny);
//			vis[x][y] = false;
//		}
//	}
//}

//int main(void) {
//	
//	freopen("test", "r", stdin);
//	
//	for( ; EOF != scanf("%d %d", &r, &c), r+c; ) {
//		for(int i=1; i<=r; i++) {
//			for(int k=1; k<=c; k++) {
//				scanf("%d", mtx[i]+k);
//			}
//		}
//		int t;
//		scanf("%d", &t);
//		for( ; t--; ) {
//			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//			is_find = false;
//			if(mtx[x1][y1] != mtx[x2][y2]) {
//				printf("NO\n");
//			} else if(mtx[x1][y1] == 0) {
//				printf("NO\n");
//			} else {
//				memset(vis, false, sizeof(vis));
//				dfs(x1, y1);
//				printf("%s\n", is_find ? "YES" : "NO");
//			}
//		}
//	}
//	
//	return 0;
//}









//要判断转弯剪支
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 1005
using namespace std;

int r, c, is_find;
int x1, y1, x2, y2;

int mtx[MAXN][MAXN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool vis[MAXN][MAXN];

void dfs(int x, int y, int dir, int count) {
	if(is_find) return ;
	if(x<1 || x>r || y<1 || y>c) return ;
	if(vis[x][y]) return ;
	if(count >= 3) return ; //转弯超过2次 减掉
	if(x!=x1 || y!=y1) 
		if(mtx[x][y] != 0) return;
	if(x==x2 && y==y2) { //到终点
		is_find = true;
		return ;
	}
	for(int i=0; i<4; i++) {
		if(x1==x && y1==y) dir = i;
		if(!vis[x][y]) {
			int nx = x+dx[i], ny = y+dy[i];
			int ndir = i;
			if(nx==x2 && ny==y2) {
				is_find = true;
				break;
			}
			vis[x][y] = true;
			if(ndir != dir)
				dfs(nx, ny, ndir, count+1);
			else
				dfs(nx, ny, ndir, count);
			vis[x][y] = false;
		}
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d %d", &r, &c), r+c; ) {
		for(int i=1; i<=r; i++) {
			for(int k=1; k<=c; k++) {
				scanf("%d", mtx[i]+k);
			}
		}
		int t;
		scanf("%d", &t);
		for( ; t--; ) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			is_find = false;
			if(mtx[x1][y1] != mtx[x2][y2]) {
				printf("NO\n");
			} else if(mtx[x1][y1] == 0) {
				printf("NO\n");
			} else if(x1==x2 && y1==y2) {
				printf("NO\n");
			} else if(x1<1 || x2<1 || x1>r || x2>r ||
				y1<1 || y2<1 || y1>c || y2>c) {
				printf("NO\n");
			} else {
				memset(vis, false, sizeof(vis));
				dfs(x1, y1, 0, 0);
				printf("%s\n", is_find ? "YES" : "NO");
			}
		}
	}
	
	return 0;
}


