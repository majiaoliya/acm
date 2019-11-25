#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <map>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n;
int pre[MAXN];

void init() {
	for(int i=0; i<=n+3; i++)
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
	int rx = find_root(x), ry = find_root(y);
	if(rx != ry)
		pre[ry] = rx;
}

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d", &n);
	char buf[4];
	init();
	for( ; EOF != scanf("%s", buf); ) {
		if(buf[0] == 'S') {
			int cnt = 0;
			for(int i=1; i<=n; i++) {
				if(pre[i] == -1) cnt ++;
			}
			if(cnt==1) printf("The network is connected.\n");
			else printf("There are %d components.\n", cnt);
			break;
		}
		int x, y;
		scanf("%d %d", &x, &y);
		if(buf[0] == 'C') {
			if(find_root(x) == find_root(y))
				printf("yes\n");
			else
				printf("no\n");
		} else if(buf[0] == 'I') {
			union_xy(x, y);
		}
	}
	
	return 0;
}

