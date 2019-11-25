#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, m, a[MAXN], b[MAXN];

int my_lower(int key) {
	int lef = 1, rig = n, mid, idx = -1;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(key >= a[mid]) idx = mid, lef = mid + 1;
		else rig = mid - 1;
	}
	return idx;
}

int my_upper(int key) {
	int lef = 1, rig = n, mid, idx = -1;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(key <= a[mid]) idx = mid, rig = mid - 1;
		else lef = mid + 1;
	}
	return idx;
}

int abs(int x) { return x > 0 ? x : -x; }

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d ", a+i);
	sort(a+1, a+1+n);
//	forarr(a, 1, n);
	int sum = 0;
	for(int i=1, key; i<=m; i++) {
		scanf("%d ", &key);
		if(std::binary_search(a+1, a+1+n, key)) continue ;
		int l = my_lower(key), r = my_upper(key);
//		printf("%d = %d %d\n", key, l==-1?-1:a[l], r==-1?-1:a[r]);
		if(-1 == l) { sum += abs(a[r]-key); }
		else if(-1 == r) { sum += abs(a[l]-key); }
		else sum += min(abs(a[l]-key), abs(a[r]-key));
	}
	printf("%d\n", sum);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

