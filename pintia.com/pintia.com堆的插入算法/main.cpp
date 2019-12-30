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

//未备份

int n, q, x;
vector<int> vec;

void insert(int x) {
	vec.push_back(x);
	int now = vec.size() - 1;
	while(vec[now] < vec[now>>1]) {
		swap(vec[now], vec[now>>1]);
		now >>= 1;
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	
	scanf("%d %d ", &n, &q);
	vec.push_back(-9999999);
	for(int i=1; i<=n; i++) {
		scanf("%d ", &x);
		insert(x);
	}
	while(q--) {
		scanf("%d ", &x);
		while(x>=1) {
			printf("%d%c", vec[x], x>>1 ? ' ' : '\n');
			x >>= 1;
		}
	}

	






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

