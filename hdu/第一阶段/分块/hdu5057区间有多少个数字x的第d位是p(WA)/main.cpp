#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#define MAXN 1000005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int T, n, m, arr[MAXN];
ll block, l[MAXN], r[MAXN], belong[MAXN], num;
int mi[15] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
struct Block {
	int mtx[11][11];
} blk[MAXN/20];

void build() {
	block = sqrt(n);
	num = n/block;
	if(n%block) num ++;
	for(int i=1; i<=num; i++)
		l[i] = (i-1)*block+1, r[i] = i*block;
	r[num] = n;
}

void update(int i, int val) {
	for(int k=1; k<=10; k++) {
		blk[belong[i]].mtx[k][arr[i]%10] --;
		arr[i] /= 10;
	}
	arr[i] = val;
	for(int k=1; k<=10; k++) {
		blk[belong[i]].mtx[k][val%10] ++;
		val /= 10;
	}
}

int query(int x, int y, int d, int p) {
	int ans = 0;
	if(belong[x] == belong[y]) {
		for(int i=x; i<=y; i++)
			if(arr[i]/mi[d]%10 == y) ans ++;
		return ans;
	}
	for(int i=x; i<=r[belong[x]]; i++) if(arr[i]/mi[d]%10 == p) ans ++;
	for(int i=belong[x]+1; i<belong[y]; i++) ans += blk[i].mtx[d][p];
	for(int i=l[belong[y]]; i<=y; i++) if(arr[i]/mi[d]%10 == p) ans ++;
	return ans;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &T);
	while(T--) {
		memset(blk, false, sizeof(blk));
		memset(arr, false, sizeof(arr));
		scanf("%d %d ", &n, &m);
		build();
		for(int i=1; i<=n; i++) {
			scanf("%d ", arr+i);
			belong[i] = (i-1)/block+1;
			int tmp = arr[i];
			for(int k=1; k<=10; k++) {
				blk[belong[i]].mtx[k][tmp%10] ++;
				tmp /= 10;
			}
		}
		while(m--) {
			char cmd;
			scanf("%c ", &cmd);
			if(cmd == 'Q') {
				int x, y, d, p;
				scanf("%d %d %d %d ", &x, &y, &d, &p);
				int ans = query(x, y, d, p);
				printf("%d\n", ans);
			} else {
				int idx, val;
				scanf("%d %d ", &idx, &val);
				update(idx, val);
			}
		}
	}




#ifdef debug2
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

