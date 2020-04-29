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
#define ull unsigned long long int
#define QAQ (0)

using namespace std;

int n, m, tree[MAXN<<2];
ll color[MAXN<<2], lazy[MAXN<<2]; //用longlong的每一位判断是否有颜色

void push_down(int rt) { //下放懒标记
	lazy[rt<<1] |= lazy[rt];
	lazy[rt<<1|1] |= lazy[rt];
	color[rt<<1] |= lazy[rt];
	color[rt<<1|1] |= lazy[rt];
	lazy[rt] = 0;
}

void push_up(int rt) {
	color[rt] = color[rt<<1] | color[rt<<1|1];
}

void update(int rt, int lef, int rig, int L, int R, int C) {
	if(L<=lef && rig<=R) {
		lazy[rt] |= (1LL<<C);
		color[rt] |= (1LL<<C);
		return ;
	}
	push_down(rt);
	int mid = (lef + rig) >> 1;
	if(L <= mid) update(rt<<1, lef, mid, L, R, C);
	if(mid < R) update(rt<<1|1, mid+1, rig, L, R, C);
	push_up(rt);
}

ll query(int rt, int lef, int rig, int L, int R) {
	if(L<=lef && rig<=R) return color[rt];
	push_down(rt);
	int mid = (lef + rig) >> 1;
	ll ret = 0;
	if(L <= mid) ret |= query(rt<<1, lef, mid, L, R);
	if(mid < R) ret |= query(rt<<1|1, mid+1, rig, L, R);
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m)) {
		memset(lazy, 0, sizeof(lazy));
		memset(color, 0, sizeof(color));
		while(m--) {
			int op, L, R, C;
			scanf("%d ", &op);
			if(op == 1) {
				scanf("%d %d %d ", &L, &R, &C);
				update(1, 1, n, L, R, C);
			} else {
				scanf("%d %d ", &L, &R);
				ull num = query(1, 1, n, L, R);
				int ans = 0;
				while(num) {
					ans += (num & 1);
					num >>= 1;
				}
				printf("%d\n", ans);
			}
		}
	}
	//	forarr(color, 1, n<<2);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



