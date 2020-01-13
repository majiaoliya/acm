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
 * 不知道是不是可以用对顶堆乱搞一下(看错题,中间数不是中位数)
 * 用两个队列a,b维护 保持a.back()一定是中间数即可
 */

int n, m, x;
deque<int> qa, qb;

inline void check() {
	if(qb.size() > qa.size()) {
		qa.push_back(qb.front());
		qb.pop_front();
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	char op[16];
	for(int i=1; i<=n; i++) {
		scanf("%s ", op);
		if(op[0] == 'D') {
			if(op[2] == 'Q') { //deque
				if(qa.empty()) printf("Empty Queue\n");
				else {
					printf("%d\n", qa.front());
					qa.pop_front();
					check();
				}
			} else { //deletemid
				if(qa.empty()) printf("Empty Queue\n");
				else {
					printf("%d\n", qa.back());
					qa.pop_back();
					check();
				}
			}
		} else { //enque
			scanf("%d ", &x);
			if((int)qa.size()+(int)qb.size() >= m) printf("Full Queue\n");
			else { //维护qa的back()一定是中间数即可
				qb.push_back(x);
				check();
			}
		}
	}
	while(!qb.empty()) { qa.push_back(qb.front()); qb.pop_front(); }
	for(int i=0; !qa.empty(); qa.pop_front(), i++) {
		printf("%s%d", !i ? "" : " ", qa.front());
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


