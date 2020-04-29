#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

#define lowbit(x) (x&(-x))

int n, tree[MAXN<<2], Q;

void update(int i, int val) {
	while(i <= n) {
		tree[i] += val;
		i += lowbit(i);
	}
}

int query(int i) { //求[1,i-1]的前缀和
	int ret = 0;
	while(i > 0) {
		ret += tree[i];
		i -= lowbit(i);
	}
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &Q);
	int cas = 0;
	while(Q--) {
		printf("Case %d:\n", ++cas);
		memset(tree, 0, sizeof(tree));
		scanf("%d ", &n);
		for(int i=1; i<=n; i++) {
			int x;
			scanf("%d ", &x);
			update(i, x);
		}
		char cmd[16];
		while(~scanf("%s ", cmd) && cmd[0]!='E') {
			if(cmd[0] == 'A') {
				int idx, val;
				scanf("%d %d ", &idx, &val);
				update(idx, val);
			} else if(cmd[0] == 'S'){
				int idx, val;
				scanf("%d %d ", &idx, &val);
				update(idx, -val);
			} else {
				int L, R;
				scanf("%d %d ", &L, &R);
				printf("%d\n", query(R)-query(L-1));
			}
		}
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


