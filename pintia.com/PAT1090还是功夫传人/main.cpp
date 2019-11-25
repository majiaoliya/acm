#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 10005
using namespace std;

int n, root_id, cnt;
double P, bfb, cur_max;

vector<int> G[MAXN];

void dsp() {
	for(int i=0; i<n; i++) {
		printf("%d:", i);
		for(int k=0; k<G[i].size(); k++) {
			printf("->%d", G[i][k]);
		}
		printf("\n");
	}
}

void dfs(int x, double val) {
	if(G[x].empty()) { //叶子节点
		if(val > cur_max) {
			cur_max = val;
			cnt = 1;
		} else if(val == cur_max) {
			cnt ++;
		}
	} else {
		for(int i=0; i<G[x].size(); i++) {
			int chl = G[x][i];
			dfs(chl, (val+val*bfb));
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %lf %lf", &n, &P, &bfb);
	for(int i=0; i<n; i++) {
		int x;
		scanf("%d", &x);
		if(x == -1) root_id = i;
		else G[x].push_back(i);
	}
//	dsp();
	bfb *= .01;
	dfs(root_id, P);
	printf("%.2lf %d\n", cur_max, cnt);
	return 0;
}

