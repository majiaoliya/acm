#define debug
#define submit
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
#define MAXN (4096)
#define INF (0x3f3f3f3f)
#define ll long long int
#define PARSE(x) (x>='a' && x<='z' ? x : x+('a'-'A'))
#define QAQ (0)

using namespace std;
/**
 * 题目 : 假设有n（n<=20）个任务由k（k<=20）个可并行工作的机器完成。
	 完成任务i需要的时间为ti。 试设计一个算法，
	 对任意给定的整数n和k，以及完成任务i 需要的时间为ti ，i=1~n。
	 计算完成这n个任务的最佳调度，使得完成全部任务的时间最早。 

   即: 给定一个大小为n的可重集合, 把他分成m个子可重集合,
      对每个子集合求sum, 最小化最大sum

   思路: 二分答案+背包 ????? 好像是错的 ??? 和网上代码对拍不一致
  		二分猜最长时间T 
		问题变成了 '判定k个机器是否可以在T时间内完成所有任务"
		判定方法 尽可能跑满每个机器(对每个机器求01背包 背包容量为T)
 */

int n, m, arr[MAXN], vis[MAXN];
bool path[MAXN][MAXN];
int w[MAXN] = { 0 }, dp[MAXN];

bool check(int mid) { //判断是否可以在限定时间T=mid内完成所有任务
	int cnt = 0; //统计完成了多少个任务
	for(int i=1; i<=n; i++) {
		if(arr[i] > mid) return false; //其中一个无法完成
		w[i] = arr[i];
	}
	int tm = m, tn = n;
	while(tn && tm--) { //求k次背包
		memset(dp, false, sizeof(dp));
		memset(path, false, sizeof(path));
		memset(vis, false, sizeof(vis));
		for(int i=1; i<=tn; i++) 
			for(int k=mid; k>=1; k--) 
				if(k>=w[i] && dp[k]<dp[k-w[i]]+w[i]) {
					path[i][k] = true;
					dp[k] = dp[k-w[i]] + w[i];
				}
		int i = tn, j = mid;
		while(i && j) {
			if(path[i][j]) {
				vis[i] = true;
				cnt ++;
#ifdef debug2
				printf("[%d]", w[i]);
#endif
				j -= w[i];
			}
			i --;
		}
		for(i=1, j=0; i<=tn; i++) {
			if(vis[i]) continue ;
			w[++j] = w[i];
		}
#ifdef debug2
		printf("\n");
#endif
		tn = j;
	}
#ifdef debug2
	printf("mid:%d cnt:%d\n", mid, cnt);
#endif
	return cnt >= n; //是否能完成N个任务
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m)) {

		int lef = 0, rig = 0, mid = 0, ans = 0, tmax = 0;
		for(int i=1; i<=n; i++) 
			scanf("%d ", arr+i), rig += arr[i], tmax = max(tmax, arr[i]);
		if(m <= 0) { printf("1000000\n"); continue ; }
		if(m >= n) { //机器数量超过任务数量直接去最大值
			printf("%d\n", tmax);
			continue ;
		}
		while(lef <= rig) {
			mid = (lef + rig) >> 1;
			if(check(mid)) ans = mid, rig = mid - 1;
			else lef = mid + 1;	
		}
		printf("%d\n", lef);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

//WA点

//正确答案154
//19 6
//38 65 35 79 34 40 32 45 67 87 56 22 61 57 48 52 20 52 32 

//正确答案128
//18 8
//72 21 90 84 61 93 33 44 86 44 81 46 78 2 32 24 59 30 

