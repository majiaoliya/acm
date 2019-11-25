#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define MAXN 10000007
using namespace std;

int n, m, q, rs, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);
	scanf("%d", &m);
	sort(arr, arr+n);
	bool ok = false;
	for(int i=0; i<(n>>1) && arr[i]<=m; i++) {
		int key = m - arr[i];
		int pos = std::lower_bound(arr, arr+n, key) - arr;
		if(pos>=0 && pos<n && arr[pos]==key) {
			printf("%d %d\n", arr[i], arr[pos]);
			ok = true;
		}
	}
	if(!ok) printf("NO\n");
	return 0;
}
