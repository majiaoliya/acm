#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long int
using namespace std;

const int MAXN = 200005;

ll k, m, n, p, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%lld %lld %lld %lld", &k, &m, &n, &p); ) {
		for(ll i=1; i<=k; i++) 
			scanf("%lld", arr+i);
		sort(arr+1, arr+1+n);
		
	}
	return 0;
}
