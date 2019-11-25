#include <stack>
#include <string.h>
#include <string>
#include <iostream>
#define debug
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                stk.push(i);
                continue ;
            } else if(s[i] == ')') {
                int lef = stk.top(), rig = i;
				stk.pop();
                revers(s, lef, rig);
            }
        }
        char rs[n+3];
        memset(rs, false, sizeof(rs));
        for(int i=0, k=0; i<n; i++) {
            if(s[i] != '(' && s[i] != ')') rs[k++] = s[i];
        }
        return rs;
    }
    
    void revers(string& s, int lef, int rig) {
        while(lef<rig) {
            swap(s[lef], s[rig]);
            lef ++, rig --;
        }
    }
};


#ifdef debug
int main(void) {
	freopen("test", "r", stdin);
	string str = "a(bcdefghijkl(mno)p)q";
	Solution s;
	cout << s.reverseParentheses(str) << endl;
	return 0;
}
#endif
