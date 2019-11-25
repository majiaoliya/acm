#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
#define MAXN 3005 
using namespace std;

bool vis[MAXN][MAXN];
int n, m, t;

bool check(int x, int y) { //检查点是否越界
	return (x>=1 && x<=n && y>=1 && y<=m && vis[x][y]==false);
}

int change(int x, int y) {
	vis[x][y] = true;
	int cnt = 0;
	if(check(x-1, y-1) && check(x-1, y) && check(x, y-1)) cnt ++;
	if(check(x-1, y) && check(x-1, y+1) && check(x, y+1)) cnt ++;
	if(check(x, y+1) && check(x+1, y+1) && check(x+1, y)) cnt ++;
	if(check(x+1, y) && check(x+1, y-1) && check(x, y-1)) cnt ++;
	return cnt;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d %d", &n, &m, &t);
	int rs = (n*m)-n-m+1;
	for(int x, y; t--; ) {
		scanf("%d %d", &x, &y);
		int del = change(x, y);
		rs -= del;
		printf("%d\n", rs);
	}
	return 0;
}
