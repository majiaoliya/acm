#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 10005
using namespace std;

int n, m;

set<int> G[MAXN];

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=m; i++) {
		int x, y;
		G[x].insert(y);
		G[y].insert(x);
	}
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		int tt;
		scanf("%d", &tt);
		bool vis[MAXN], ok = true;
		int arr[tt+1];
		memset(vis, false, sizeof(vis));
		for(int i=1; i<=tt; i++) {
			scanf("%d", &arr+i);
			if(!ok) continue;
			if(vis[arr[i]]) ok = false; //出现两次的节点一定不是哈密顿回路
		}
		if(arr[1] != arr[tt]) ok = false;
		if(ok) {
			memset(vis, false, sizeof(vis));
			int lst;
			for(int i=1; i<=tt; i++) {
				if(vis[arr[i]]) { ok = false; break; }
				if(i==1) {
					lst = arr[i];
					vis[i] = true;
				} else {
					set<int>& s = G[lst];
					if(s.find(arr[i]) == s.end()) { ok = false; break; }
					else {
						lst = arr[i];
					}
				}
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	
	return 0;
}

