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
 * 给定3个数组,每个数组里挑一个 组成3元组,最小化两两差值的绝对值
 * a[], b[], c[], an < bn < cn
 * 生成ab[an*bn] O(an*bn)
 * 枚举min(ab[], c[]) 二分max(ab[], c[])
 */

int n, m, a[MAXN], b[MAXN], c[MAXN], na, nb, nc;
int ab[MAXN], nab;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	freopen("out2", "w", stdout);
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
		int minx = 0x3f3f3f3f, maxx = -1, x, y, z;
		for(int i=1; i<=na; i++) 
			scanf("%d ", a+i), minx=min(minx, a[i]), maxx=max(maxx, a[i]);
		for(int i=1; i<=nb; i++) 
			scanf("%d ", b+i), minx=min(minx, b[i]), maxx=max(maxx, b[i]);
		for(int i=1; i<=nc; i++) 
			scanf("%d ", c+i), minx=min(minx, c[i]), maxx=max(maxx, c[i]);

		int ans = 0x3f3f3f3f;
		for(int i=1; i<=na; i++) {
			for(int j=1; j<=nb; j++) {
				for(int k=1; k<=nc; k++) {
					int D = abs(a[i]-b[j]) + abs(b[j]-c[k]) + abs(c[k]-a[i]);
					if(ans > D) 
						x = a[i], y = b[j], z = c[k];
					ans = min(D, ans);
				}
			}
		}
		printf("%d (%d %d %d)\n", ans, x, y, z);

	}

#ifdef debug2
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

