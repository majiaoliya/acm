#include <iostream>
#include <stack>
#include <vector>
#define MAX 100005
using namespace std;

vector<int> vs[MAX];
int arr[MAX];
bool vis[MAX];
int t = 0, rs = 1;

void dfs(int root, int n, int level) {
	if(level > t) {
		t = level;
		rs = root;
	}
	if(root <= n) {
		for(int i=0; i<vs[root].size(); i++) {
			dfs(vs[root][i], n, level+1);
		}
	}
}

int main(void) {
	freopen("test", "r", stdin);

	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int t;
		scanf("%d", &t);
		for(int x; t--; ) {
			scanf("%d", &x);
			vs[i].push_back(x);
			vis[x] = true;
		}
	} 
		
	int root_id = 1;
	for(int i=1; i<=n; i++)
		if(!vis[i]) root_id = i;
	
	dfs(root_id, n, 1);
//	cout << t << " rs:" << rs << endl; 
	cout << rs << endl;
	return 0;
}






/**

#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

#define MAX 100005
using namespace std;

int pre[MAX];
int level[MAX];
bool vis[MAX];
int t = 0, rs = 1;

int main(void) {
	freopen("test", "r", stdin);
	memset(pre, false, sizeof(pre));
	memset(level, false, sizeof(level));
	memset(vis, false, sizeof(vis));
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int t;
		scanf("%d", &t);
		for( ; t--; ) {
			int x;
			scanf("%d", &x);
			pre[x] = i;
		}
	}
	
	int max_id = 1, max_level=0;
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			vector<int> pids;
			int pid = pre[i], t_level = 1;
			while(pid) {
				if(vis[pid]) {
					t_level += level[pid];
					break;
				}
				t_level ++;
				pids.push_back(pid);
				pid = pre[pid];
			}
			vis[i] = true;
			level[i] = t_level;
			for(int k=0, t=t_level; k<pids.size(); k++) {
				level[pids[k]] = --t;
				vis[pids[k]] = true;
			}
			if(t_level > max_level) {
				max_id = i;
				max_level = t_level;
			}
		}
	}
	
	printf("%d\n", max_id);
	
	return 0;
}
*/

