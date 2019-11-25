
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAXN 100005
using namespace std;

int t, n, m, pre[MAXN];
bool vis[MAXN];

struct Edge {
	int from, to, dist;
} arr[1000005];

bool cmp(Edge& x, Edge& y) { return x.dist < y.dist; }

vector<int> tree[MAXN];

void init(int n) {
	for(int i=1; i<=n; i++)
		pre[i]=-1, tree[i].clear(), vis[i]=false;
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry)
		pre[ry] = rx;
}

void disp(int n) {
	for(int i=1; i<=n; i++) {
		printf("%d:", i);
		for(int k=0; k<tree[i].size(); k++)
			printf("->%d ", tree[i][k]);
		printf("\n");
	}
}

int krs() {
	sort(arr+1, arr+m+1, cmp);
	for(int i=1; i<=m; i++)
		printf("%d\t", arr[i].dist);
	printf("\n");
	int cnt = 1, rs = 0;
	for(int i=1; cnt<n && i<=m; i++) {
		int x = arr[i].from, y = arr[i].to;
		if(fa(x) == fa(y)) continue;
		union_xy(x, y);
		rs += arr[i].dist;
		cnt ++;
		printf("[%d %d %d]\n", i, x, y);
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	printf("dist: %d\n", rs);
	return rs;
}

void dfs(int x) {
	if(vis[x]) return;
	vis[x] = true;
	for(int i=0; i<tree[x].size(); i++) {
		int chl = tree[x][i];
		if(vis[chl]) continue;
		dfs(chl);
	}
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		init(n);
		for(int i=1; i<=m; i++) 
			scanf("%d %d %d", &arr[i].from, &arr[i].to, &arr[i].dist);
		krs();
		disp(n);
	}
	return 0;
}



