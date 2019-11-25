#include <iostream>
#include <algorithm>
#define MAXN 65
using namespace std;

int n, tag_len, is_find;
int arr[MAXN];
bool vis[MAXN];

void dfs(int level, int t_len, int count) {
	if(level>n || vis[level] | is_find) return ;
	if(level)
	for(int i=1; i<=n; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		if(t_len+arr[i] == tag_len) {
			dfs(level+1, 0, count+1);
		} else if(t_len+arr[i] < tag_len) {
			dfs(level+1, t_len+arr[i], count);
		}
		vis[i] = false;
	}
}

int main(void) {
	
	for( ; EOF != scanf("%d", &n), n; ) {
		is_find = false;
		memset(vis, false, sizeof(MAXN));
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
		}
		sort(arr+1, arr+1+n);
		for(tag_len=arr[1]; tag_len<=sum; tag_len++) {
			memset(vis, false, sizeof(vis));
			dfs(1, 0, 0);
		}
	}
	
	return 0;
}
