#include <iostream>
#include <set>
#include <vector>
#define MAXN 9999999
using namespace std;

int n, arr[MAXN], dp[MAXN];
int max(int x, int y, int z) {
	return x > y ? (x > z ? x : z) : (y > z ? y : z);
}
int main(void) {
	freopen("test", "r", stdin);
	bool ok = false;
	n = 0;
	while(EOF != scanf("%d", arr+n+1)) {
		if(arr[n+1] > 0) ok = true;
		n ++;
		getchar();
	}

	if(!ok) 
		printf("0\n");
	else {
		int lef = 0, rig = 0, sum = 0, rs = 0;
		for(int i=1; i<=n; i++) {
			sum += arr[i];
			sum = sum >= 0 ? sum : 0;
			rs = max(sum, rs);
		}
		printf("%d\n", rs);
	}
	return 0;
}
