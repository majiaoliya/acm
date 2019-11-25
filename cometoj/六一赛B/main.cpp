//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string.h>
//#define ll long long int 
//#define MAXN 20
//using namespace std;
//int n;
//ll arr[MAXN];

//ll gcd(ll a, ll b) {
//	return (b>0) ? gcd(b, a%b) : a;
//}

//int main(void) {
//	freopen("test", "r", stdin);
//	int t;
//	for( ; EOF != scanf("%d", &t); ) {
//		for( ; t--; ) {
//			scanf("%d", &n);
//			for(int i=0; i<n; i++)
//				scanf("%lld", arr+i);
//			vector<ll> rs;
//			sort(arr, arr+n);
//			for(int i=0; i<n; i++) {
//				bool ok = true;
//				for(int k=0; k<rs.size(); k++) {
//					if(gcd(rs[k], arr[i]) != 1) {
//						ok = false;
//						break;
//					}
//				}
//				if(ok) 
//					rs.push_back(arr[i]);
//			}
//			for(int i=0; i<rs.size(); i++)
//				printf("%lld,", rs[i]);
//			printf(" size:%d\n", (int)rs.size());
////			printf("%d\n", (int)rs.size());
//		}
//	}
//	return 0;
//}


/**

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define ll long long int 
#define MAXN 16
using namespace std;
int n;
ll arr[MAXN], rs[MAXN], vis[MAXN]; 
int tmax = 0;

ll gcd(ll a, ll b) {
	return (b>0) ? gcd(b, a%b) : a;
}

void dfs(int x, vector<ll>& v) {
	
	if(x == n+1) {
//		for(int i=0; i<v.size(); i++)
//			printf("%lld,", arr[rs[i+1]]);
//		printf("\n");
		tmax = tmax < v.size() ? v.size() : tmax;
		v.clear();
		return;
	}
	
	for(int i=1; i<=n; i++) {
		if(vis[i]) continue;
		vis[i] = true;
		rs[x] = i;
		bool ok = true;
		for(int k=0; k<v.size(); k++) {
			if(1 != gcd(v[k], arr[i])) {
				ok = false;
				break;
			}
		}
		if(ok)
			v.push_back(arr[i]);
		dfs(x+1, v);
		vis[i] = false;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	int t;
	for( ; EOF != scanf("%d", &t); ) {
		for( ; t--; ) {
			scanf("%d", &n);
			for(int i=1; i<=n; i++)
				scanf("%lld", arr+i);
			vector<ll> v;
			dfs(1, v);
			printf("%d\n", tmax);
		}
	}
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define ll long long int 
#define MAXN 20
using namespace std;
int n, tmax;
ll arr[MAXN];
bool vis[MAXN], used[MAXN];

ll gcd(ll a, ll b) {
	return (b > 0) ? gcd(b, a%b) : a;
}

bool check(int num) {
	for(int i=1; i<=n; i++)
		if(used[i] && 1!=gcd(num, arr[i])) return false;
	return true;
}

void dfs(int x) {
	if(x == n+1) {
		int tag = true;
		for(int i=1; i<=n && tag; i++) {
			for(int k=1; k<=n && tag; k++) {
				if(i == k) continue;
				if(vis[i] && vis[k] && 1!=gcd(arr[i], arr[k])) {
					tag = false;
				}
			}
		}
		int tcnt = 0;
		for(int i=1; i<=n; i++)
			if(vis[i]) tcnt ++;
		if(tag) {
			tmax = max(tmax, tcnt);
#ifdef DEBUG
			for(int i=1; i<=n; i++)
				printf("%d-", vis[i]);
			printf("\n");
#endif
		}
		return; 
	}
	
	vis[x] = true;
	dfs(x+1);
	vis[x] = false;
	dfs(x+1);
}

int main(void) {
	freopen("test", "r", stdin);
	int t;
	for( ; EOF != scanf("%d", &t); ) {
		for( ; tmax=0, t--; ) {
			scanf("%d", &n);
			memset(vis, false, n+3);
			memset(used, false, n+3);
			for(int i=1; i<=n; i++)
				scanf("%lld", arr+i);
			dfs(1);
			printf("%d\n", tmax);
		}
	}
	return 0;
}





























