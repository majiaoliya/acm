#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int 
using namespace std;
#define MAXN 505
ll n, k;
ll arr[MAXN], val[250000+10];

int cmp(int x, int y) { return x < y; }

int main(void) {
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%lld %lld", &n, &k); ) {
		int pn = 0;
		for(int i=0; i<n; i++)
			scanf("%lld", arr+i);
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				val[pn++] = arr[i] + arr[j];
		sort(val, val+pn);
		ll sum = 0;
		for( ; k--; )
			sum += val[--pn];
		printf("%lld\n", sum);
	}
	
	return 0;
}
