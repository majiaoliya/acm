#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long int
#define MAXN 105

int n;

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n)) {
		priority_queue<int, vector<int>, greater<int> > q;
		for(int i=1, x; i<=n; i++) {
			scanf("%d", &x);
			q.push(x);
		}
		int sum = 0;
		while(q.size() > 1) {
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
			sum += a + b;
			q.push(a+b);
		}
		printf("%d\n", sum);
	}
	return 0;
}



