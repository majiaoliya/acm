#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 300005
#include <map>
#define ll long long int
#define max(x, y) ( x > y ? x : y )
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

int n, arr[MAXN], dp[MAXN];

int main() {
	freopen("test", "r", stdin);
	cin >> n;
	int tmax, neg = true;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		if(arr[i] > 0) neg = false;
		tmax = i==1 ? arr[i] : min(tmax, arr[i]);
	}
	if(neg) {
		cout << tmax << endl;
		return 0;
	}
	dp[1] = arr[1];
	int sum = 0, rs = 0;
	for(int i=1; i<=n; i++) {
		sum += arr[i];
		sum = sum > 0 ? sum : 0;
		rs = max(sum, rs);
	}
	cout << rs << endl;
	return 0;
}



