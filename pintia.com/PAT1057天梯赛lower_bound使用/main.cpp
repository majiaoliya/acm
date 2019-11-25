#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

int main() {
	freopen("test", "r", stdin);
	
	int m;
	scanf("%d", &m);
	stack<int> stk;
	vector<int> arr;
	for( ; m--; ) {
		char buf[32];
		scanf("%s", buf);
		if(buf[1] == 'o') { //pop
			if(stk.empty()) printf("Invalid\n");
			else {
				printf("%d\n", stk.top());
				vector<int>::iterator mid = lower_bound(arr.begin(), arr.end(), stk.top());
				arr.erase(mid);
				stk.pop();
			}
		} else if(buf[1] == 'e') { //peek median
			if(stk.empty()) printf("Invalid\n");
			else {
				if(arr.size()%2 == 0) //偶数 
					printf("%d\n", arr[(arr.size()-1)/2]);
				else 
					printf("%d\n", arr[(arr.size())/2]);
			}
		} else if(buf[1] == 'u') { //push
			int x;
			scanf("%d", &x);
			stk.push(x);
			vector<int>::iterator mid = lower_bound(arr.begin(), arr.end(), x);
			arr.insert(mid, x);
		}
	}
	
	return 0;
}


