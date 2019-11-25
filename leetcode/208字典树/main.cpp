#include <stack>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#define debug
using namespace std;

//
//struct Node {
//	Node* next[27];
//	bool isEnd;
//	Node() : isEnd(false) { memset(next, false, sizeof(next)); }
//};
//
//class Trie {
//public:
//    /** Initialize your data structure here. */
//	Node* root;
//    Trie() {
//		root = new Node();
//    }
//    
//    /** Inserts a word into the trie. */
//    void insert(string str) {
//		int n = str.length();
//		Node* node = root;
//        for(int i=0, loc; i<n; i++) {
//			loc = str[i] - 'a';
//			if(!node->next[loc]) node->next[loc] = new Node();
//			node = node->next[loc];
//		}
//		node->isEnd = true;
//    }
//    
//    /** Returns if the word is in the trie. */
//    bool search(string str) {
//		Node* node = root;
//		for(int i=0, n=str.length(), pos=0; i<n; i++) {
//			pos = str[i] - 'a';
//			if(!node->next[pos]) return false;
//			node = node->next[pos];
//		}
//		return node->isEnd;
//    }
//    
//    /** Returns if there is any word in the trie that starts with the given prefix. */
//    bool startsWith(string str) {
//		Node* node = root;
//		for(int i=0, n=str.length(), pos; i<n; i++) {
//			pos = str[i] - 'a';
//			if(!node->next[pos]) return false;
//			node = node->next[pos];
//		}
//		return true;
//    }
//};

#define MAXN (int)(1e6)

struct Node {
	int next[27];
	bool isEnd;
	Node() : isEnd(false) { memset(next, false, sizeof(next)); }
} tree[MAXN];

class Trie {
public:
	int size, root;
    Trie() : size(0), root(0) { memset(tree, false, size); }
    
    void insert(string str) { 
		int now = root;
        for(int i=0, n=str.length(), pos; i<n; i++) {
			pos = str[i] - 'a';
			if(!tree[now].next[pos]) tree[now].next[pos] = ++size;
			now = tree[now].next[pos];
		}
		tree[now].isEnd = true;
    }
    
    bool search(string str) {
		int now = root;
		for(int i=0, n=str.length(), pos; i<n; i++) {
			pos = str[i] - 'a';
			if(!tree[now].next[pos]) return false;
			now = tree[now].next[pos];
		}
		return tree[now].isEnd;
    }
    
    bool startsWith(string str) {
		int now = root;
		for(int i=0, n=str.length(), pos; i<n; i++) {
			pos = str[i] - 'a';
			if(!tree[now].next[pos]) return false;
			now = tree[now].next[pos];
		}
		return true;
    }
};

#ifdef debug
int main(void) {
	return 0;
}
#endif
