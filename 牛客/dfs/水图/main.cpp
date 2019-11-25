#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 50005

using namespace std;

int n, m;
long long int max_dist = 0;
struct Edge {
	int nxt;
	long long int dist;
	Edge(int _n, int _d) : nxt(_n), dist(_d) { }
	Edge() : nxt(0), dist(0) { }
};

vector<Edge> vs[MAX];
bool vis[MAX];
void dfs(int root, int dist) {
	vis[root] = true;
	if(dist > max_dist) max_dist = dist;
	
	for(int i=0; i<vs[root].size(); i++) {
		int chl = vs[root][i].nxt;
		if(!vis[chl]) {
			dfs(chl, dist+vs[root][i].dist);
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		long long int sum = 0;
		max_dist = 0;
		memset(vis, false, sizeof(vis));
		for(int i=0; i<=n; i++) vs[i].clear();
		for(int i=1; i<n; i++) {
			int x, y;
			long long int d;
			scanf("%d %d %lld", &x, &y, &d);
			Edge e1(x, d), e2(y, d);
			vs[x].push_back(e2), vs[y].push_back(e1);
			sum += d;
		}
		dfs(1, 0);
		printf("%lld\n", sum*2-max_dist);
	}
	return 0;
}

