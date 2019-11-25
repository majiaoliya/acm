
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 10005

using namespace std;

int n, r;

struct Node {
	int row, col;
} arr[MAXN];

int pre[MAXN];
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

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d %d", &n, &r);
		for(int i=1; i<=n; i++) {
			pre[i] = -1;
		}
		for(int i=1, count=1; i<=n; i++) {
			scanf("%d %d", &arr[i].row, &arr[i].col);
			for(int k=1; k<i; k++) {
				int absr = abs(arr[i].row-arr[k].row);
				int absc = abs(arr[i].col-arr[k].col);
				if(absr<=r || absc<=r) {
					union_xy(i, k);
					break;
				}
			}
		}
		int count = 0;
		for(int i=1; i<=n; i++) {
			if(pre[i] == -1) count ++;
		}
		printf("%d\n", count);
	}
	return 0;
}
