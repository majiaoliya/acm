#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define MAXN 128

int n, ans[MAXN];

void dfs(int x, int sum) {
	if(sum > n) return ;
	if(sum == n) {
		for(int i=1; i<x; i++) printf("%d%s", ans[i], i==x-1?"\n":"+");
		return ;
	}
	for(int i=1; i<n; i++) {
		if(ans[x-1] > i) continue ;
		ans[x] = i;
		dfs(x+1, sum+i);
		ans[x] = 0;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	cin >> n;
	dfs(1, 0);
	return 0;
}



