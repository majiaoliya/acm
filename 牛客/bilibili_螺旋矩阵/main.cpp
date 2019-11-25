#include<time.h>
#include<limits.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string.h>

using namespace std;

int n, m;
const int MAXN = 5005;
int mtx[MAXN][MAXN];
bool vis[MAXN][MAXN];

int d[][2] = {
	{ 0, 1 },
	{ 1, 0 },
	{ 0, -1 },
	{ -1, 0 }	
};

bool check(int r, int c) {
	if(r<1 || r>n || c<1 || c>m || vis[r][c]) return false;
	return true;
}

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m) && (n!=-1)) {
		memset(vis, false, sizeof(vis));
		for(int i=1; i<=n; i++)
			for(int k=1; k<=m; k++)
				scanf("%d", &mtx[i][k]);
		int cnt = 0, mx = n*m, row = 1, col = 1, cur = 0;
		while(cnt < mx) {
			if(cnt++) printf(",");
			printf("%d", mtx[row][col]);
			vis[row][col] = true;
			if(!check(row+d[cur][0], col+d[cur][1]))
				cur = (cur+1) % 4;
			row += d[cur][0], col += d[cur][1];
		}
		printf("\n");
	}
	return 0;
}

