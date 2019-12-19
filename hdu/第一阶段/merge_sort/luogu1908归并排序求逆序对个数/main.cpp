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
#define MAXN ((int)5e5+7)
#define ll long long int
#define OO (0x3f3f3f3f)
#define QAQ (0)

using namespace std;

/**
 * 归并排序求逆序对个数
 * 在归并排序的过程中把答案统计出来即可
 * 当然也可用线段树或树状数组做,扫一遍a[]对于每个a[i]求a[1-i-1]有多少个比a[i]小
 * 权值线段树 ??
 */

ll n, m, arr[MAXN], tmp[MAXN];
ll buf[MAXN], ans;

void merge(int lef, int rig) {
	if(lef == rig) return ;
	int mid = (lef + rig) >> 1;
	merge(lef, mid);
	merge(mid+1, rig);
	int i = 0, x = lef, y = mid+1;
	for( ; i<(rig-lef+1); i++) {
		if(x<=mid && y<=rig) {
			if(tmp[x] > tmp[y]) {
				ans += mid-x+1; //统计答案
				buf[i] = tmp[y++];
			}
			else buf[i] = tmp[x++];
			continue ;
		}
		if(x <= mid) buf[i] = tmp[x++];
		if(y <= rig) buf[i] = tmp[y++];
	}
	int k = lef;
	for(i=0; i<(rig-lef+1); i++, k++)
		tmp[k] = buf[i];
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld ", &n);
	for(int i=1; i<=n; i++) scanf("%lld ", arr+i), tmp[i] = arr[i];
	merge(1, n);
	printf("%lld\n", ans);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


