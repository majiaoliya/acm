#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100006
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, m, arr[MAXN];

int my_lower(int key) {
	int lef = 1, rig = n, mid, ret = -1;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(key < arr[mid]) ret = mid, rig = mid - 1;
		if(key > arr[mid]) lef = mid + 1;
		if(key == arr[mid]) break;
	}
	return ret;
}

int my_upper(int key) {
	int lef = 1, rig = n, mid, ret = -1;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(key > arr[mid]) ret = mid, lef = mid + 1;
		if(key < arr[mid]) rig = mid - 1;
		if(key == arr[mid]) break;
	}
	return ret;
}

int my_search(int key) {
	int lef = 1, rig = n, mid;
	while(lef <= rig) {
		mid = (lef + rig) >> 1;
		if(key > arr[mid]) lef = mid + 1;
		if(key < arr[mid]) rig = mid - 1;
		if(key == arr[mid]) return mid;
	}
	return -1;
}

inline int abs(int x) { return x > 0 ? x : -x; }

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) scanf("%d ", arr+i);
	scanf("%d ", &m);
	sort(arr+1, arr+1+n);
	while(m--) {
		int key;
		scanf("%d ", &key);
		int s = my_search(key);
		if(s != -1) {
			printf("%d\n", arr[s]);
			continue ;
		}
		int l = my_lower(key);
		int r = my_upper(key);
		if(-1 == l && -1 != r) { printf("%d\n", arr[r]); continue ; }
		if(-1 != l && -1 == r) { printf("%d\n", arr[l]); continue ; }
		if(-1 != l && -1 != r) {
			int absl = abs(arr[l] - key), absr = abs(arr[r] - key);
			if(absl == absr) printf("%d\n", min(arr[l], arr[r]));
			else if(absl < absr) printf("%d\n", arr[l]);
			else printf("%d\n", arr[r]);
		}
	}






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

