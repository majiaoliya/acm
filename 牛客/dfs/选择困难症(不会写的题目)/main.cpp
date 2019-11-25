#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, m, count;
vector<int> likes[8];
bool vis[8];

void dsp() {
	for(int i=1; i<=n; i++) {
		for(int k=0; k<likes[i].size(); k++)
			printf("%d,", likes[i][k]);
		printf("\n");
	}
}

//void dfs(int x, int sum) {
//	if(x == n+1) return ;
//	for(int i=0; i<likes[x].size(); i++) {
//		if(likes[x][i]+sum > m) count ++;
//		dfs(x+1, likes[x][i]+sum);
//	}
//}

void dfs(int x, int sum) {
	if(x == n+1) return ;
	for(int i=0; i<likes[x].size(); i++) {
		if(sum+likes[x][i] > m) count ++;
		dfs(x+1, sum+likes[x][i]);
ss	}
}

int main()
{
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		count = 0;
		for(int i=1; i<=n; i++) {
			int t;
			scanf("%d", &t);
			likes[i].clear();
			for( ; t--; ) {
				int x;
				scanf("%d", &x);
				likes[i].push_back(x);
			}
		}
		for(int i=1; i<=n; i++) {
			dfs(1, 0);
		}
		printf("%d %d\n", m, count);
	}
	
	return 0;
}

