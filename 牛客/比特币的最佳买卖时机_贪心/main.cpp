#include <iostream>
#include <set>
#include <vector>
#include <queue>
#define MAXN 9999999
using namespace std;

int n, minarr[MAXN], arr[MAXN], rs[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	for(int x; ~scanf("%d", &x); ) {
		n ++;
		arr[n] = x;
		if(n == 1) minarr[n] = x;
		else minarr[n] = min(minarr[n-1], x);
	}
	int ans = 0;
	for(int i=2; i<=n; i++) {
		rs[i] = arr[i] - minarr[i-1];
//		printf("%d - %d = %d\n", arr[i], minarr[i-1], rs[i]);
		ans = max(rs[i], ans);
	}
	cout << ans << endl;
	return 0;
}
