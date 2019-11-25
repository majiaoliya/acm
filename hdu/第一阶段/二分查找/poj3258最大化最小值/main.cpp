#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int len, n, m, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	
	while(EOF != scanf("%d %d %d", &len, &n, &m)) {
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		arr[0] = 0, arr[n+1] = len;
		int lef = 0, rig = len, mid;
		sort(arr, arr+n+2);
		int res = 0;
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			int cnt = 0, lst = arr[0];
			for(int i=1; i<=n+1; i++) {
				if(arr[i]-lst <= mid) cnt ++;
				else lst = arr[i];
			}
			if(cnt > m) rig = mid - 1, res = mid;
			else lef = mid + 1;
		}
		printf("%d\n", res);
	}
	
	return 0;
}
