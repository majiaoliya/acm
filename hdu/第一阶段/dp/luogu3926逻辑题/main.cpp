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
#define PARSE(x) ((x>='a' && x<='z') ? x-'a' : x-'A')
#define QAQ (0)

using namespace std;

int a, c, p, q, r, x;
template <typename T>
T abs(T val) { val > 0 ? val : -val; }

/**
 *  蒟蒻果冻为a摄氏度，
	1、蒟蒻果冻小于c度的时候，每p单位时间加热1单位温度；
	2、当蒟蒻果冻等于c度的时候，时间+q
	3、当蒟蒻果冻解冻完成之后，每r单位时间加热1单位温度。
	求将果冻加热x单位时间的时候果冻的温度。

	从当前温度开始算就行了,可能有当前温度大于等于解冻温度的情况(a>c)
 */

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d %d %d %d %d ", &a, &c, &p, &q, &r, &x)) {
		if(a < c) {
			int toc_need = abs((c-a))*p;
			if(x >= toc_need) 
				x -= toc_need, a = c;
			else 
				a = a+(x/p), x = 0;
		}
		if(a == c) {
			if(x >= q) x -= q;
			else x = 0;
		}
		if(x) {
			a += x/r;
		}
		printf("%d\n", a);
	}

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



