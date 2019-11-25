#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#define MAXN (int)(500005)
using namespace std;

#define ll long long int

ll n, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%lld", &n)) {
		for(int i=1; i<=n; i++) scanf("%lld", arr+i);
		sort(arr+1, arr+1+n);
		bool ok = true;
		if(n < 2) ok = false;
		for(int i=2; i<=n && ok; i++)
			if(arr[i-1]==arr[i]) {
				ok = false;
				printf("%lld\n", arr[i]);
				break;
			}

	}
	return 0;
}
