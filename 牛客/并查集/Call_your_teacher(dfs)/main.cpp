
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 55
using namespace std;
int n, m;
bool is_find = false; 

vector<int> vs[MAX];
bool vis[MAX];

void dfs(int root) {
	if(is_find) return;
	vis[root] = true;
	if(root == n) {
		is_find = true;
		return ;
	}
	for(int i=0; i<vs[root].size(); i++) {
		dfs(vs[root][i]);
	}
}

void dsp() {
	for(int i=1; i<=n; i++) {
		printf("%d:", i);
		for(int k=0; k<vs[i].size(); k++) {
			printf("->%d", vs[i][k]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		is_find = false;
		memset(vis, false, sizeof(vis));
		for(int i=0; i<n; i++) vs[i].clear();
		for(int i=0; i<m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			vs[x].push_back(y);
		}
		//dsp();
		dfs(1);
		printf("%s\n", is_find ? "Yes" : "No");
	}
	
	return 0;
}

