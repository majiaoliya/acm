#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
#define ll long long int
using namespace std;

int n;

int main(void) {
	freopen("test", "r", stdin);
	ll arr[MAXN];
	arr[0] = 0, arr[1] = 1, arr[2] = 2;
	for(int i=3; i<MAXN; i++)
		arr[i] = arr[i-1] + arr[i-2];
	for( ; EOF != scanf("%d", &n); ) {
		printf("%lld\n", arr[n]);
	}
	return 0;
}
