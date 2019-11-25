//不会用并查集写
//#include <iostream>
//#include <vector>
//#define MAXN 10086

//using namespace std;

//struct Edge {
//	int x, y;
//} e[MAXN];

//int n, m, k;
//bool vis[MAXN];

//int find_root(int x, int pre[]) {
//	int ret = x;
//	while(pre[ret] != -1) {
//		ret = pre[ret];
//	}
//	pre[x] = ret;
//	return ret;	
//}

//void union_xy(int x, int y, int pre[]) {
//	int rx = find_root(x, pre), ry = find_root(y, pre);
//	if(rx != ry) pre[ry] = rx;
//}

//int main()
//{
//    freopen("test.txt", "r", stdin);
//    scanf("%d %d %d", &n, &m, &k);
//    for(int i=1; i<=m; i++) 
//    	scanf("%d %d", &e[i].x, &e[i].y);
//    
//    for(int z=1; z<=k; z++) {
//    	int x, count=0;
//    	scanf("%d", &x);
//    	vis[x] = true;
//    	int pre[n+1];
//    	for(int i=1; i<=n; i++)
//    		pre[i] = -1;
//    	for(int i=1; i<=m; i++)
//    		if(!vis[e[i].x] && !vis[e[i].y]) 
//    			union_xy(e[i].x, e[i].y, pre);
//    	for(int i=1; i<=n; i++)
//    		if(pre[i]==-1 && !vis[i]) count ++;
//    	printf("%d\n", count-1);
//    }
//    
//    return 0;
//}











#include <iostream>
#include <vector>
#include <string.h>
#define MAXN 1086

using namespace std;

int n, m, k;
bool vis[MAXN], rmv[MAXN];
bool mtx[MAXN][MAXN];

void dfs(int x) {
	vis[x] = true;
	for(int i=1; i<=n; i++)
		if(!vis[i] && mtx[x][i]) dfs(i);
}

int main()
{
    freopen("test.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1; i<=m; i++) {
    	int x, y;
    	scanf("%d %d", &x, &y);
    	mtx[x][y] = mtx[y][x] = true;
    }
    
   	for(int z=1; z<=k; z++) {
   		int x;
   		scanf("%d", &x);
   		memset(vis, false, sizeof(vis));
   		vis[x] = true;
   		int count = 0;
   		for(int i=1; i<=n; i++)
   			if(!vis[i]) dfs(i), count++;
   		printf("%d\n", count-1);
   	}
   	
    return 0;
}


