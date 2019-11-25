#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#define MAXN 100005
using namespace std;

priority_queue<int> q;
int n, m;

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	for(int i=0; !q.empty() && m--; i++) {
		if(i) printf(" ");
		printf("%d", q.top());
		q.pop();
	}
	return 0;
}

