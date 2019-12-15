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
#define ll long long int
#define QAQ (0)

using namespace std;

// 4a + 7b = n

/**
 * n <= 1e6
 * 小学数学题:给定一个数字n,求一个只由4或7组成的数字x(可能很大)要求x各位数字和恰好等于n
 * 其实就是对与4a + 7b = n 枚举a值即可
 */

int n;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d\n", &n);
	for(int a=0; a<=(4*n); a++) { //枚举a
		int b = (n - (a*4)) / 7;
		if(4*a + 7*b == n) {
			if(a<0 || b<0) continue ;
			for(int i=1; i<=a; i++) printf("4");
			for(int k=1; k<=b; k++) printf("7");
			return 0;
		}
	}
	printf("YingYingYing\n");








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


