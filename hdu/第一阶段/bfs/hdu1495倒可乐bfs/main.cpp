#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#include <vector>
#define MAXN 105

using namespace std;

int s, n, m;

int vis[MAXN][MAXN][MAXN];

struct Node {
	int s, n, m, step;
};

bool dao(int& a, int va, int& b, int vb) { //a倒到b
	bool ret = false;
	if(a == 0) return ret;
	int sb = vb - b; //b瓶剩余的体积
	if(a > sb) {
		a -= sb;
		b += sb;
		ret = true;
	} else if(a <= sb) {
		b += a;
		a -= a;
		ret = true;
	}
	return ret;
}

int bfs() {
	int rs = -1;
	if(s & 1) return rs;
	queue<Node> q;
	memset(vis, false, sizeof(vis));
	Node x, nx;
	x.s = s, x.n = 0, x.m = 0, x.step = 0;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
		q.pop();
//		printf("[%d %d %d]\n", x.s, x.n, x.m);
		vis[x.s][x.n][x.m] = true;
		if(x.s == x.m && x.s == (s>>1)) { rs = x.step; break; }
		nx.step = x.step + 1;
		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.s, s, nx.n, n) && !vis[nx.s][nx.n][nx.m]) q.push(nx);
		
		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.s, s, nx.m, m) && !vis[nx.s][nx.n][nx.m]) q.push(nx);
		
		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.n, n, nx.s, s) && !vis[nx.s][nx.n][nx.m]) q.push(nx);
		
		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.n, n, nx.m, m) && !vis[nx.s][nx.n][nx.m]) q.push(nx);
		
		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.m, m, nx.s, s) && !vis[nx.s][nx.n][nx.m]) q.push(nx);
		
		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.m, m, nx.n, n) && !vis[nx.s][nx.n][nx.m]) q.push(nx);
	}
	return rs;
}

int main(void) {
	freopen("test", "r", stdin);
	while(EOF!=scanf("%d %d %d", &s, &n, &m) && (s+n+m)) {
		if(n>m) swap(n, m);
		int rs = bfs();
//		printf("%d\n", rs);
		if(rs == -1) printf("NO\n");
		else printf("%d\n", rs);
	}
	return 0;
}

