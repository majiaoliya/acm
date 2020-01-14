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

ll n, m, q;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld %lld ", &n, &q);
	while(q--) {
		ll op, x;
		scanf("%lld %lld ", &op, &x);
		if(op == 1) m = (m + x) % n;
		else m = (m - x) % n;
	}
	m %= n;
	m = (m > 0 ? m : (n+m));
	for(ll i=m; i<n; i++) printf("%lld\n", i);
	for(ll i=0; i<m; i++) printf("%lld\n", i);




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


