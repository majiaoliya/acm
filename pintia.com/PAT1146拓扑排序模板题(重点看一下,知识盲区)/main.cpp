#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>
#define MAXN 10086
using namespace std;

//题目:给定一个图,和t个序列, 打印不是拓扑序列的序列下标[0,t-1]

vector<int> G[MAXN];
int n, m;

bool topsort(vector<int>& arr, int tind[]) {
	int ind[MAXN];
	for(int i=1; i<=n; i++) { //每次都要把原始的入度拷贝一份
		ind[i] = tind[i];
	}
	for(int i=0; i<arr.size(); i++) { //遍历这个序列 当前arr[i]入度不为0就不可能
		if(ind[arr[i]] != 0) return false; //当前arr[i]入度不为0就不可能是top
		for(int k=0; k<G[arr[i]].size(); k++) { //arr[i]入度==0 子节点入度全部-1
			int chl = G[arr[i]][k];
			ind[chl] --; //子节点入度全部-1
		}
	}
	return true;
}

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d %d", &n, &m);
	int ind[MAXN]; memset(ind, false, sizeof(ind));
	for(int i=1; i<=m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		ind[y] ++; // y的入度+1
	}
	int t;
	scanf("%d", &t);
	vector<int> rs;
	for(int i=0; i<t; i++) {
		vector<int> arr;
		for(int i=0, x; i<n; i++) {
			scanf("%d", &x);
			arr.push_back(x);
		}
		if(!topsort(arr, ind)) rs.push_back(i);
	}
	for(int i=0, c=0; i<rs.size(); i++) {
		if(c++) printf(" ");
		printf("%d", rs[i]);
	}
	return 0;
}
