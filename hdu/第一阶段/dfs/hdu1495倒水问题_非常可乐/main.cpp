#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 105
using namespace std;

int s, n, m;
bool vis[MAXN][MAXN][MAXN];

struct Node {
	int s, n, m, step;
};

bool dao(int& a, int va, int& b, int vb) { //模拟a倒到b (va是a的总容量)
	int sb = vb - b; //b瓶剩余的体积
	if(a == 0) return false; //a瓶为空到不了
	if(a > sb) { //b瓶装不满
		a -= sb;
		b += sb;
		return true;
	} else if(a <= sb) { //b瓶装的满
		b += a;
		a -= a;
		return false;
	}
	return false;
}

int bfs() {
	int rs = -1;
	if(s & 1) return rs; //神奇的剪枝 对于奇数一定不能平分
	queue<Node> q;
	Node x, nx;
	x.s = s, x.n = n, x.m = m, x.step = 0;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
		q.pop();
		vis[x.s][x.n][x.m] = false;
		if(x.s == x.m) { rs = x.step; break; }
		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.s, s, nx.n, n) && vis[nx.s][nx.n][nx.m]) q.push(nx);

		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.s, s, nx.m, m) && vis[nx.s][nx.n][nx.m]) q.push(nx);
		
		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.n, n, nx.m, m) && vis[nx.s][nx.n][nx.m]) q.push(nx);

		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.n, n, nx.s, s) && vis[nx.s][nx.n][nx.m]) q.push(nx);

		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.m, m, nx.s, s) && vis[nx.s][nx.n][nx.m]) q.push(nx);

		nx.s = x.s, nx.n = x.n, nx.m = x.m;
		if(dao(nx.m, m, nx.n, n) && vis[nx.s][nx.n][nx.m]) q.push(nx);
	}
}

int main(void) {
	freopen("test", "r", stdin);
	while(EOF != scanf("%d %d %d", &s, &n, &m) && (s+n+m)) {
		int rs = bfs();
		memset(vis, false, sizeof(vis));
		if(rs == -1) printf("NO\n");
		else printf("%d\n", rs);
	}
	
	return 0;
}


