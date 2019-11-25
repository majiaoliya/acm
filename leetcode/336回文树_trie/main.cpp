#include <stack>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define MAXN (int)(1e6)
#define debug

typedef vector<vector<int> > vvi;

struct Node {
	int id;
	int next[26];
} tree[MAXN];
int tsize;
class Solution {
public:

	int ansId, level, mlevel;

	void insert(string& str, int id) {
		int now = 0;
		for(int i=0, n =str.length(); i<n; i++) {
			int pos = str[i] - 'a';
			if(!tree[now].next[pos]) tree[now].next[pos] = ++tsize;
			now =  tree[now].next[pos];
		}
		tree[now].id = id;
	}

    string longestWord(vector<string>& v) {
		//for(int i=0, n=v.size(); i<n; i++)
		//	insert(v[i], i);
		//ansId = level = mlevel = 0;
		//dfs(0, 0);
		map<int, set<string> > mp;
		int m = 0;
		for(int i=0; i<(int)v.size(); i++) {
			m = max(m, (int)v[i].length());
			mp[m].insert(v[i]);
		}
		string ret = *mp[m].begin();
		return ret;
    }
	void dfs(int now, int level) {

		for(int i=0; i<26; i++) {
			if(tree[now].next[i]) dfs(tree[now].next[i], level+1);
		}
	}
};

#ifdef debug
int main(void) {
	vector<string> v = { "a","banana","app","appl","ap","apply","apple" };
	Solution s;
	string ret = s.longestWord(v);
	cout << ret << endl;
	return 0;
}
#endif
