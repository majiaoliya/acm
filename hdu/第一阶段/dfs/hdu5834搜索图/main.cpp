//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string.h>
//#define MAXN 10005
//using namespace std;

//int n, rs; 
//int arr[MAXN];

//vector<int> vs[MAXN];
//int cost[MAXN][MAXN];
//bool vis[MAXN];

//void dfs(int x, int val) {
//	if(vis[x]) return ;
//	vis[x] = true;
//	if(val > rs) {
//		rs = val;
//	}
//	vector<int>& tv = vs[x];
//	for(int i=0; i<tv.size(); i++) {
//		if(!vis[tv[i]]) {
//			int nv = val + arr[tv[i]] - cost[x][tv[i]];
//			dfs(tv[i], nv);
//		}
//	}
//	vis[x] = false;
//}

//int main(void) {
//	
//	freopen("test", "r", stdin);
//	int t, count = 1;
//	scanf("%d", &t);
//	for( ; t--; ) {
//		printf("Case #%d:\n", count++);
//		scanf("%d", &n);
//		for(int i=1; i<=n; i++) {
//			scanf("%d", arr+i);
//			vs[i].clear();
//			memset(cost[i], false, n+10);
//		}
//		for(int i=1; i<n; i++) {
//			int u, v, c;
//			scanf("%d %d %d", &u, &v, &c);
//			vs[u].push_back(v);
//			vs[v].push_back(u);
//			cost[u][v] = cost[v][u] = c;
//		}
//		for(int i=1; i<=n; i++) {
//			rs = arr[i];
//			dfs(i, rs);
//			printf("%d\n", rs);
//		}
//	}
//	return 0;
//}







#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
using namespace std;

struct Edge {
	int cost, idx;
	Edge() : idx(0), cost(0) { }
	Edge(int _idx, int _c) : idx(_idx), cost(_c) { }
};

int n, rs; 
int arr[MAXN];
bool vis[MAXN];
int cost[MAXN][MAXN];
vector<Edge> vs[MAXN];

void dfs(int x, int val) {
	if(vis[x]) return ;
	if(val > rs) rs = val;
	vis[x] = true;
	vector<Edge>& tv = vs[x];
	for(int i=0; i<tv.size(); i++) {
		if(!vis[tv[i].idx]) {
			int nv = val + arr[tv[i].idx] - tv[i].cost;
			dfs(tv[i].idx, nv);
		}
	}
	vis[x] = false;
}

int main(void) {
	freopen("test", "r", stdin);
	
	int t, count = 1;
	scanf("%d", &t);
	for( ; t--; ) {
		printf("Case #%d:\n", count++);
		scanf("%d", &n);
		memset(vis, false, n+10);
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			vs[i].clear();
			memset(cost[i], false, n+3);
		}
		for(int i=1; i<n; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			Edge e1(u, c), e2(v, c);
			vs[u].push_back(e2);
			vs[v].push_back(e1);
		}
		for(int i=1; i<=n; i++) {
			rs = arr[i];
			dfs(i, rs);
			printf("%d\n", rs);
		}
	}
	return 0;
}


