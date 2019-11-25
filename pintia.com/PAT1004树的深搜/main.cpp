#include <iostream>
#include <vector>
#define MAXN 105
using namespace std;

int n, m, tmax;
//bool have_par[MAXN]; //01是root 这里不用自己找根了

vector<int> vs[MAXN];
int level[MAXN];

void dfs(int root, int lev) {
	if(lev > tmax) tmax = lev;
	if(vs[root].empty()) 
		level[lev] ++;
	else 
		for(int i=0; i<vs[root].size(); i++) 
			dfs(vs[root][i], lev+1);
}

void dsp() {
	for(int k=1; k<=n; k++) {
		printf("%d:", k);
		for(int i=0; i<vs[k].size(); i++) {
			printf("->%d", vs[k][i]);
		}
		printf("\n");
	}
}

int main() {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++) {
		int par, t;
		scanf("%d %d", &par, &t);
		for(int k=1; k<=t; k++) {
			int x;
			scanf("%d", &x);
			vs[par].push_back(x);
		}
	}
//	dsp();
	dfs(1, 0);
	for(int i=0, c=0; i<=tmax; i++) {
		if(c++) printf(" ");
		printf("%d", level[i]);
	}
	return 0;
}
