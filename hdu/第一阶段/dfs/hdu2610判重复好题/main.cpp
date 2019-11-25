#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#define MAXN 1005
using namespace std;

int flag, len, tcnt, n, p, arr[MAXN], cnt, rs[MAXN];
bool vis[MAXN];

struct Node {
	int num, pos;
} temp[MAXN];

bool check(int s, int e) {
	for(int i=s+1; i<e; i++)
		if(arr[i] == arr[e]) return false;
	return true;
}

void prt(int len) {
	for(int i=0; i<len-1; i++)
		cout << temp[i].num << " ";
	cout << temp[len-1].num << endl;
}

void dfs(int x, int pos) {
	if(cnt >= p) return ;
	if(x == len) {
		cnt ++;
		flag = true;
		prt(len);
		return ;
	}
	for(int i=pos; i<n; i++) {
		if((x!=0 && temp[x-1].num<=arr[i]) || x==0) {
			if(x==0 && !check(-1, i)) continue;
			if(x!=0 && !check(temp[x-1].pos, i)) continue;
			temp[x].num = arr[i];
			temp[x].pos = i;
			dfs(x+1, i+1);
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);
	
	while(cin>>n>>p) {
		for(int i=0; i<n; i++)
			cin >> arr[i];
		cnt = 0;
		for(int i=1; i<n; i++) {
			flag = false;
			len = i;
			dfs(0, 0);
			if(cnt >= p || !flag) break;
		}
		cout << endl;
	}

	return 0;
}

