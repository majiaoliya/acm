/**
Illyasviel："来玩游戏吧！"

Star-dust："好啊！"

有一个 nnn 个点 mmm 条边无环的无向图，Illyasviel 和 Star-dust 轮流加边。可以在点 xxx 和点 yyy 之间加一条边当且仅当点 xxx 与点 yyy 不连通。轮到谁无法操作就对方获胜。两人都是聪明绝顶的，Illyasviel先手。你需要做的是输出"Illyasviel"或"Star-dust"（不包含双引号），代表谁必胜。

注 1：点 xxx 和点 yyy 连通，当且仅当存在某 kkk 个点 a1,a2,…,aka_1, a_2, \ldots, a_ka1​,a2​,…,ak​ 满足 a1=x,ak=ya_1 = x, a_k = ya1​=x,ak​=y 且对于所有的 jjj (1<j≤k1 < j \le k1<j≤k) 都有 aj−1a_{j-1}aj−1​ 和 aja_jaj​ 之间存在一条边。

注 2：一个无向图是无环的，当且仅当此图不存在环。图上的相异 kkk (k≥3k \ge 3k≥3) 个点  a1,a2,…,aka_1, a_2, \ldots, a_ka1​,a2​,…,ak​ 称作环，当且仅当对于所有 jjj (1<j≤k1 < j \le k1<j≤k)  aj−1a_{j-1}aj−1​ 和 aja_jaj​ 之间存在一条边且 a1a_1a1​ 和 aka_kak​ 间也存在一条边。
*/

/**
	给一个图, 要求两个人把图连成树, 连最后一条边的人赢 树n-1条边
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m;

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		for(int i=0, x, y; i<m; i++)
			scanf("%d %d", &x, &y);
		int temp = n-1 - m;
		printf("%s\n", temp%2 ? "Illyasviel" : "Star-dust");
	}
	return 0;
}





























