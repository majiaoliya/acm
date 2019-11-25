#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 5000005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int n, k;
long double arr[MAXN];

bool check(long double mid) {
	int sum = 0;
	for(int i=1; i<=n; i++) 
		sum += arr[i]/mid;
	return sum >= k;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	scanf("%d %d ", &n, &k);
	for(int i=1; i<=n; i++) scanf("%Lf", arr+i);
	long double lef = 0, rig = 1e12+7, mid = 0, ans = 0;
	while(rig-lef >= 0.00001) {
		mid = (lef + rig) / 2;
		if(check(mid)) ans = mid, lef = mid;
		else rig = mid;
	}
	printf("%.2Lf\n", ans);





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



