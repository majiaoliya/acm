#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#define MAX_SIZE 26
using namespace std;

#define MAX_SIZE 26
// 题目意思 : 给定多对string (key, val) 通过key查找val  
struct Node {
	Node* next[MAX_SIZE];
	string val;
	bool flag;
	Node() : flag(false) { memset(next, false, sizeof(next)); }
	~Node() {
		for(int i=0; i<MAX_SIZE; i++)
			if(next[i]) delete next[i];
	}
} *root;

void insert(string& s, string& val) {
	Node* p = root;
	for(int i=0; i<s.length(); i++) {
		int id = s[i] - 'a';
		if( ! p->next[id]) p->next[id] = new Node;
		p = p->next[id];
	}
	p->flag = true;
	p->val = val;
//	cout << "	" << "insert " << s << " " << val << endl;
}

string find(string key) {
	Node* p = root;
	for(int i=0; i<key.length(); i++) {
		int id = key[i] - 'a';
		if( ! p->next[id]) return "eh";
		p = p->next[id];
	}
	if(p->flag) return p->val;
	return "eh";
}

int main(void) {
	freopen("test", "r", stdin);
	std::ios::sync_with_stdio(false);
	string line, str, q, val;
	root = new Node;
	while(getline(cin, line)) {
		if(line[0] == '\0') break;
		stringstream ss(line);
		ss >> val >> str;
		insert(str, val);
	}
	while(cin >> q) {
		cout << find(q) << endl;
	}
//	delete root;
	return 0;
}
