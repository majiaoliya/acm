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
#include <math.h>
#include <stdlib.h>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给定3个升序数组,每个数组里挑一个 组成3元组,最小化两两差值的绝对值之和
 *                                             D = |a-b| + |b-c| + |c-a| 最小化D
 * 算法一:
 *    3个for暴力
 *    
 * 算法二:
 *	  a[], b[], c[], an < bn < cn
 *	 生成ab[an*bn] O(an*bn)
 *	 枚举min(ab[], c[]) 二分max(ab[], c[])
 *	 
 * 算法三: 
 *   每个数组维护一个指针下标pa, pb, pc开始指向第一个数
 *   每次移动最小的数的指针 并保存最小值 直到有一个越界
 */

int n, m, a[MAXN], b[MAXN], c[MAXN], na, nb, nc;
int ab[MAXN], nab;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	freopen("out1", "w", stdout);
	clock_t stime = clock();
#endif
	
	//[-1, 0, 9]
	//[-25, -10, 10, 11]
	//[2, 9, 17, 30, 41]
	// D = |a-b| + |b-c| + |c-a|
	int T;
	scanf("%d ", &T);
	while(T--) {

		scanf("%d %d %d ", &na, &nb, &nc);
		for(int i=1; i<=na; i++) scanf("%d ", a+i);
		for(int i=1; i<=nb; i++) scanf("%d ", b+i);
		for(int i=1; i<=nc; i++) scanf("%d ", c+i);
#ifdef debug2
		forarr(a, 1, na);
		forarr(b, 1, nb);
		forarr(c, 1, nc);
#endif

		int pa = 1, pb = 1, pc = 1, ans = 0x3f3f3f3f, x, y, z;
		while(true) {
			int D = abs(a[pa]-b[pb]) + abs(b[pb]-c[pc]) + abs(c[pc]-a[pa]);
			if(ans > D) {
				x = a[pa], y = b[pb], z = c[pc];
//				printf("%d %d %d = %d\n", a[pa], b[pb], c[pc], D);
//				printf("[%d %d %d]\n", abs(a[pa]-b[pb]), abs(b[pb]-c[pc]),
//						abs(c[pc]-a[pa]));
			}
			ans = min(D, ans);
			if(a[pa]<=b[pb] && a[pa]<=c[pc]) pa ++;
			else if(b[pb]<=a[pa] && b[pb]<=c[pc]) pb ++;
			else pc ++;
			if(pa>na || pb>nb || pc>nc) break;
		}
		printf("%d (%d %d %d)\n", ans, x, y, z);


	}
#ifdef debug2
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

