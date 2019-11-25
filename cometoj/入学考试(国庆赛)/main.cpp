#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long int
const int MAXN = 100005;

ll n, m, v, T, ans, sum, ti[MAXN], psum[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld %lld %lld", &n, &m, &v, &T);
		ans = ans = 0;
		for(ll i=1; i<=m; i++) scanf("%lld", ti+i), sum+=ti[i];
		sort(ti+1, ti+1+m);
		for(ll i=1; i<=m; i++) psum[i] = psum[i-1] + ti[i];
		if(sum*n <= T) { //可以写完所有试卷
			printf("%lld\n", m*n+v*n);
			continue ;
		}
		for(ll i=0; i<=n; i++) {
			ll time = T - (i*sum); //写完i张试卷剩余的时间
			ll score = i*m + i*v;
			if(time < 0) break;
			//二分剩下的时间能做多少道题
			ll lef = 0, rig = m, res = 0, mid = 0;
			while(lef <= rig) {
				mid = (lef + rig) >> 1;
				if(time >= psum[mid]*(n-i))
					res = mid, lef = mid + 1;
				else
					rig = mid - 1;
			}
			score += (n-i)*res + (time-psum[res]*(n-i))/ti[res+1];
			ans = max(ans, score);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
