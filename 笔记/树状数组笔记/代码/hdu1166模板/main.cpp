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
#define MAXN (1024)
#define ll long long int
#define QAQ (0)

using namespace std;

#define lowbit(x) (x&(-x))

int n, tree[MAXN][MAXN], Q, mp[MAXN][MAXN];

void update(int i, int k, int x) {
	for( ; i<=n; i+=lowbit(i))
		for(int j=k; j<=n; j+=lowbit(j))
			tree[i][j] += x;
}

int query(int x, int y) {
	int ans = 0;
	for(int i=x; i>0; i-=lowbit(i))
		for(int k=y; k>0; k-=lowbit(k))
			ans += tree[i][k];
	return ans;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	int m;
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++)
		for(int k=1; k<=n; k++) {
			scanf("%d ", &mp[i][k]);
			if(mp[i][k]) update(i, k, 1);
		}
	while(m--) {
		int op;
		scanf("%d ", &op);
		if(op == 1) {
			int x, y;
			scanf("%d %d ", &x, &y);
			if(mp[x][y])
				update(x, y, -1), mp[x][y] = 0;
			else
				update(x, y, 1), mp[x][y] = 1;
		} else {
			int x1, x2, y1, y2;
			scanf("%d %d %d %d ", &x1, &y1, &x2, &y2);
			cout << (query(x2, y2) + query(x1 - 1, y1 - 1) - query(x1 - 1, y2) - query(x2, y1 - 1)) << endl;
			//printf("%d\n",
			//		query(x2, y2)+query(x1-1, y1-1)-query(x1-1, y2)-
			//		query(x1, y2-1));
		}
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


