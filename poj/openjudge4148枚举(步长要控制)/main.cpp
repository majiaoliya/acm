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
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int m = 21252;
int a, b, c, s, vis[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	int Case = 0;
	while(~scanf("%d %d %d %d ", &a, &b, &c, &s)) {
		if(a==-1) break; 
		int j = s + 1;
		for( ; j<m; j++)
			if(j%23 == a%23) break;
		for( ; j<m; j+=23)
			if(j%28 == b%28) break;
		for( ; j<m; j+=(23*28))
			if(j%33 == c%33) break;
		printf("Case %d: the next triple peak occurs in %d days.\n",
				++Case, j-s);
	}





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


