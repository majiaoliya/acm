//dfs可能有问题
//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <map>
//#include <string.h>
//#include <algorithm>
//#define MAXN 10005
//using namespace std;

//vector<int> G[MAXN];
//int n, m, cnt;
//bool vis[MAXN];

//void dfs(int x, int level) {
//	if(vis[x] || level>6) return ;
//	if(level <= 6) cnt ++;
//	vis[x] = true;
//	for(int i=0; i<G[x].size(); i++) {
//		dfs(G[x][i], level+1);
//	}
//}

//int main() {
//	freopen("test", "r", stdin);
//	
//	scanf("%d %d", &n, &m);
//	int x, y;
//	for(int i=0; i<m; i++) {
//		scanf("%d %d", &x, &y);
//		G[x].push_back(y);
//		G[y].push_back(x);
//	}
//	
//	for(int i=1; i<=n; i++) {
//		memset(vis, false, n+4);
//		cnt = 0;
//		dfs(i, 0);
//		double rs = ((double)cnt)/n;
//		printf("%d: %.2lf%%\n", i, rs*100);
//	}
//	
//	return 0;
//}





//对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。每个结节点输出一行，格式为“结点编号:（空格）百分比%”。




// bfs
#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAXN 10015
using namespace std;

vector<int> G[MAXN];
int n, m, cnt;
bool vis[MAXN];

struct Node {
	int to, level;
	Node() : to(0), level(0) { }
};

void bfs(int root) {
	queue<Node> q;
	vis[root] = true;
	Node nroot;
	nroot.to = root, nroot.level = 0;
	q.push(nroot);
	while(!q.empty()) {
		Node x = q.front();
		q.pop();
		if(x.level <= 6) cnt ++;
		for(int i=0; i<G[x.to].size(); i++) {
			int chl = G[x.to][i];
			int chl_level = x.level + 1;
			if(!vis[chl] && chl_level<=6) {
				vis[chl] = true;
				Node nchl;
				nchl.to = chl, nchl.level = chl_level;
				q.push(nchl);
			}
		}
	}
}

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d %d", &n, &m);
	int x, y;
	for(int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	
	for(int i=1; i<=n; i++) {
		memset(vis, false, n+10);
		cnt = 0;
		bfs(i);
		printf("%d\n", cnt);
	}
	
	return 0;
}



