#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#pragma GCC optimize(2)
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <queue>
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * n个数,滑动窗口大小K,每滑动一格求一次最大最小值
 * 用堆维护,每次查之前先把下标不在窗口内的pop掉
 */

ll n, m;
struct Node {
	ll id, val;
	Node(ll _id=0, ll _val=0) : id(_id), val(_val) { }
	bool operator < (const Node& node) const { return val < node.val; }
	bool operator > (const Node& node) const { return val > node.val; }
} ;

int main() {
#ifdef debug
//	freopen("/home/majiao/下载/testdata(9).in", "r", stdin);
//	freopen("out", "w", stdout);
	clock_t stime = clock();
#endif
//	scanf("%lld %lld ", &n, &m);
	read(n);
	read(m);
	priority_queue<Node> q;
	priority_queue<Node, vector<Node>, greater<Node> > q2;
	vector<ll> ans1, ans2;
	for(ll i=1, x; i<=n; i++) {
//		scanf("%lld ", &x);
		read(x);
		q.push(Node(i, x));
		q2.push(Node(i, x));
		while(q.top().id <= i-m) q.pop(); //pop掉所有不在窗口内的
		while(q2.top().id <= i-m) q2.pop();
		if(i >= m) {
			ans1.push_back(q.top().val);
			ans2.push_back(q2.top().val);
		}
	}
	//forvec(ans1);
	//forvec(ans2);
	for(int i=0; i<ans2.size(); i++) {
		if(i) printf(" ");
		printf("%lld", ans2[i]);
	}
	printf("\n");
	for(int i=0; i<ans1.size(); i++) {
		if(i) printf(" ");
		printf("%lld", ans1[i]);
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


