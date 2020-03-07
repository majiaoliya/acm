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

int n;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	scanf("%d ", &n);
	for(int a=1; a<=n; a++)
		for(int b=1; b<=n; b++)
			for(int c=b; c<=n; c++)
				for(int d=c; d<=n; d++)
					if(a*a*a == (b*b*b) + (c*c*c) + (d*d*d) &&
							a>1 && b>1 && c>1 && d>1)
						printf("Cube = %d, Triple = (%d,%d,%d)\n", 
								a, b, c, d);



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

