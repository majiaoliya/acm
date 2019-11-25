#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;
#define MAX_SIZE 10

const int MAXN = 1e6+7;

int t, n, cnt, tree[MAXN][MAX_SIZE];
bool is_end[MAXN];
inline void init() {
	memset(tree, -1, sizeof(tree));
	memset(is_end, false, sizeof(is_end));
	cnt = 0;
}

bool insert(string& str) {
//	cout << "insert " << str << endl;
	int root = 0, mark = false;
	for(int i=0; i<str.length(); i++) {
		int pos = str[i] - '0';
		if(tree[root][pos] < 0) {
			mark = true; //是一个新节点 说明不是之前某个串的前缀
			tree[root][pos] = ++cnt;
		}
		if(is_end[root]) return false; //遇到一个结尾 说明有前缀
		root = tree[root][pos];
	}
	is_end[root] = true;
	if(!mark) return false;
	return true; //如果插入这个str没有开辟新的节点 就说明有前缀
}

int main(void) {
	freopen("test", "r", stdin);
	std::ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		init();
		cin >> n;
		cin.ignore();
		bool flag = true;
		string str;
		for(int i=1; i<=n; i++) {
			cin >> str;
			if(flag) flag = insert(str);
		}
		printf("%s\n", !flag ? "NO" : "YES");
	}
	return 0;
}
