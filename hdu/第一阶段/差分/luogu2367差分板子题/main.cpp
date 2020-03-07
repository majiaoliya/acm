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
#define MAXN (5000005)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给一个数组, 多次区间加减, 最后询问一次最小值
 * 
 * 差分数组 : dif[i] = a[i] - a[i]-1
 * 
 * 差分性质 : 差分数组前缀和就是原数组
 * 			 对于每次修改[]lef, rig]  => dif[lef]+=val, dif[rig+1]-=val;
 */

int n, m, a[MAXN], dif[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++)
		scanf("%d ", a+i), dif[i] = a[i] - a[i-1];
	while(m--) {
		int x, y, val;
		scanf("%d %d %d ", &x, &y, &val);
		dif[x] += val, dif[y+1] -= val;
	}
	int ans = 0x3f3f3f3f;
	for(int i=1; i<=n; i++) dif[i] += dif[i-1], ans = min(ans, dif[i]);
	printf("%d\n", ans);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

