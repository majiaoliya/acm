#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAXN 10005

using namespace std;

int n, ml = 0, root_id;
int pre[MAXN], max_level[MAXN];
bool vis[MAXN];

vector<int> rs[MAXN];
vector<int> tree[MAXN];

void init() {
	for(int i=1; i<=n; i++)
		pre[i] = -1;
}

int find_root(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(x != ret)
		pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int rx = find_root(x), ry = find_root(y);
	if(rx != ry) pre[ry] = rx;
}

void dfs(int x, int l) {
	if(vis[x]) return ;
	max_level[root_id] = max_level[root_id] > l ? max_level[root_id] : l;
	if(l > ml) {
		ml = l;
	}
	vis[x] = true;
	for(int i=0; i<tree[x].size(); i++) {
		dfs(tree[x][i], l+1);
	}
}

int main()
{
    freopen("test", "r", stdin);
   	
   	scanf("%d", &n);
   	init();
   	for(int i=1; i<n; i++) {
   		int x, y;
   		scanf("%d %d", &x, &y);
   		union_xy(x, y);
   		tree[x].push_back(y);
   		tree[y].push_back(x);
   	}
   	
   	int count = 0;
   	for(int i=1; i<=n; i++) 
   		if(pre[i] == -1) count ++;
   	if(count != 1) printf("Error: %d components\n", count);
   	else {
   		for(int i=1; i<=n; i++) {
   			memset(vis, false, n+5);
   			root_id = i, ml = 0;
   			dfs(i, 1);
   		}
   		for(int i=1; i<=n; i++)
   			if(max_level[i] == ml) printf("%d\n", i);
   	}
    return 0;
}


