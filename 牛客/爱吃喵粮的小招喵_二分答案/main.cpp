#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 9999999
using namespace std;

int n, m, sum, arr[MAXN], ans;

bool check(int mid) {
	int need = 0;
	for(int i=1; i<=n; i++) {
		need += (arr[i]/mid);
		if(arr[i] % mid) need ++;
	}
	return need <= m;
}

int main(void) {
	freopen("test", "r", stdin);
	
	for(char c =' '; c!='\n'; ) {
		scanf("%d", &arr[++n]);
		sum += arr[n];
		c = getchar();
	}
	scanf("%d", &m);
	sort(arr+1, arr+1+n);
	int lef = 1, rig = sum;
	ans = sum;
	while(lef < rig) {
		int mid = (lef + rig)>>1;
		if(check(mid)) ans = mid, rig = mid;
		else lef = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
