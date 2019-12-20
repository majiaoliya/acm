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

//归并排序板子 luogu1177
int n, arr[MAXN], tmp[MAXN];

void merge_sort(int lef, int rig) {
	if(lef == rig) return ;
	int mid = (lef + rig) >> 1;
	merge_sort(lef, mid);
	merge_sort(mid+1, rig);
	int i = lef, k = mid+1, sz = 0;
	while(i<=mid && k<=rig) {
		if(arr[i] < arr[k]) { tmp[sz] = arr[i]; i++; }
		else { tmp[sz] = arr[k]; k++; }
		sz ++;
	}
	while(i<=mid) { tmp[sz] = arr[i]; i++; sz++; }
	while(k<=rig) { tmp[sz] = arr[k]; k++; sz++; }
	for(i=0, k=lef; i<sz; i++, k++) arr[k] = tmp[i];
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) scanf("%d ", arr+i);
	merge_sort(1, n);
	for(int i=1; i<=n; i++)
		if(i == 1) printf("%d", arr[i]);
		else printf(" %d", arr[i]);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


