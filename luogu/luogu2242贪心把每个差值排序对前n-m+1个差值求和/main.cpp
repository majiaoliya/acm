#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)2e5+7)
#include <map>
#define ll long long int
#define QAQ (0)

using namespace std;
/**
 * 给定一个拍好序的数组,把数组分成m段,使得累加每段和最小
 * 直接贪心,把相邻两个数的差值算出来然后累加最小的前n-m+1个差值
 */
int n, m, arr[MAXN], b[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	int sum = 0;
	for(int i=0; i<n; i++) {
		scanf("%d ", arr+i);
		if(!i) continue ;
		b[i-1] = arr[i] - arr[i-1];
	}
	sort(b, b+n);
	for(int i=0; i<(n-m+1); i++) sum += b[i];
	printf("%d\n", sum+m);








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

