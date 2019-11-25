#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <stack>
#define MAXN 1000005
using namespace std;

int n;
string s1, s2;
vector<int> v; // 1=in, 2=out;

int main(void) {
	freopen("test", "r", stdin);
	/** 纳闷了 ??
	for( ; EOF != scanf("%d %s %s", &n, s1, s2); ) {
		int s2_idx = 0, ok = true;
		stack<char> stk;
		for(int i=0; i<n; i++) {
			while(!stk.empty() && stk.top() == s2[s2_idx]) {
				s2_idx ++;
				stk.pop();
				v.push_back(2); // out
			}
			stk.push(s1[i]);
			v.push_back(1); // in
		}
		while(!stk.empty() && stk.top() == s2[s2_idx]) {
			s2_idx ++;
			stk.pop();
			v.push_back(2); // out
		}
		if(!stk.empty()) ok = false;
		printf("%s.\n", ok ? "Yes" : "No");
		if(ok) {
			for(int i=0; i<v.size(); i++)
				printf("%s\n", 1==v[i] ? "in" : "out");
		}
		printf("FINISH\n");
	}
	*/
	for( ; cin>> n >> s1 >> s2; ) {
		int idx1 = 0, idx2 = 0;
		stack<char> stk;
		vector<int> v; // 1=in, 2=out
		while(true) {
			if(!stk.empty() && stk.top()==s2[idx2]) {
				v.push_back(2);
				stk.pop();
				idx2 ++;
				continue;
			}
			if(idx1 >= s1.length()) break;
			stk.push(s1[idx1]);
			idx1 ++;
			v.push_back(1);
		}
		if(stk.empty()) {
			printf("Yes.\n");
			for(int i=0; i<v.size(); i++) 
				printf("%s\n", v[i]==1 ? "in":"out");
		} else {
			printf("No.\n");
		}
		printf("FINISH\n");
	}
	return 0;
}





