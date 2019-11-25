#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
using namespace std;

int n, is_find;

string arr[MAXN];
bool vis[MAXN];
int rs[MAXN];

void dfs(int x) {
	if(x == n+1) return ;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			rs[x] = i;
			vis[i] = true;
			string& lst = arr[rs[x-1]];
			string& cur = arr[rs[x]];
			if(lst[lst.length()-1] != cur[0]) continue ;
			for(int i=1; i<x; i++)
				printf("(%s)", arr[rs[i]].data());
			printf("   lst:%s %c  cur:%s %c\n", lst.data(),
				lst[lst.length()-1], cur.data(), cur[0]);
			dfs(x+1);
			vis[i] = false;
		}
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
	string s;
	for(n=1; ; ) {
		cin >> s;
		if(s == "0") break;
		arr[n] = s;
		n ++;
	}
	n--;
	for(int i=1; i<=n; i++) {
		if(arr[i][0] == 'b') {
			memset(vis, false, sizeof(vis));
			vis[i] = true;
			rs[1] = i;
			dfs(2);
		}
	}
	return 0;
}


