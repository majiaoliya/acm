#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;
#define MAX_SIZE 10

const int MAXN = 5e5+7;

int t, n, cnt, tree[MAXN][MAX_SIZE];
bool is_end[MAXN];

void init() {
	memset(tree, -1, sizeof(tree));
	memset(is_end, false, sizeof(is_end));
	cnt = 0;
}

bool insert(string& str) {
	int root = 0;
	bool mark = false;
	for(int i=0; i<str.length(); i++) {
		int pos = str[i] - '0';
		if(tree[root][pos] < 0) {
			mark = true;
			tree[root][pos] = ++cnt;
		}
		if(is_end[root]) return false;
		root = tree[root][pos];
	}
	is_end[root] = true;
	return mark;
}

int main(void) {
	freopen("test", "r", stdin);
	std::ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		init();
		cin >> n;
		string str;
		bool flag = true;
		for(int i=0; i<n; i++) {
			cin >> str;
			if(flag) flag = insert(str);
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}
