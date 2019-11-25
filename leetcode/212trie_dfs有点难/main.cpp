#include <stack>
#include <string.h>
#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN (int)(1e6)
#define debug

struct Node {
	Node* next[26];
	bool isEnd;
	Node() : isEnd(false) { memset(next, false, sizeof(next)); }
	~Node() { for(int i=0; i<26; i++) delete next[i]; }
} *root;
typedef vector<vector<bool> > Vis;
typedef vector<vector<char> > Mtx;
int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

class Solution {
public:
	int row, col;
	char tstr[2048];
	Solution() {
		delete root;
		root = new Node();
	}
	void insert(string& str) {
		Node* now = root;
		for(int i=0, n=str.length(), pos; i<n; i++) {
			pos = str[i] - 'a';
			if(!(now->next[pos])) now->next[pos] = new Node();
			now = now->next[pos];
		}
		now->isEnd = true;
	}

	bool search(string& str) {
		Node* now = root;
		for(int i=0, n=str.length(), pos; i<n; i++) {
			pos = str[i] - 'a';
			if(!(now->next[pos])) return false;
			now = now->next[pos];
		}
		return now->isEnd;
	}

    vector<string> findWords(vector<vector<char> >& mtx, vector<string>& str) {
		vector<string> ret;
//		set<string> seta;
		row = mtx.size(), col = mtx[0].size();
		for(string x : str) insert(x);
		for(int i=0; i<row; i++)
			for(int k=0; k<col; k++) {
				Vis vis(mtx.size(), vector<bool>(mtx[i].size(), false));
				memset(tstr, false, sizeof(tstr));
				dfs(root->next[mtx[i][k]-'a'], mtx, vis, i, k, tstr, ret);
			}
//		sort(ret.begin(), ret.end());
#ifdef debug2
		set<string>::iterator it = seta.begin();
		while(it != seta.end()) {
			ret.push_back(*it);
			it ++;
		}
#endif
		return ret;
    }
	
	void dfs(Node* root, Mtx& mtx, Vis& vis, int r, int c, string str, vector<string>& ret) {
		if(!root) return ;
		str += mtx[r][c];
		if(root->isEnd) root->isEnd=false, ret.push_back(str);
		vis[r][c] = true;
		for(int i=0; i<4; i++) {
			int nr = r+dr[i], nc = c+dc[i];
			if(nr>=0 && nr<row && nc>=0 && nc<col && !vis[nr][nc]) {
				vis[nr][nc] = true;
				dfs(root->next[mtx[nr][nc]-'a'], mtx, vis, nr, nc, str, ret);
				vis[nr][nc] = false;
			}
		}
		vis[r][c] = true;
	}
};

#ifdef debug
int main(void) {
	vector<string> words = {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"};
	vector<vector<char> > mtx = {
		{'a','b','c'},
	  	{'a','e','d'},
	  	{'a','f','g'}
	};
	Solution s;
	vector<string> rs = s.findWords(mtx, words);
	sort(rs.begin(), rs.end());
	for(string str : rs)
		cout << str << endl;
	return 0;
}
#endif
