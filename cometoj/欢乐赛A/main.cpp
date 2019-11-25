#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int 
using namespace std;
#define MAXN 505
ll n, k;

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld", &k, &n);
		if(k == 1) {
			printf("%lld\n", n-1);
			continue ;
		} else if(n == 0) {
			printf("0\n");
			continue ;
		}
		ll temp = n, need = 1, level = -1;
		while(true) {
			if(need >= temp) break;
			temp -= need;
			need *= k;
			level ++;
		}
//		printf("%lld 拼出了:%lld level\n", n, level);
		ll rs = level * 2;
		if(temp >= 1) rs ++;
		if(temp > need/2) rs ++;
		printf("%lld\n", rs > 0 ? rs : 0);
		
		/**
		ll p = 1, ans = 0;
		while(n>=p) {
			n -= p; p *= k; ans ++;
		}
		if(n == 0) printf("%lld\n", ans*2-2);
		else if (n*k<=p) printf("%lld\n", ans*2-1);
		else printf("%lld\n", ans*2);
		*/
	}

	return 0;
}


