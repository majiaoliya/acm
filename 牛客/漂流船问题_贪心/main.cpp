#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 9999999
using namespace std;

int n, m, arr[MAXN];
bool vis[MAXN];
char c = ' ';

int main(void) {
	freopen("test", "r", stdin);
	do {
		++n;
		scanf("%d", arr+n);
	} while((c=getchar()) != '\n');
	sort(arr+1, arr+1+n);
	int rs = 0;
	scanf("%d", &m);
	for(int i=n; i>=1; i--) {
		if(vis[i]) continue ;
		vis[i] = true;
		rs ++;
		for(int k=i-1; k>=1; k--) {
			if(vis[k]) continue ;
			if(arr[k]+arr[i] <= m) {
				vis[k] = true;
				break;
			}
		}
	}
	printf("%d\n", rs);
	return 0;
}
