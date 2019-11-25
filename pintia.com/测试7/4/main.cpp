#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#define MAXN 105
using namespace std;

int n, m, q;

int mtx[MAXN][MAXN]; // -1敌对, 1朋友

int good_pre[MAXN], bad_pre[MAXN];
void init() {
	for(int i=1; i<=n; i++)
		good_pre[i] = -1, bad_pre[i] = -1;
}

int fa(int x, int pre[]) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x)
		pre[x] = ret;
	return ret;
}

void union_xy(int x, int y, int pre[]) {
	int rx = fa(x, pre), ry = fa(y, pre);
	if(rx != ry)
		pre[ry] = rx;
}

int main()
{
	freopen("test", "r", stdin);
	
	scanf("%d %d %d", &n, &m, &q);
	init();
	for(int i=1; i<=m; i++) {
		int x, y, tag;
		scanf("%d %d %d", &x, &y, &tag);
		mtx[x][y] = mtx[y][x] = tag;
		if(tag == 1) { //加入朋友
			union_xy(x, y, good_pre);
		} else { //加入敌对
			union_xy(x, y, bad_pre);
		}
	}
	
	for(int i=1; i<=q; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		bool good_tag = fa(x, good_pre)==fa(y, good_pre);
		bool bad_tag = fa(x, bad_pre)==fa(y, bad_pre);
		if(mtx[x][y] == 1)
			printf("No problem\n");
		else if(mtx[x][y]!=1 && mtx[x][y]!=-1) 
			printf("OK\n");
		else if(mtx[x][y]==-1 && good_tag)
			printf("OK but...\n");
		else if(mtx[x][y]==-1 && !good_tag)
			printf("No way\n");
	}
	
	return 0;
}

