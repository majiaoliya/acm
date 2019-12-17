#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100050
#include <map>
#define ll long long int
#define ld long double
#define QAQ (0)

using namespace std;

int n, m, T, vis[MAXN];
double esp = 0.000000001;
struct Node {
	int x, y;
	double w;
	bool operator < (const Node& node) const { return w > node.w; }
} arr[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	/**
	 * 英雄开始血量为m, 共有n只怪物第i只怪物伤害ai,打死第i只可以回血bi
	 * 问英雄是否可以打完所有怪物(打的过程中英雄血量必须大于0)
	 * 
	 * 贪心即可 优先贪性价比高的 性价比=拿到的钱 / 扣掉的血
	 * 
	 * 优先打价值最大的怪物,价值 = 拿到的钱 - 扣掉的血 (错的)
	 * 优先打价值最大的怪物,价值 = 拿到的钱 / 扣掉的血
	 */
	scanf("%d ", &T);
	while(T--) {
		scanf("%d %d ", &n, &m);
		for(int i=1; i<=n; i++) {
			scanf("%d %d ", &arr[i].x, &arr[i].y);
			arr[i].w = arr[i].y/(double)arr[i].x;
		}
		sort(arr+1, arr+1+n);
		double now = m;
		bool ok = true;
		for(int i=1; i<=n; i++) {
			if(now-arr[i].x < esp) {
				ok = false;
				break;
			}
			now -= arr[i].x;
			now += arr[i].y;
		}
		printf("%s\n", ok ? "Yes" : "No");
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



