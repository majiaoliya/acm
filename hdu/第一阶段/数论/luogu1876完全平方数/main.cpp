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

int n, m;

/**
 * 题意 : n栈灯开始时全关闭, 1到n个人第i个人每次把i的倍数的灯取反
 *  1: 1 2 3 4 5 ... n
 *  2: 2 4 6 8 ...
 *  3: 3 6 9 12 ....
 *  问n以后有多少个灯开着
 * 思路 : 一个数如果不是完全平方数,那么这个数有偶数个因子
 *    直接打印n以内的完全平方数
 */

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i*i<=n; i++) 
		printf("%s%d", i==1 ? "":" ", i*i);
#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

