//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <map>
//#include <set>
//#include <string.h>
//#include <queue>
////#include <math.h>
//#define MAXN 55
//#define ll long long
//using namespace std;

//ll t, n, q, p;
///**
//	求[(q^1)%p+(q^2)%p+(q^3)%p+...(q^n)%p] % p
//	= [(q%p)%p + (q%p*q%p)%p + (q%p*q%p*q%p) + ... ] % p
// */

//ll fp(ll a, ll b, ll mod) {
//	ll rs = 1;
//	while(b) {
//		if(b & 1) rs = rs*a % mod;
//		b >>= 1;
//		a = a*a % mod;
//	}
//	return rs;
//}

//ll slove(ll q, ll n, ll p) {
//	ll rs = 0;
//	for(int i=1; i<=n; i++) 
//		rs += fp(q, i, p);
//	return rs%p;
//}

//int main(void) {
//	freopen("test", "r", stdin);
//	scanf("%lld", &t);
//	while(t--) {
//		scanf("%lld %lld %lld", &q, &n, &p);
//	}
//	return 0;
//}



#include <iostream>
#define ll long long 
using namespace std;

ll n, p, q, t;

ll fp(ll a, ll b, ll mod) {
  ll rs = 1;
  while(b) {
    if(b & 1) rs = rs * a % mod;
    b >>= 1;
    a = a*a%mod;
  }
  return rs;
}

ll slove(ll n) {
  if(n == 1) return q;
  if(n%2 == 0) {
    return (fp(q, n/2, p)+1)%p * slove(n/2)%p;
  } else {
    return (fp(q, n, p) + slove(n-1)) % p;
  }
}

int main(void) {
  freopen("test", "r", stdin);
  scanf("%lld", &t);
  while(t--) {
    scanf("%lld %lld %lld", &q, &n, &p);
    printf("%lld\n", slove(n));
  }
  return 0;
}
