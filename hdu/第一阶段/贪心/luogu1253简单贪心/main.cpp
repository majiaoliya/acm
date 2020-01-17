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
#define MAXN ((int)2e5+7)
#define ll long long int
#define ld long long double
#define QAQ (0)

using namespace std;

/**
 * 给定查找时间a1,a2,a3.., 查找频率b1,b2,b3..., 贪最小平均查找时间
 * 按a*b从大到小排序即可
 */

int n, m;
struct Node {
	int a, b, id;
	bool operator < (const Node& node) const { return a*b < node.a*node.b; }
} arr[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) 
		scanf("%d %d ", &arr[i].a, &arr[i].b), arr[i].id = i;
	sort(arr+1, arr+1+n);
	for(int i=n; i>0; i--)
		printf("%d ", arr[i].id);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


