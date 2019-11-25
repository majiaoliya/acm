#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#define MAXN 205
using namespace std;

int n, k;

struct Node {
	int step, idx;
};

int bfs() {
	queue<Node> q;
	Node x, nx;
	x.step = 0, x.idx = n;
	q.push(x);
	int ret = -1;
	bool vis[100005] = { 0 };
	
	while(!q.empty()) {
		x = q.front();
		q.pop();
		vis[x.idx] = true;
		if(x.idx == k) { ret = x.step; break; }
		nx.step = x.step+1;
		nx.idx = x.idx+1;
		if(nx.idx>=0 && nx.idx<=100000 && !vis[nx.idx])
			q.push(nx);
		nx.idx = x.idx-1;
		if(nx.idx>=0 && nx.idx<=100000 && !vis[nx.idx])
			q.push(nx);
		nx.idx = x.idx*2;
		if(nx.idx>=0 && nx.idx<=100000 && !vis[nx.idx])
			q.push(nx);
	}
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &k); ) {
		printf("%d\n", bfs());
	}
	return 0;
}
