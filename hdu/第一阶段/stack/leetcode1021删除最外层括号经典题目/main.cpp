#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)2e5)
#include <map>
#include <stack>
#include <queue>
#include <unordered_set>
#define ll long long int

using namespace std;

int m, arr[MAXN], rig, minx[MAXN], mrig;
char tmp[MAXN];

class Solution {
public:
    string removeOuterParentheses(string s) {
		stack<char> stk;
		memset(tmp, false, sizeof(tmp));
		rig = 0;
		string ans;
		vector<pair<int,int> > vec;
		for(auto x : s) {
			if(x == '(') {
				stk.push(x);
				if(stk.size() == 1) continue ;
			} else {
				stk.pop();
			}
			if(stk.size()) ans.push_back(x);
		}
		return ans;
    }
};

#ifdef debug
int main() {
	string str = "(()())(())";
	Solution s;
	cout << s.removeOuterParentheses(str) << endl;

	return 0;
}
#endif 


