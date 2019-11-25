#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n, stk[MAXN], size;
int tree[MAXN<<2], llen[MAXN<<2], rlen[MAXN<<2], len[MAXN<<2];

void build(int x, int lef, int rig) {
	
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		size = 0;
		for( ; m--; ) {
			char cmd[4];
			scanf("%s", cmd);
			if(cmd[0] == 'D') {
				scanf("%d", stk[++size]);
			} else if(cmd[0] == 'Q') {
				
			} else {
				
			}
		}
	}
	return 0;
}
