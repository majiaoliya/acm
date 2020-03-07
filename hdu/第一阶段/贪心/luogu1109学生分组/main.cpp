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
#include <math.h>
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define PARSE(x) ((x>='a' && x<='z') ? x-'a' : x-'A')
#define QAQ (0)

using namespace std;

template <typename T>
T abs(T val) { val > 0 ? val : -val; }

/**
 * 给定每个班的下界上界(L,R), n个班, 每个班初始人数a[i],
 * 操作 : 从某个班掉一个人到另一个班 即:a[i]--, a[j]++
 * 问最少要操作多少次
 * 
 * 思路: 先判断sum是否在[n*L, n*R]之间, 不在输出-1
 *       对所有班计算调进来的sum_in, 调出去的sum_out
 *       max(sum_in, sum_out)就是答案
 */

int n, m, arr[MAXN], L, R, sum;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) scanf("%d ", arr+i), sum+=arr[i];
	scanf("%d %d ", &L, &R);
	if(L*n>sum || R*n<sum) {
	   	printf("-1\n"); return 0;
   	}
	sort(arr+1, arr+1+n);
	int ans1 = 0, ans2 = 0;
	for(int i=n; i>=1; i--)
		if(arr[i] > R) ans1 += arr[i]-R;
		else if(arr[i] < L) ans2 += L-arr[i];
	printf("%d\n", max(ans1, ans2));




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



