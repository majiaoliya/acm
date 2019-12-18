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
 * 用deque来水约瑟夫环问题
 * 把前K-1个循环丢到屁股后头
 */
int n, m;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	deque<int> q;
	for(int i=1; i<=n; i++) q.push_back(i);
	while(!q.empty()) {
		int K = m - 1;
		while(K--) {
			int fst = q.front(); q.pop_front();
			q.push_back(fst);
		}
		printf("%d ", q.front()); q.pop_front();
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


