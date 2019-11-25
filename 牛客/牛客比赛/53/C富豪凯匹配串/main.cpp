#include <iostream>
#include <string>
#define MAXN 10005
using namespace std; 

int n, m, q, ans;
string str;

int tree[MAXN][3], cnt;

void insert(string& str) {
	int now = 0, len = str.length();
	for(int i=0, pos; i<len; i++) {
		pos = str[i] - '0';
		if(tree[now][pos] == 0) tree[now][pos] = ++cnt;
		now = tree[now][pos];
	}
}

bool find_str(string& str) {
	int now = 0, len = str.length();
	for(int i=0, pos; i<len; i++) {
		pos = str[i] - '0';
		if(tree[now][pos] == 0) return false;
		now = tree[now][pos];
	}
	return true;
}

void dfs(string& str, int now, int i) {
	if(i == m) {
		ans ++;
		return ;
	}

	if(str[i] == '_') {
		for(int k=0; k<2; k++) {
			dfs(str, tree[now][k], i+1);
		}
	} else {
		
	}
}

int main(void) {
	freopen("test", "r", stdin);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> str;
		insert(str);
	}
	cin >> q;
	while(q--) {
		cin >> str;
		ans = 0;
		cout << find_str(str) << endl;
	}
	return 0;
}
