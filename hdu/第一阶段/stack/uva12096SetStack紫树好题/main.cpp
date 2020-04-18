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

int Q, n;
char buf[32];

typedef set<int> Set;
map<Set, int> mp;
map<int, Set> mp2;
int tot;

int ID(Set& seta) {
	int& rx = mp[seta];
	if(!rx) rx = ++tot, mp2[tot] = seta;
	return rx;
}

void union_ab(Set& a, Set& b, Set& c) {
	for(auto it : a) c.insert(it);
	for(auto it : b) c.insert(it);
}

void inter(Set& a, Set& b, Set& c) {
	auto ita = a.begin(), itb = b.begin();
	while(ita != a.end() && itb != b.end()) {
		if(*ita == *itb) c.insert(*ita), ita ++, itb ++;
		else {
			if(*ita < *itb) ita ++;
			else itb ++;
		}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	scanf("%d ", &Q);
	while(Q--) {
		mp.clear();
		mp2.clear();
		stack<int> stk;
		scanf("%d ", &n);
		tot = 0;
		while(n--) {
			scanf("%s ", buf);
			if(buf[0] == 'P') { //push
				Set a;
				stk.push(ID(a));
			} else if(buf[0] == 'D') {
				stk.push(stk.top());
			} else {
				Set a, b, c;
				a = mp2[stk.top()]; stk.pop();
				b = mp2[stk.top()]; stk.pop();
				if(buf[0] == 'U') {
					union_ab(a, b, c);
				} else if(buf[0] == 'I') {
					inter(a, b, c);
				} else if(buf[0] == 'A') {
					c = b;
					c.insert(ID(a));
//					for(auto it : a) c.insert(it);
				}
				stk.push(ID(c));
			}
			printf("%d\n", (int) mp2[stk.top()].size());
		}
		printf("***\n");
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


