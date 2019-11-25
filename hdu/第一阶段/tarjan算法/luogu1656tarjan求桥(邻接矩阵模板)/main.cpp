#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 155
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int maps[MAXN][MAXN];
int n, m;

struct Edge {
	int x, y;
} E[5001]; //存储答案

int dfn[MAXN]; //dfs时第几个遍历 , 下标代表点编号, dfn[i]第几个遍历
int low[MAXN]; //这个点能通过他的child到达的的dfn值最小的dfn
int f[MAXN]; //他遍历的上一个点
int id; //用于dfn标记
int cnt;

void addEdge(int x, int y) {
	E[++cnt].x = x;
	E[cnt].y = y;
}

int cmp(Edge& a, Edge& b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

//tarjan求桥模板(求割点)
void tarjan(int x) {
	int y;
	dfn[x] = low[x] = ++id;
	for(int i=1; i<=n; i++) {
		if(!maps[x][i]) continue ;
		y = i;
		if(dfn[y] && y!=f[x]) 
			low[x] = min(low[x], dfn[y]); //如果是爸爸, 割边就没有用了
		if(!dfn[y]) {
			f[y] = x; //记录前驱
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if(low[y] > dfn[x]) addEdge(x, y); //low[chl]>dfn[x]就是割边
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	int x, y;
	cin >> n >> m;
	for(int i=1; i<=m; i++) {
		cin >> x >> y;
		maps[x][y] = maps[y][x] = 1;
	}
	for(int i=1; i<=n; i++) {
		if(!dfn[i]) tarjan(i);
	}
	sort(E+1, E+1+cnt, cmp);
	for(int i=1; i<=cnt; i++)
		cout << min(E[i].x, E[i].y) << " " << max(E[i].x, E[i].y) << endl;





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}








