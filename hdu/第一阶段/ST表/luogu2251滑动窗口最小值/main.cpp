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
#include <math.h>
#include <set>
#include <stack>
#include <queue>
#define MAXN (1000007)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, f[MAXN][40], LC;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++) 
		scanf("%d ", &(f[i][0]));
	LC = (int)(log(n)/log(2));
	for(int j=1; j<=LC; j++)
		for(int i=1; i<=n; i++) 
			f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
	int L = 1, R = m;
	for( ; R<=n; R++) {
		L = R - m + 1;
		int p = (int)(log(R-L+1)/log(2));
		printf("%d\n", min(f[L][p], f[R-(1<<p)+1][p]));
	}




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


