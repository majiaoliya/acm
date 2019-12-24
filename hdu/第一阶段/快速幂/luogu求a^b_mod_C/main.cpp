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

ll n, m, mod;

ll fp(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = (ret * a ) % mod;
		b >>= 1;
		a = a*a % mod;
	}
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%lld %lld %lld ", &n, &m, &mod);
	//注意: 要对最后答案mod mod 不然wa最后一个点
	printf("%lld^%lld mod %lld=%lld\n", n, m, mod, fp(n, m)%mod);








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


