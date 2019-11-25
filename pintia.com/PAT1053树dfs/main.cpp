#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
#define MAXN 105
using namespace std;

int n, m, max_v;
int value[MAXN];
vector<int> G[MAXN];

vector<vector<int>> rs;

void dsp() {
	for(int i=0; i<n; i++) {
		printf("%d:", i);
		for(int k=0; k<G[i].size(); k++) {
			printf("->%d", G[i][k]);
		}
		printf("\n");
	}
}

bool dfs(int root, int val, vector<int> tv) {
	tv.push_back(value[root]);
	if(G[root].empty() && val==max_v) {
		rs.push_back(tv);
	}
	for(int i=G[root].size()-1; i>=0; i--) {
		dfs(G[root][i], val+value[G[root][i]], tv);
	}
	return false;
}

bool cmp(vector<int>& x, vector<int>& y) {
	for(int i=0; i<x.size() && i<y.size(); i++) {
		if(x[i] == y[i]) continue ;
		return x[i] > y[i];
	}
	return false;
}

int main() {
	freopen("test", "r", stdin);
	
	scanf("%d %d %d", &n, &m, &max_v);
	for(int i=0; i<n; i++) 
		scanf("%d", value+i);
	
	for(int i=0; i<m; i++) {
		int root, t = 0;
		scanf("%d %d", &root, &t);
		for(int k=0; k<t; k++) {
			int chl;
			scanf("%d", &chl);
			G[root].push_back(chl);
		}
	}
//	dsp();
	vector<int> v;
	dfs(0, value[0], v);
	sort(rs.begin(), rs.end(), cmp); //题目要求按非递减序列打印...?
	for(int i=0; i<rs.size(); i++) {
		for(int k=0, c=0; k<rs[i].size(); k++) {
			if(c++) printf(" ");
			printf("%d", rs[i][k]);
		}
		printf("\n");
	}
	return 0;
}
























