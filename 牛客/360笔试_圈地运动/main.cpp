#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#define ll long long int
#define max(x, y) ( x > y ? x : y )
#define min(x, y) ( x < y ? x : y )
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

int n, m, q, arr[MAXN], psum[MAXN];

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		if(n < 3) {
			printf("-1\n");
			continue ;
		}
		int sum = arr[1] + arr[2], ok = false;
		int tmax = max(arr[1], arr[2]);
		for(int i=3; i<=n; i++) {
			sum += arr[i];
			tmax = max(tmax, arr[i]);
			if(sum - tmax > tmax) {
				printf("%d\n", i);
				ok = true;
				break;
			}
		}
		if(!ok) printf("-1\n");
	}
	return 0;
}



