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
#define MAXN ((int)1e5+7)
#define ll long long int
#define int long long int
#define QAQ (0)

using namespace std;

int n, m, a[MAXN], K, q[MAXN];
priority_queue<int, vector<int> > big;
priority_queue<int, vector<int>, greater<int> > sml;

void putin(int x) {
	sml.push(x);
	while(big.empty() || (sml.top()<big.top() && !sml.empty())) {
		big.push(sml.top());
		sml.pop();
	}
}

int kth() {
	while((int)big.size()>K) {
		sml.push(big.top());
		big.pop();
	}
	while((int)big.size()<K && !sml.empty()) {
		big.push(sml.top());
		sml.pop();
	}
	return big.top();
}

signed main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld %lld ", &n, &m);
	for(int i=1; i<=n; i++) scanf("%lld ", a+i);
	for(int i=1; i<=m; i++) scanf("%lld ", q+i);
	for(int i=1, k=1; i<=m; i++) {
		while(k<=q[i]) {
			putin(a[k]);
//			printf("put(%lld)  ", a[k]);
			k ++;
		}
		++ K;
//		printf(" k:%lld ans:%lld\n", K, kth());
		printf("%lld\n", kth());
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


