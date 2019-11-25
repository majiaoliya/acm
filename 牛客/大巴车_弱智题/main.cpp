#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define MAXN 1000005
using namespace std;

int n, m, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	int tmp = n % m, cnt = n / m, k = n+m, j = n-tmp;
	while(cnt--) {
		int t = m, tk = k;
		while(t--) {
			arr[tk--] = arr[j--];
		}
		k += m;
	}
	for(int i=(n-tmp+1), tc=0; i<=2*n-tmp; i++) {
		if(tc ++) printf(" ");
		printf("%d", arr[i]);
	}
	return 0;
}
