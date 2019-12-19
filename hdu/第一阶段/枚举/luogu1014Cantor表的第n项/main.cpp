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

/**
 * 
 *  1/1 1/2 1/3 1/4 1/5 1/6 1/7 1/8 1/9

	2/1 2/2 2/3 2/4 2/5 2/6 2/7 2/8

	3/1 3/2 3/3 3/4 3/5 3/6 3/7

	4/1 4/2 4/3 4/4 4/5 4/6

	5/1 5/2 5/3 5/4 5/5

	6/1 6/2 6/3 6/4

	7/1 7/2 7/3

	8/1 8/2

	9/1
	先跳到某一条斜线上 再枚举该斜线上的值还要分奇偶讨论
 */

int n;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d ", &n)) {
		int sum = 0, i = 1, line = 1;
		while(sum+i < n) { //跳到第n项的前一条斜线
			sum += i;
			i ++;
			line ++;
		}
		int fz, fm;
		if(line & 1) fz = line, fm = 1; //进入第n项的斜线后开始枚举
		else fz = 1, fm = line;
		sum ++;
		for( ; sum < n; sum++) {
			if(line & 1) fz --, fm ++; //枚举要分奇偶讨论
			else fm --, fz ++;
		}
		printf("%d/%d\n", fz, fm);
	}






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


