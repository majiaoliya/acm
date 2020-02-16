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
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 题意: 给定一个数组,对每一个数字a[i]打印[a[1], a[i]]有多少个比a[i]小的数字
 *       即,对每个位置求逆序对个数
 * 思路: 权值线段树, 没有离散化, 
 */

int n, m, idx, val, L, R, sum[MAXN], N = 128;

void push_up(int rt) { sum[rt] = sum[rt<<1] + sum[rt<<1|1]; }

void update(int rt, int lef, int rig) {
	if(lef == rig) { sum[rt] ++; return; }
	int mid = (lef + rig) >> 1;
	if(idx <= mid) update(rt<<1, lef, mid);
	else update(rt<<1|1, mid+1, rig);
	push_up(rt);
}

int query(int rt, int lef, int rig) {
	if(L<=lef && rig<=R) return sum[rt];
	int mid = (lef + rig) >> 1, ret = 0;
	if(L <= mid) ret = query(rt<<1, lef, mid);
	if(mid < R) ret += query(rt<<1|1, mid+1, rig);
	return ret;
}

int cnt[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d ", &val);
		val ++;
		L = 1, R = val;
		idx = R;
		printf("%d ", query(1, 1, N)-cnt[val]);
		update(1, 1, N);
		cnt[val] ++;
	}


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



