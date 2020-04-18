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
#define MAXN ((int)2e5)
#define ll long long int
#define QAQ (0)

using namespace std;

int Q, n, m, a[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &Q);
	while(Q--) {
		scanf("%d %d ", &n, &m);
		priority_queue<int> q;
		deque<pair<int,int> > deq;
		for(int i=0; i<n; i++) {
			scanf("%d ", a+i);
			q.push(a[i]);
			deq.push_back({a[i], i});
		}
		int timer = 0;
		while(true) {
			auto fst = deq.front();
//			printf("%d %d\n", fst.first, fst.second);
			if(fst.first == q.top()) {
				timer ++;
				if(fst.second == m) {
					printf("%d\n", timer);
					break;
				}
				deq.pop_front();
				q.pop();
			} else {
				deq.push_back(fst);
				deq.pop_front();
			}
		}
	}
	return 0;
}


