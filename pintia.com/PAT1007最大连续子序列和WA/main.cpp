#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n;
int arr[MAXN], dp[MAXN];

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d", &n);
	for(int i=0; i<n; i++) 
		scanf("%d", arr+i);
	dp[0] = arr[0];
	int rs_lef=0, rs_rig=0, lef=0, rig=0, tmax=arr[0];
	for(int i=1; i<n; i++) {
		int t = dp[i-1] + arr[i];
		dp[i] = max(t, arr[i]);
		if(dp[i-1] < dp[i]) lef = i;
		if(t > tmax) {
			rs_lef = lef;
			rs_rig = rig = i;
			tmax = t;
		}
	}
	
	printf("%d %d %d\n", tmax, rs_lef, rs_rig);
	
	return 0;
}
