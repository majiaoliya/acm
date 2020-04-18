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
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m;
struct Node {
	int dir;
	char str[16];
} a[MAXN];

#define LEF(x) (x==0)
#define RIG(x) (x==1)

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=0; i<n; i++) 
		scanf("%d %s ", &a[i].dir, a[i].str);
	int now = 0;
	while(m--) {
		int K, dir;
		scanf("%d %d ", &dir, &K);
		K %= n;
		//0是向里,1是向外
		if(a[now].dir) dir = !dir; //对于向外的人要把左右调换
		if(RIG(dir)) { //右加左减
			now = (now+K) % n;
		} else {
			now = (now+n-K) % n;
		}
	}
	printf("%s\n", a[now].str);









#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


