#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#define MAX_SIZE 26
#define MAXN 1000005
using namespace std;

int n, m, tree[MAXN][MAX_SIZE], cnt;
int sum[MAXN];
string str;

void insert(string& s) {
	int root = 0;
	for(int i=0; i<s.length(); i++) {
		int pos = s[i] - 'a';
		if( ! tree[root][pos]) tree[root][pos] = ++cnt;
		root = tree[root][pos];
	}
	sum[root] ++;
}

int find(string& s) {
	int root = 0, ret = 0;
	for(int i=0; i<s.length(); i++) {
		int pos = s[i] - 'a';
		if( ! tree[root][pos]) break;
		root = tree[root][pos];
		ret += sum[root];
	}
	return ret;
}

int main(void) {
	freopen("test", "r", stdin);
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> str;
		insert(str);
	}
	for(int i=0; i<m; i++) {
		cin >> str;
		printf("%d\n", find(str));
	}
	return 0;
}
