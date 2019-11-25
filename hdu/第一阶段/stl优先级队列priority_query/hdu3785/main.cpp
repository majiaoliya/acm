#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	int n, m;
	while(~scanf("%d %d", &n, &m) && (n+m)) {
		priority_queue<int> q;
		for(int i=0, x; i<n; i++) {
			scanf("%d", &x);
			q.push(x);
		}
		for(int i=1; i<=m; i++) {
			printf("%d%c", q.top(), i<m ? ' ' : '\n');
			q.pop();
		}
	}
	return 0;
}
