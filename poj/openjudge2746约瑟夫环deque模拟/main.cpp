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
 * 使用deqye模拟约瑟夫环
 */
int n, m;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m) && (n+m)) {
		deque<int> q;
		for(int i=1; i<=n; i++) q.push_back(i);
		while(q.size() > 1) {
			int k = m - 1;
			while(k--) {
				q.push_back(q.front());
				q.pop_front();
			}
			q.pop_front();
		}
		printf("%d\n", q.front());
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


