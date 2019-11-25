#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define debug

typedef pair<int, int> pii;

int n, m;
pii arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		for(int i=1; i<=n; i++)
			scanf("%d %d", &arr[i].first, &arr[i].second);
		int cnt = 0;
		for(int i=1; i<=m; i++) {
			int a, an;
			scanf("%d %d", &a, &an);
			
		}
		printf("%d\n", cnt);
	}
	return 0;
}
