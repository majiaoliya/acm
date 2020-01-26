#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <map>
#include <queue>
#define MAXN ((int)1e6+7)
#define ll long long int
#define ld double
#define QAQ (0)

using namespace std;

ld my_esp;

ld my_abs(ld x) { return x > 0 ? x : -x; }

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%lf ", &my_esp) ) {
		ld pi = 0, flag = 0, down = 1;
		while(true) {
			ld now = 1./down;
			now = flag ? -now : now;
			down += 2;
			flag = !flag;
			pi += now;
			if(fabs(now) < my_esp) {
				printf("Pi = %.4lf\n",pi*4);
				goto flag1;
			}

		}
		pi = 1;
		printf("Pi = %.4lf\n",pi*4);
flag1 : ;
	}




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


