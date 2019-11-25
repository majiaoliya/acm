#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#define MAX_SIZE 27
using namespace std;

struct Node {
	int flag;
	struct Node* next[MAX_SIZE];
	Node() : flag(0) {
		memset(this->next, false, sizeof(next));
	}
	~Node() {
		for(int i=0; i<MAX_SIZE; i++)
			if(this->next[i]) delete this->next[i];
	}
} *root;

int ans;
void insert(string& str) {
	Node* p = root;
	for(int i=0; i<str.length(); i++) {
		if(p->next[str[i]-'a'] == nullptr)
			p->next[str[i]-'a'] = new Node;
		p = p->next[str[i]-'a'];
	}
	p->flag ++;
	if(p->flag == 1) ans ++;
}

string str;

int main(void) {
	freopen("test", "r", stdin);
	std::ios::sync_with_stdio(false);
	while(getline(cin, str)) {
		if(str[0] == '#') break ;
		ans = 0;
		root = new Node;
		stringstream ss(str);
		string ts;
		while(ss >> ts) {
			insert(ts);
		}
		cout << ans << endl;
		delete root;
	}
	return 0;
}
