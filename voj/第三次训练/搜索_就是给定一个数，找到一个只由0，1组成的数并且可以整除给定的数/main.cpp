#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define MAXN 105
using namespace std;
//就是给定一个数n(1<=n<=200)，找到一个只由0，1组成的数并且可以整除给定的数m

//typedef unsigned long long ull;
#define ull unsigned long long int

bool ok = false;
int n;
ull rs;
/** dfs
void dfs(int x, ull num) {
	if(x>20) return;
	if(ok) return;
	if(num%n == 0) { ok = true; rs = num; return; }
	dfs(x+1, num*10);
	dfs(x+1, num*10|1);
}
*/

struct Node {
	int step;
	ull num;
};

void bfs() {
	queue<Node> q;
	Node fst;
	fst.step = 1, fst.num = 1;
	q.push(fst);
	while(!q.empty()) {
		Node x = q.front();
		q.pop();
		if(x.num%n == 0) { ok = true; rs = x.num; break; }
		if(x.step > 20) continue;
		Node n1, n2;
		n1.step = n2.step = x.step + 1;
		n1.num = x.num*10, n2.num = x.num*10|1;
		q.push(n1);
		q.push(n2);
	}
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n) && n; ) {
		ok = false;
//		dfs(1, 1);
		bfs();
		if(ok) printf("%llu\n", rs);
	}
	return 0;
}

