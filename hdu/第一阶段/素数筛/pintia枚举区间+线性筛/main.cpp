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
#define MAXN ((int)1e6+7)
#define IS_PRIME(x) (!vis[x])
#define ll long long int
#define QAQ (0)

using namespace std;
/**
 *  素数41能写成连续6个素数之和：41=2+3+5+7+11+13。 现在要求n以内的素数中，能表示为最多连续素数之和的那个数，如果有多个答案，请输出最大的那个素数。
 */


ll n, prime[MAXN], psum[MAXN], vis[MAXN], pn;

void get_prime() {
	vis[0] = vis[1] = true;
	for(ll i=2; i<MAXN; i++) {
		if(!vis[i]) prime[++pn] = i, psum[pn] = psum[pn-1] + i;
		for(ll k=1; k<=pn && i*prime[k]<MAXN; k++) {
			vis[i*prime[k]] = true;
			if(i%prime[k] == 0) break;
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	get_prime();
	scanf("%lld ", &n);
	ll ans = 0, len = -1;
	for(int i=1; i<=pn && prime[i]<=n; i++) {
		for(int k=0; k<i; k++) {
			ll sum = psum[i] - psum[k-1];
			printf("%lld, ", sum);
			if(sum > n) break;
			if(sum<=n && IS_PRIME(sum) ) {
				printf("[%d %d], ", k, i);
				ans = sum, len = i-k;
			}
		}
		printf("\n");
	}
	printf("%lld\n", ans);








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


