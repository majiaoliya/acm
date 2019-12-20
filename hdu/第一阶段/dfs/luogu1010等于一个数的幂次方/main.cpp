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

/**
 * 思路很简单的dfs把now的每一位都dfs一遍即可
 */

int n;

void printf(int x) {
	stack<int> stk;
	while(x) {
		stk.push(x & 1);
		x >>= 1;
	}
	while(!stk.empty()) {
		printf("%d", stk.top()); stk.pop();
	}
	printf("\n");
}

string dfs(int now) {
	if(now == 0) return "0";
	if(now == 1) return "";
	string ret = "";
	int tmp = now, cnt = 0;
	vector<int> vec;
	while(tmp) { //取每一位二进制为1的位
		if(tmp & 1) vec.push_back(cnt);
		tmp >>= 1;
		cnt ++;
	}
	for(int i=vec.size()-1; i>=0; i--) { //重大到小
		string x = dfs(vec[i]);
		if(x.empty()) ret += "2";
		else ret += "2(" + x + ")";
		if(i) ret += "+";
	}
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d ", &n)) {
		string ans = dfs(n);
		cout << ans;
	}






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


