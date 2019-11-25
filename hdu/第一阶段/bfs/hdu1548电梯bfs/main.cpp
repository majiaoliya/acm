#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAXN 305
int a, b, n, arr[MAXN];
bool vis[MAXN];
struct Node {
	int step, i;
};

bool check(int i) {
	if(i>0 && i<=n && !vis[i]) return true;
	return false;
}

int bfs() {
	Node x, nx;
	x.i = a, x.step = 0;
	queue<Node> q;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
//		printf("%d\n", x.i);
		q.pop();
		vis[x.i] = true;
		if(x.i == b) return x.step;
		nx.step = x.step + 1;
		nx.i = x.i + arr[x.i];
		if(check(nx.i)) q.push(nx);
		nx.i = x.i - arr[x.i];
		if(check(nx.i)) q.push(nx);
	}
	return -1;
}

int main(void) {
	freopen("test", "r", stdin);
	while(scanf("%d", &n) && n) {
		scanf("%d %d", &a, &b);
		for(int i=1; i<=n; i++)
			scanf("%d", arr+i);
		memset(vis, false, sizeof(vis));
		int rs = bfs();
		printf("%d\n", rs);
	}

	return 0;
}
