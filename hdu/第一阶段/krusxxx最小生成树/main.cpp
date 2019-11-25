
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXN 105
using namespace std;

struct Edge {
	long long int start, end, dist;
	Edge() : start(0), end(0), dist(0) { }
};

int n, m, sum;
Edge arr[MAXN*MAXN];
int pre[MAXN];

int cmp(Edge& x, Edge& y) { return x.dist < y.dist; }

void init() {
	sum = 0;
	for(int i=1; i<=n; i++) 
		pre[i] = -1;
}

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

void krs() {
	init(); //初始化并查集的pre[]
	sort(arr+1, arr+1+n, cmp); //按边从小到大排序
	int count = 0;
	for(int i=1; i<=m && count<n-1; i++) {
		if(find_root(arr[i].start)!=find_root(arr[i].end)) {
			sum += arr[i].dist;
			union_xy(arr[i].start, arr[i].end);
			count ++; //数边 n节点树 共有n-1条边
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &m, &n); ) {
		if(m == 0) continue;
		for(int i=1; i<=m; i++) {
			scanf("%lld %lld %lld", &arr[i].start, &arr[i].end, &arr[i].dist);
	//		printf("%d %d %d\n", arr[i].start, arr[i].end, arr[i].dist);
		}
		krs();
//		printf("%d\n", sum);
//		for(int i=1; i<=n; i++)
//			printf("%d,", pre[i]);
		int count = 0;
		for(int i=1; i<=n; i++) 
			if(pre[i] == -1) count ++;
		if(1 == count) 
			printf("%d\n", sum);
		else printf("?\n");
	}
	return 0;
}



