#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 505
#include <map>
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, mp[MAXN][MAXN], pre[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m)) {
		for(int i=1; i<=m; i++) {
			int u, v, w;
		   	scanf("%d %d %d ", &u, &v, &w);
			mp[u][v] = w;
		}
		for(int k=1; k<=n+1; k++)
			for(int i=1; i<=n+1; i++)
				for(int j=1; j<=n+1; j++) {
					if(i!=j && j!=k && mp[i][k] && mp[k][j])
						mp[i][j] = max(mp[i][j], mp[i][k]+mp[k][j]);
				}
		printf("%d\n1 ", mp[1][n+1]);
		for(int i=2; i<=n+1; i++)
			if(mp[1][i]+mp[i][n+1] == mp[1][n+1]) printf("%d ", i);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


