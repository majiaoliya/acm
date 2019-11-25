
/**
 * L3_003 
 */
#include <iostream>
#include <vector>
#define MAXN 1005

using namespace std;

int n;
int vis[MAXN]; //兴趣是否被访问过
int pre[MAXN], sum[MAXN]; // sum[]每个集合的节点个数
vector<int> vs[MAXN]; //关注第i个兴趣的人的列表

void init(int n) {
	for(int i=1; i<=n; i++) 
		vis[i] = false, vs[i].clear(), pre[i] = -1, sum[i] = 1; 
}

int find_root(int x) {
	int ret = x;
	while(pre[ret]!=-1) 
		ret = pre[ret];
	if(ret != x)
		pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int root_x = find_root(x);
	int root_y = find_root(y);
	if(root_x != root_y) {
		sum[root_x] += sum[root_y];
		pre[root_y] = root_x;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	init(n);
	for(int i=1; i<=n; i++) {
		int t, x;
		scanf("%d:", &t);
		for( ; t--; ) {
			scanf("%d", &x);
			vs[x].push_back(i);
			if(vs[x].size()>1) {
				union_xy(vs[x][0], vs[x][vs[x].size()-1]);
			}
		}
	}
	
	vector<int> rs;
	for(int i=1; i<=n; i++) {
		if(pre[i] == -1) {
			vector<int>::iterator it = lower_bound(rs.begin(), rs.end(), sum[i]);
			rs.insert(it, sum[i]);
		}
	}
	printf("%d\n", rs.size());
	for(int i=rs.size()-1, c=0; i>=0; i--) {
		if(c++) printf(" ");
		printf("%d", rs[i]);
	}
	printf("\n");
	return 0;
}
