#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <queue>
#define MAXN (128)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给定n个点m条边的有向图 其中一些点为定义为终点,判断给定字符串是否可以以终点结尾
 * 简单dfs
 */

int n, m, K, G[MAXN][MAXN], x;
bool is_end[MAXN], ans;
char str[1024*1024];

void dfs(int v, int ptr) {
	if(!str[ptr]) {
		if(is_end[v]) ans = true;
		return ;
	}
	for(int i=0; i<n; i++)
		if(str[ptr] == G[v][i]) {
			dfs(i, ptr+1);
		}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	scanf("%d ", &K);
	for(int i=1; i<=K; i++) {
		scanf("%d ", &x);
		is_end[x] = true;
	}
	for(int i=1; i<=m; i++) {
		int u, v;
		char ch;
		scanf("%d %d %c ", &u, &v, &ch);
		G[u][v] = ch;
	}
	scanf("%d ", &m);
	while(m--) {
		scanf("%s ", str);
		ans = false;
		dfs(0, 0);
		printf("%s\n", ans ? "Yes" : "No");
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


