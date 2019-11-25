#include <iostream>
#include <string.h>
#define ll long long int
using namespace std;

const int MAXN = 1e6;

ll arr[MAXN];
ll dp[MAXN];
ll mmax[MAXN];

int main(void) {

	ll m, n, mmmax;
	for( ; cin>>m>>n; ) {
		for(int i=0; i<n; i++) cin >> arr[i];
		memset(dp, false, sizeof(dp));
		dp[0] = 0;
		mmax[0] = 0;
		for(int i=1; i<=m; i++) {
			memset()
		}
	}

	return 0;
}
