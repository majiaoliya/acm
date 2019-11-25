#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <unordered_set>
#include <stdlib.h>
#define ll long long int
#define random(x) (rand()%x)
using namespace std;

int n, m;

void For(int n, int MAX) {
	for(int i=1; i<=n; i++)
		printf("%d ", random(MAX));
	printf("\n");
}

int main() {
#ifdef debug
	freopen("test", "w", stdout);
	clock_t stime = clock();
#endif
	srand(time(0));
	n = 100, m = 30;
	printf("%d\n", n);
	For(n, n);
	printf("%d\n", m);
	for(int i=1; i<=m; i++)
		printf("%d\n", random(n));





#ifdef debug2
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

