#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <algorithm>
#include <stack>
#define MAXN 100086

using namespace std;

int n, m, arr[MAXN], cnt, ok, rs[MAXN];
bool vis[MAXN];
vector<int> rsv;

void dfs(int x, int sum) {
	if(x>n || sum>m || ok) return ;
	if(sum == m) {
		ok = true;
		if(rsv.empty()) {
			for(int i=1; i<x; i++) 
				rsv.push_back(arr[rs[i]]);
		} else {
			bool tag = true;
			for(int i=1; i<x&&(i-1)<rsv.size(); i++) 
				if(arr[rs[i]] > rsv[i-1]) { tag = false; break;}
			if(tag) {
				rsv.clear();
				for(int i=1; i<x; i++)
					rsv.push_back(arr[rs[i]]);
			}
		}
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i]) continue ;
		rs[x] = i;
		vis[i] = true;
		dfs(x+1, sum+arr[i]);
		vis[i] = false;
	}
}

int main()
{
	freopen("test", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) 
    	scanf("%d", arr+i);
    sort(arr+1, arr+n+1);
    if(n == 1) {
    	if(arr[1]==m)
    		printf("%d\n", arr[1]);
    	else 
    		printf("No Solution\n");
    	return 0;
    }
    dfs(1, 0);
    if(rsv.empty()) printf("No Solution\n");
    else {
    	for(int i=0; i<rsv.size(); i++) {
    		if(i) printf(" ");
    		printf("%d", rsv[i]);
    	}
    }
    return 0;
}

