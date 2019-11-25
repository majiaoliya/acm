
#include <iostream>
#include <algorithm>
#define MAX 105
using namespace std;

int n, m;

int pre[100005];

int find_root(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x) 
		pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int root_x = find_root(x);
	int root_y = find_root(y);
	if(root_x != root_y) 
		pre[root_y] = root_x;
}

int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		for(int i=1; i<=n; i++)
			pre[i] = -1;
		for(int i=0; i<m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			union_xy(x, y);
		}
		int count = 0;
		for(int i=1; i<=n; i++) 
			if(pre[i] == -1) count ++;
		printf("%d\n", count-1);
	}
	
	return 0;
}

