//为啥dfs会有bug呢??????
//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <algorithm>
//#include <string.h>
//#define MAXN 10086
//using namespace std;

//int n, m, max_level, cnt = 0;
//bool vis[MAXN];
//vector<int> G[MAXN];

//void dsp() {
//	for(int i=1; i<=n; i++) {
//		printf("%d:", i);
//		for(int k=0; k<G[i].size(); k++) {
//			printf("->%d", G[i][k]);
//		}
//		printf("\n");
//	}
//}

//void dfs(int x, int level) {
//	if(vis[x] || level>m) return ;
//	vis[x] = true;
//	for(int i=0; i<G[x].size(); i++) {
//		int chl = G[x][i];
////		printf("%d,", chl);
//		if(!vis[chl]) {
//			if(level+1 <= m)
//				cnt ++;
//			dfs(chl, level+1);
//		}
//	}
//}

//int main() {
//	freopen("test", "r", stdin);
//	scanf("%d %d", &n, &m);
//	for(int i=1; i<=n; i++) {
//		int t;
//		scanf("%d", &t);
//		for(int k=1; k<=t; k++) {
//			int x;
//			scanf("%d", &x);
//			G[x].push_back(i);
//		}
//	}
////	dsp();
//	int t;
//	for(scanf("%d", &t); t--; ) {
//		int x;
//		max_level = 0, cnt = 0;
//		scanf("%d", &x);
////		printf("%d:", x);
//		memset(vis, false, sizeof(vis));
//		dfs(x, 0);
//		printf("%d\n", cnt);
//	}
//	return 0;
//}









#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
#define MAXN 10086
using namespace std;

int n, m, max_level, cnt = 0;
bool vis[MAXN];
vector<int> G[MAXN];

void dsp() {
	for(int i=1; i<=n; i++) {
		printf("%d:", i);
		for(int k=0; k<G[i].size(); k++) {
			printf("->%d", G[i][k]);
		}
		printf("\n");
	}
}

struct Node {
	int to, step;
	Node() : to(0), step(0) { }
	Node(int _t) : to(_t), step(0) { }
};

void bfs(int r) {
	queue<Node> q;
	Node nroot(r);
	q.push(nroot);
	while(!q.empty()) {
		Node x = q.front();
		q.pop();
		if(x.step<=m && !vis[x.to]) {
			vis[x.to] = true;
			cnt ++;
		}
		else continue ;
		for(int i=0; i<G[x.to].size(); i++) {
			int chl = G[x.to][i];
			Node n(chl);
			n.step = x.step + 1;
			q.push(n);
		}
	}
}

int main() {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		int t;
		scanf("%d", &t);
		for(int k=1; k<=t; k++) {
			int x;
			scanf("%d", &x);
			G[x].push_back(i);
		}
	}
//	dsp();
	int t;
	for(scanf("%d", &t); t--; ) {
		int x;
		max_level = 0, cnt = 0;
		scanf("%d", &x);
//		printf("%d:", x);
		memset(vis, false, sizeof(vis));
		bfs(x);
		printf("%d\n", cnt-1);
	}
	return 0;
}
