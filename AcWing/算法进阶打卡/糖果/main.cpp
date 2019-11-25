//#include <iostream> 
//#include <string.h>
//#include <vector>
//#include <time.h>
//using namespace std;
//#include <iostream>
//#include <math.h>
//#include <vector>
//#define MAXN 5005
//#define ll long long int
//using namespace std;

//ll sum[MAXN], arr[MAXN], n, o, d, t;

//ll max(ll a, ll b) { return a > b ? a : b; }

//int main(void) {
//	freopen("test", "r", stdin);
//	scanf("%lld", &t);
//	while(t--) {
//		scanf("%lld %lld %lld", &n, &o, &d);
//		for(int i=1; i<=n; i++) {
//			scanf("%lld", arr+i);
//			sum[i] = arr[i] + sum[i-1];
//		}
//		ll maxs = (ll)-1e9+5;
//		for(int i=1; i<=n; i++) {
//			ll ji = arr[i] & 1 ? 1 : 0;
//			ll s = arr[i];
//			for(int k=i+1; k<=n; k++) {
//				ji += arr[k] & 1 ? 1 : 0;
//				if(ji > o) break;
//				if(s+arr[k]>d) { break; }
//				ll tmax = max(s, s+arr[k]);
//				maxs = max(tmax, maxs);
//				s += arr[k];
//			}
//		}
//		if(maxs > d) printf("IMPOSSIBLE\n");
//		else printf("%lld\n", maxs);
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
#include <iostream>
#include <set>
#define ll long long int
#define N 100005
using namespace std;

ll x[N], s[N], A, B, C, M, L;

int main(void) {
	freopen("test", "r", stdin);
	int T;
	cin >> T;
	for(int cases=1; cases<=T; cases++) {
		ll n, o, d;
		cin >> n >> o >> d;
		cin >> x[1] >> x[2] >> A >> B >> C >> M >> L;
		for(int i=3; i<=n; i++) (x[i] = x[i-1]*A + x[i-2]*B+C)%M;
		for(int i=1; i<=n; i++) s[i] = x[i] + L;
		for(int i=1; i<=n; i++) s[i] += s[i-1];
		multiset<ll> S;
		S.insert(0);
		ll res = -1e18;
		for(int i=1, j=0, odds=0; i<=n; i++) {
			S.insert(s[j]);
			if(s[i]-s[i-1] & 1) odds++;
			while(odds > o) {
				S.erase(S.find(s[j]));
				if(s[j+1] - s[j]&1) odds --;
				j ++;
			}
			
			auto it = S.lower_bound(s[i]-d);
			if(it != S.end()) res = max(res, s[i] - *it);
		}
		printf("Case #%d: %lld\n", cases, res);
	}
}
