#include <stack>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#define debug
using namespace std;

#define MAXN (int)(1e6)

struct Node {
	Node* next[26];
	bool isEnd;
	Node() : isEnd(false) { memset(next, false, sizeof(next)); }
	~Node() { 
		for(int i=0; i<26; i++)
			delete next[i];
	}
}*root;

class WordDictionary {
public:
	int pos;
    WordDictionary() {
		delete root;
		root = new Node();
    }
    
	void addWord(string str) {
		Node* now = root;
		for(int i=0, n=str.length(), pos; i<n; i++) {
			pos = str[i] - 'a';
			if(!(now->next[pos])) now->next[pos] = new Node();
			now = now->next[pos];
		}
		now->isEnd = true;
    }
    
    bool search(string str) { return dfs(str, root, 0); }

	bool dfs(string& str, Node* root, int x) { //深搜这颗字典树
		if((size_t)x >= str.length()) return root->isEnd;
		pos = str[x] - 'a';
		if(str[x] == '.') {
			for(int i=0; i<26; i++)
				if(root->next[i] && dfs(str, root->next[i], x+1))
					return true;
		} else if(root->next[pos] && dfs(str, root->next[pos], x+1))
			return true;
		return false;
	}
};

#ifdef debug
int main(void) {
	return 0;
}
#endif
