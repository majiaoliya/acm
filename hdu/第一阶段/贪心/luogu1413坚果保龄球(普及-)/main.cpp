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

/**
 * 植物大战僵尸有6行60列, 僵尸第j秒出现在第i行的60列, 
 * 坚果保龄球会从第一列滚到最后一列 并清除这一行上的所有僵尸
 * 玩家可以挑任意时间在第一列放任意多个坚果保龄球
 * 给定所有僵尸的出现时间 求最小放置坚果的个数
 * 
 * 思路 : 关键点是枚举所有出现的时间 然后瞎模拟即可
 */

int n, m, ans, row, tim;
typedef pair<int,int> pii;
pii arr[MAXN];

queue<int> mtx[MAXN];

#define fst(x) (mtx[x].empty() ? -1 : mtx[x].front())

inline void cls(int id) {
	while(!mtx[id].empty()) mtx[id].pop();
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	set<int> seta;
	for(int i=1; i<=n; i++) {
		scanf("%d %d ", &arr[i].second, &arr[i].first);
		seta.insert(arr[i].first);
	}
	sort(arr+1, arr+1+n);
	seta.insert(0x3f3f3f3f); //放一个无穷时间在最后面
	int nowtime, i = 1;
	for(auto it : seta) {
		nowtime = it;
		for(int k=1; k<=6; k++) { //扫每一行的第一个,
								  //如果fst于当前时间的差超出60就放一个坚果
			if(-1==fst(k) || nowtime-fst(k) < 60) continue ;
			cls(k); //清除该行
			ans ++;
		}
		while(i<=n && arr[i].first==nowtime)
			mtx[arr[i].second].push(arr[i].first), i ++;
	}
	printf("%d\n", ans);


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


