//用并查集25分 用dfs28分
// 并查集test3 WA      dfs test2 WA
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 4096

using namespace std;

int cnt = 0, n, m, cur_max, vis[MAXN], cost[MAXN][MAXN];

set<int> G[MAXN];
map<string, int> mp; //名字映射下标
string name[MAXN];

vector<int> rs_id; //这个小团体的所有首领id
int sum_time[MAXN]; //第i个人的总时间

void dsp() {
	for(int i=1; i<=cnt; i++) {
		printf("%d: ", i);
    	set<int>::iterator it = G[i].begin();
    	while(it!=G[i].end()) {
    		printf("->%d", *it);
    		it ++;
    	}
    	printf("\n");
    }
}

void dfs(int x, int& n_count) {
	if(vis[x]) return;
	vis[x] = true;
	sum_time[x] = 0;
	n_count ++; 
	
	for(set<int>::iterator it=G[x].begin(); it!=G[x].end(); it++) {
		sum_time[x] += cost[x][*it];
		if(cur_max < sum_time[x]) { //第x个人通话时间更大 设为首领
			rs_id.clear();
			rs_id.push_back(x);
			cur_max = sum_time[x];
		} else if(cur_max == sum_time[x]) { //第x个人时间和首领相同 设为首领之一
			rs_id.push_back(x);
		}
		dfs(*it, n_count);
	}
}

bool cmp(int xid, int yid) {
	return name[xid] < name[yid];
}

struct Rs {
	string name; 
	int nodes_count; //团队的总人数
	Rs() : nodes_count(0) { }
	bool operator < (const Rs& o) const {
		return name < o.name;
	}
};

int main()
{
    freopen("test", "r", stdin);
    cin >> n >> m; 
    for(int i=1; i<=n; i++) {
    	string x, y;
    	int t;
    	cin >> x >> y >> t;
    	if(mp[x]==0) { mp[x]=(++cnt); name[cnt]=x; }
    	if(mp[y]==0) { mp[y]=(++cnt); name[cnt]=y; }
    	int xid = mp[x], yid = mp[y];
    	cost[xid][yid] += t;
    	cost[yid][xid] += t;
    	G[xid].insert(yid), G[yid].insert(xid);
    }
//    dsp();
    set<Rs> rs;
    for(int i=1; i<=cnt; i++) {
		if(!vis[i]) {
			cur_max = 0;
			int n_count = 0; //记录改图的节点个数
			rs_id.clear(); //rs_id=这个小团体的所有首领id
			dfs(i, n_count);
			
			if(n_count <= 2) continue; //人数不足不是gang
			
			for(int k=0; k<rs_id.size(); k++) {
				Rs r;
				r.name = name[rs_id[k]];
				r.nodes_count = n_count;
//				printf("%s %d\n", r.name.data(), r.nodes_count);
				rs.insert(r);
			}
		}
    }
    
    printf("%d\n", rs.size());
    set<Rs>::iterator it = rs.begin();
    while(it != rs.end()) {
    	printf("%s %d\n", it->name.data(), it->nodes_count);
    	it ++;
    }
    
    return 0;
}


