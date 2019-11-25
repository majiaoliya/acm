#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string.h>
#define MAXN 10005
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

string IN, OUT;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	ios::sync_with_stdio(false);
	cin >> IN >> OUT;
	int i=0, k=0, n=IN.length(), m=OUT.length();
	vector<pair<int, int> > ans;
	stack<char> stk;
	while(i<n) {
		if(IN[i] == OUT[k]) {
			i++, k++;
			ans.push_back({1, 2});
			continue ;
		}
		if(!stk.empty() && stk.top()==OUT[k]) {
			ans.push_back({3, 2});
			k++; stk.pop();
			continue ;
		}
		if(i<n && IN[i]!=OUT[k]) {
			ans.push_back({1, 3});
			stk.push(IN[i]);
			i++;
		}
	}
	while(!stk.empty() && k<m && stk.top()==OUT[k]) {
		ans.push_back({3, 2});
		k++, stk.pop();
	}
	if(!stk.empty()) printf("Are you kidding me?\n");
	else {
		for(int i=0; i<ans.size(); i++)
			printf("%d->%d\n", ans[i].first, ans[i].second);
	}

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

