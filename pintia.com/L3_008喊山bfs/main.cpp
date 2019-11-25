/**
 * L3_008
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 10005

using namespace std;

int n, m, q;

bool vis[MAXN];
vector<int> vs[MAXN];

struct Node {
	int id;
	int count; //传到第几个山头
	Node() : id(0), count(0) { }
	Node(int _id, int _c) : id(_id), count(_c) { }
};

void display(int n) { //打印邻接表
	for(int i=1; i<=n; i++) {
		printf("%d:", i);
		for(int k=0; k<vs[i].size(); k++)
			printf("->%d", vs[i][k]);
		printf("\n");
	}
}

void bfs(int start) {
	Node s(start, 0);
	queue<Node> que;
	que.push(s);
	int count = 0, tid = 0;
	while(!que.empty()) {
		Node x = que.front();
		que.pop();
		if(vis[x.id]) continue ;
		vis[x.id] = true;
		if(x.count == count) {
			if(x.id < tid) tid = x.id;
		} else {
			if(x.count > count) count = x.count, tid = x.id;
		}
		vector<int>& tv = vs[x.id];
		for(int i=0; i<tv.size(); i++) {
			if(!vis[tv[i]]) {
				Node nxt(tv[i], x.count+1);
				que.push(nxt);
			}
		}
	}
	printf("%d\n", tid);
}

int main(void) {
	freopen("test", "r", stdin);
	
	scanf("%d %d %d", &n, &m, &q);
	for(int i=1; i<=m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vs[x].push_back(y);
		vs[y].push_back(x);
	}
//	display(n);
	for(int i=1,t; i<=q; i++) {
		scanf("%d", &t);
		memset(vis, false, n+4);
		bfs(t);
	}
	
	return 0;
}
