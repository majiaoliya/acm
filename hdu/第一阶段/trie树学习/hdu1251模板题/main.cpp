#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 26
using namespace std;

const int MAXN = 2e6+5; //64MB
int tree[MAXN][30];
bool flagg[MAXN];

int tot, sum[MAXN];

inline void init() {
	memset(tree, false, sizeof(tree));
	memset(flagg, false, sizeof(flagg));
	tot = 0;
}

string str;

void insert_(string& s) {
	int root = 0;
	for(size_t i=0; i<s.length(); i++) {
		int id = s[i] - 'a';
		if(tree[root][id] == 0) tree[root][id] = ++tot;
		sum[tree[root][id]] ++;
		root = tree[root][id];
	}
}

int find_(string& s) {
	int root = 0;
	for(size_t i=0; i<s.length(); i++) {
		int id = s[i] - 'a';
		if(tree[root][id] == 0) return 0;
		root = tree[root][id];
	}
	return sum[root];
}

int main(void) {
	freopen("test", "r", stdin);
	std::ios::sync_with_stdio(false);
	while(getline(cin, str) && str.length()) {
		insert_(str);
	}
	while(cin >> str) {
		cout << find_(str) << endl;
	}
	return 0;
}
