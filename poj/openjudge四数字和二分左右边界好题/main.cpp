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
#define MAXN ((int)4e3+7)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给定4个数组 每个数组里挑一个相加得到sum,问sum==0有几种可能
 * 把a[]和b[]两两相加, c[]和d[]两两相加 
 * 得到ab[n*n], cd[n*n]
 * 枚举ab[i],二分cd[n*n]
 * 二分的时候要二分左右边界 不能像书里那样二分左边界枚举右边界
 */

int n, a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int ab[MAXN*MAXN], cd[MAXN*MAXN], nab, ncd;

int binsearch(int* arr, int key, int N) { //返回arr[]里有多少个key
	int lef = 1, rig = N, mid = 0, l = -1, r = -1;
	while(lef <= rig) { //二分左边界
		mid = (lef + rig) >> 1;
		if(arr[mid] < key) lef = mid + 1;
		else {
			if(arr[mid] == key) l = mid;
			rig = mid - 1;
		}
	}
	if(l == -1) return 0; //没有key返回0
	lef = 1, rig = N;
	while(lef <= rig) { //二分右边界
		mid = (lef + rig) >> 1;
		if(arr[mid] <= key) {
			if(arr[mid] == key) r = mid;
			lef = mid + 1;
		} else rig = mid - 1;
	}
//	printf("[l:%d r:%d %d]\n", l, r, r-l+1);
	return (r-l+1);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
#ifdef debug2
	int arr[] = {0, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4};
	printf("%d\n", binsearch(arr, 3, 11));
#endif

	scanf("%d ", &n);
	for(int i=1; i<=n; i++)
		scanf("%d %d %d %d ", a+i, b+i, c+i, d+i);
	for(int i=1; i<=n; i++)
		for(int k=1; k<=n; k++) {
			ab[(++nab)] = a[i] + b[k];
			cd[(++ncd)] = c[i] + d[k];
		}
	int ans = 0;
#ifdef debug2
	forarr(a, 1, n);
	forarr(b, 1, n);
	forarr(ab, 1, nab);
	forarr(cd, 1, ncd);
#endif
	sort(cd+1, cd+1+ncd);
	for(int i=1; i<=nab; i++) { //枚举ab[]
		ans += binsearch(cd, -ab[i], ncd); //二分cd[]里有多少个-ab[i]
	}
	printf("%d\n", ans);




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


