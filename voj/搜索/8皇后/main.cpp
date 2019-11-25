#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 16
using namespace std;

int n, arr[MAXN], trs, rs[MAXN], vis[MAXN];
void init() {
	trs = 0;
	memset(arr, false, sizeof(arr));
}

int abs(int x) { return x > 0 ? x : -x; }

bool check(int r1, int c1, int r2, int c2) {
	return (r1!=r2 && c1!=c2 && abs(r1-c1)!=abs(r2-c2));
}

void dbg() {
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=n; k++) {
			if(k==arr[i]) printf("* ");
			else printf("O ");
		}
		printf("\n");
	}
}

void dfs(int x) {
	if(x == n+1) {
		trs ++;
		return ;
	}
	for(int i=1; i<=n; i++) {
		arr[x] = i;
		bool ok = true;
		for(int k=1; k<x; k++) {
			if(arr[x]==arr[k] || x-arr[x]==k-arr[k] || x+arr[x]==k+arr[k]) {
				ok = false; break;
			}
		}
		if(ok) dfs(x+1);
	}
}

int main(void) {
	freopen("test", "r", stdin);
	while(EOF!=scanf("%d", &n) && n) {
		if(vis[n]) printf("%d\n", rs[n]);
		else {
			trs = 0;
			dfs(1);
			rs[n] = trs;
			vis[n] = true;
			printf("%d\n", rs[n]);
		}
	}
	return 0;
}
