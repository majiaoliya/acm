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

/**
 * 类似合并果子 把一块长度为n的木板切开消耗体力n,现在需要arr[]块木板
 * 问最小消耗多少体力
 * 每次挑两个最小的合并起来即可进行n-1次合并
 */
ll n, m;
priority_queue<ll, vector<ll>, greater<ll> > q;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld ", &n);
	for(ll i=1, x; i<=n; i++) {
		scanf("%lld ", &x);
		q.push(x);
	}
	ll ans = 0;
	while(q.size() > 2) {
		ll fst = q.top(); q.pop();
		ll snd = q.top(); q.pop();
		ans += fst + snd;
		q.push(fst+snd);
	}
	printf("%lld", ans);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


