#include <iostream>
#include <algorithm>
#define MAXN 32
using namespace std;

int n, sum = 0, is_find = 0, alen;
int arr[MAXN], rs[MAXN];
bool vis[MAXN];

void dfs(int x, int tlen, int count) {
//	printf("%d : tlen:%d  count:%d  tag:%d\n", x, tlen, count, alen);
	if(is_find) return ;
	if(count == 3) {
		is_find = true;
		return ;
	}
	if(is_find) return ;
	if(x == n+1) { return; } 
	if(tlen == alen) {
		dfs(x+1, 0, count+1);
	} else if(tlen < alen) {
		for(int i=1; i<=n; i++) {
			if(!vis[i]) {
				rs[x] = i;
				vis[i] = true;
				dfs(x+1, tlen+arr[rs[x]], count);
				vis[i] = false;
			}
		}
	}
}

int main(void) {
	
	freopen("test", "r", stdin);
//	freopen("rs", "wr", stdout);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		sum = 0, is_find = false;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", arr+i);
			sum += arr[i];
		}
		alen = sum / 4;
		sort(arr+1, arr+n+1);
		if(sum % 4) printf("no\n"); //剪支
		else {
			dfs(1, 0, 1);
			printf("%s\n", is_find ? "yes" : "no");
		}
	}
	
	return 0;
}
