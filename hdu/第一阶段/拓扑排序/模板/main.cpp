// hiho oj 1174
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#define MAXN 100005
using namespace std;

int t, n, m, ind[MAXN];
vector<int> G[MAXN];

bool topsort() {
	queue<int> q;
	for(int i=1; i<=n; i++) //初始化 所有入度为0的点入队列
		if(ind[i] == 0) q.push(i);
	int cnt = 0;
	while(!q.empty()) { //取出所有队列里的点x 同时x的子节点入度-1
		int x = q.front();
		q.pop();
		cnt ++;
		for(int i=0; i<G[x].size(); i++) {
			int chl = G[x][i];
			ind[chl] --; //x的子节点入度-1
			if(ind[chl] == 0) //子节点入度为0 也入队列
				q.push(chl);
		}
	}
	if(cnt == n) return true; //cnt == n说明没有环
	return false;
}

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		memset(ind, false, sizeof(ind));
		for(int i=1; i<=n; i++) 
			G[i].clear();
		for(int i=1; i<=n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
			ind[y] ++; //y入度+1
		}
		bool no_circle = topsort();
		printf("%s\n", no_circle ? "Correct" : "Wrong");
	}
	
	return 0;
}
