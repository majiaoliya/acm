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

int m;
typedef pair<int, string> pis;
priority_queue<pis, vector<pis>, greater<pis> > q;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &m);
	while(m--) {
		char op[64];
		scanf("%s ", op);
		if(op[0] == 'P') {
			char msg[64];
			int w;
			scanf("%s %d ", msg, &w);
			q.push({w, msg});
		} else {
			if(q.empty()) { printf("EMPTY QUEUE!\n"); continue ; }
			auto x = q.top(); q.pop();
			printf("%s\n", x.second.data());
		}
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


