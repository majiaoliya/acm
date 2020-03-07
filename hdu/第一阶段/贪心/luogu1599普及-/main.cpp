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
#include <stack>
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
 * 不放债不借债”，贝西多么希望自己可以遵循这个忠告。她已经和她的N（1 <= N <= 100,000）个朋友有了债务关系，或者借债了，或者放债了。她的N个朋友依次标号为1..N。 结算日终于来临了。她知道，朋友欠她的钱比她欠朋友的钱多。她的朋友们分布在一条直线上，第i头奶牛站的位置距离谷仓i米。贝西打算沿着这条直线行走，从欠她钱的奶牛手里收钱回来，并且还钱给她欠钱的奶牛。 当她沿直线移动的时候，她可以要求任何欠她钱的奶牛还全部的钱。当她有足够的钱可以还清她的某个债，就可以把钱给对应的奶牛还清她的债。奶牛i欠贝西D_i元（-1,000 <= D_i <=1,000; D_i <> 0），负数表示贝西欠奶牛i钱。 贝西从谷仓出发，位置为0，初始贝西没有钱。贝西收回她的所有借债，并且还清她的欠债所需行走的最短距离是多少？注意：她必须在最后一头奶牛所在的位置，完成她的行走。
 * 
 * 一直往前走记下当前位置欠了多少钱,如果搜到的钱大于等于前面欠下的,就立马回去还钱 就是最优策略
 */

int m, n, arr[MAXN], sum, ans, fu;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) scanf("%d ", arr+i);
	stack<int> stk;
	for(int i=1; i<=n; i++) {
		int now = i;
		if(arr[i] < 0) stk.push(i), fu += arr[i];
		else {
			sum += arr[i];
		}
		ans ++;
		while(!stk.empty() && abs(fu)<=sum) {
			int id = stk.top(); stk.pop();
			sum -= abs(arr[id]);
			ans += (now - id) << 1;
			now -= (now - id);
			fu += abs(arr[id]);
//			printf("back : %d %d i:%d\n", id, arr[id], i);
		}
	}
	printf("%d\n", ans);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



