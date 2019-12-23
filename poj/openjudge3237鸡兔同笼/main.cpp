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

int T, n;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &T);
	while(T--) {
		scanf("%d ", &n);
		if(n & 1) { printf("0 0\n"); continue ; }
		int x, y; //鸡兔 2x + 4y = n
		if(n%4 == 0) printf("%d %d\n", n/4, n/2);
		else if(n%2 == 0) printf("%d %d\n", n/4+1, n/2);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


