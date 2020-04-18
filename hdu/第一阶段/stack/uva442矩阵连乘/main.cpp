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
	char ch;
	int r, c;
	Node(char _ch=0, int _r=0, int _c=0) : ch(_ch), r(_r), c(_c) { }
};

map<char, Node> mp;

char buf[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) {
		char ch;
		int x, y;
		scanf("%c %d %d ", &ch, &x, &y);
		mp[ch] = Node(ch, x, y);
	}
	while(~scanf("%s ", buf)) {
		if(buf[0] != '(') {
			printf("0\n");
			continue ;
		}
		stack<Node> stk;
		ll sum = 0, error = 0;
		for(int i=0; buf[i]; i++) {
			if(buf[i] == ')') {
				Node B = stk.top(); stk.pop();
				Node A = stk.top(); stk.pop();
				if(B.r == A.c) {
					sum += A.r * (ll)A.c * B.c;
					stk.push({0, A.r, B.c});
				} else {
					error = true;
					break;
				}
				continue ;
			} else if(buf[i]>='A' && buf[i]<='Z') {
				stk.push(mp[buf[i]]);
			}
		}
		if(!error) printf("%lld\n", sum);
		else printf("error\n");
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


