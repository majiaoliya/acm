/**
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
#define min(x,y) ( x > y ? y : x )
#define ll long long int
#define MAXN 10005
using namespace std;
#define ll long long int
ll n, a, b, m, t;

ll dp[MAXN];
const int mod = 1e9+7;

ll fz(ll n) {
	if(n == 1) return 1;
//	ll aa = (n*n*n*b + (n-1)*n*n*a);
	if(n & 1) return (n*n*n*b + (n-1)*n*n*a) % mod;
	ll aa = (n*n*n*b + (n-1)*n*n*a);
	ll bb = (7*fz(n>>1) + 18*(n>>1)*(n>>1)*a);
	return min(aa, bb) % mod;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld %lld", &n, &a, &b);
		memset(dp, false, sizeof(dp));
		
//		dp[1] = 1;
//		for(int i=2; i<=n; i++) {
//			ll aa = i*i*i*b + (i-1)*i*i*a;
//			ll bb = 18*(i>>1)*(i>>1)*a + 7*dp[i>>1];
//			dp[i] = i&1 ? aa : min(aa, bb);
//			dp[i] %= mod;
//		}
//		
		printf("%lld\n", fz(n));
	}
	return 0;
}
*/




#include <iostream>
#define ll long long int
#define MAXN 36
using namespace std;
ll t, n, a, b;
const int mod = 1e9+7;

int main(void) {
	freopen("test", "r", stdin);
	cin >> t;
	while(t--) {
		cin >> n >> a >> b;
		ll dp[MAXN] = { 0 };
		dp[1] = 1;
		ll i = 1, k = 1;
		for( ; k<=32; i<<=1, k++) {
			if(k == 1) dp[k] = 1;
			else {
#define modi (i%mod)
#define modi2 ((i/2)%mod)
				ll aa = ((modi*modi*modi)*(b%mod)%mod + (((i-1)%mod)*modi*modi)%mod) % mod;
				ll bb = (((18%mod)*(modi2)*(modi2)*(a%mod))%mod + ((7%mod)*(dp[k-1]%mod)%mod)) % mod;
				dp[k] = min(aa, bb) % mod;
			}
			cout << dp[k] << endl;
		}
		
	}
	return 0;
}


