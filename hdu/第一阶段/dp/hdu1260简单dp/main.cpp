
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 5005
#define ll long long int
using namespace std;

int k, arr[MAXN], dp[MAXN];
int temp[MAXN]; //和前一个人合买
	
int main() {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &k);
		for(int i=1; i<=k; i++)
			scanf("%d", arr+i);
		dp[0] = 0;
		for(int i=2; i<=k; i++)
			scanf("%d", temp+i);
		for(int i=1; i<=k; i++) {
			if(i == 1) { //只有自己一个人时
				dp[i] = arr[i];
			} else { //选择 min(不于前一个人买, 和前一个人买)
				dp[i] = min(dp[i-1]+arr[i], dp[i-2]+temp[i]);
			}
		}
		ll ti = 3600 * 8 + dp[k];
		ll hh = ti / 3600;
		ll mm = (ti-(hh*3600)) / 60;
		ll ss = (ti-(hh*3600)-(mm*60));
		printf("%02lld:%02lld:%02lld %s\n", hh, mm, ss, hh>=12?"pm":"am");
//		printf("%d\n", dp[k]);
	}

	return 0;
}



