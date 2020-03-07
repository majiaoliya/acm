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
#include <set>
#include <stack>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给定n个天然气井坐标(Xi,Yi), n个中转站坐标(xi,yi)
 * 定义天然气井(Xi,Yi)到中转站(xi,yi)的距离为di(曼哈顿距离)
 * 要求天然气井和中转站一一配对 求每一对的距离之和最小是多少
 * 思路:
 * 		di = abs(Xi-ai) + abs(Yi-yi)
 * 		ans = sum(di) { i = 1 to n }
 * 		化简:
 * 			sum(di) = sum( abs(Xi-xi) + abs(Yi-yi) )
 * 			        = sum(abs(Xi-xi)) + sum(abs(Yi-yi))
 * 			        = |sum(Xi)-sum(xi)| + |sum(Yi)-sum(yi)|
 */

ll n, a, b;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld ", &n);
	ll Xi = 0, Yi = 0, xi = 0, yi = 0;
	for(int i=1; i<=n; i++) {
		scanf("%lld %lld ", &a, &b);
		Xi += a, Yi += b;
	}
	for(int i=1; i<=n; i++) {
		scanf("%lld %lld ", &a, &b);
		xi += a, yi += b;
	}
	printf("%lld\n", abs(Xi-xi)+abs(Yi-yi));







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


