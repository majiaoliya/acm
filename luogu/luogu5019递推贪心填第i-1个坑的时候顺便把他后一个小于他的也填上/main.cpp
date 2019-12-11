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

int n, m, arr[MAXN], f[MAXN];
int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) scanf("%d ", arr+i);
	//对于第i个坑,如果小于前一个坑a[i]<=a[i-1],就可以填i-1的时候随便填i
	//否则单独填坑
	f[1] = arr[1];
	for(int i=2; i<=n; i++) {
		if(arr[i] <= arr[i-1]) f[i] = f[i-1];
		else f[i] = f[i-1] + (arr[i]-arr[i-1]);
	}
	printf("%d\n", f[n]);








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

