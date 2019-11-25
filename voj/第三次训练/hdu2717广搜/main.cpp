#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 100010
using namespace std;

int n, k;

struct Node {
	int step, num;
//	Node(int s, int n) : step(s), num(n) { }
};

queue<Node> q;
int bfs() {
	int rs = 0;
	int vis[100010] = { 0 };
	Node fst, nx, x;
	fst.step = 0, fst.num = n;
	q.push(fst);
	while(!q.empty()) {
		x = q.front();
		q.pop();
		if(x.num == k) { rs = x.step; break; }
		vis[x.num] = true;
		nx.step = x.step + 1, nx.num = x.num + 1;
		if(nx.num<=100000 && nx.num>=0 && !vis[nx.num]) q.push(nx);
		nx.num = x.num - 1;
		if(nx.num<=100000 && nx.num>=0 && !vis[nx.num]) q.push(nx);
		nx.num = x.num * 2;
		if(nx.num<=100000 && nx.num>=0 && !vis[nx.num]) q.push(nx);
	}	
	return rs;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &k); ) {
//		if(n > k) swap(n, k);
		q = queue<Node>();
		printf("%d\n", bfs());
	}
	return 0;
}
