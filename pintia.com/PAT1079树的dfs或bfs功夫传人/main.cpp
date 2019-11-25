#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <algorithm>
#include <stack>
#define MAXN 100005

using namespace std;

vector<int> G[MAXN];
struct Node {
	int x;
	double val;
	Node() : x(0), val(0) { }
	Node(int _x, double _v) : x(_x), val(_v) { }
};

int n, bei[MAXN];
double m , bfb; //根节点值, 百分比

void bfs() {
	Node tmp(0, m);
	queue<Node> q;
	q.push(tmp);
	double sum = 0;
	while(!q.empty()) {
		Node n = q.front();
		q.pop();
		if(G[n.x].empty()) { //叶节点
			sum += n.val * bei[n.x];
		} else {
			vector<int>& tv = G[n.x];
			for(int i=0; i<tv.size(); i++) {
				double tval = n.val + n.val * bfb;
				Node tn(tv[i], tval);
				q.push(tn);
			}
		}
	}
	printf("%.1lf\n", sum);
}

int main()
{
    freopen("test", "r", stdin);
    scanf("%d %lf %lf", &n, &m, &bfb);
    bfb *= .01;
    for(int i=0; i<n; i++) {
    	int t, x;
    	scanf("%d", &t);
    	if(t == 0) {
    		scanf("%d", &x);
    		bei[i] = x;
    	} else {
			for( ; t--; ) {
				scanf("%d", &x);
				G[i].push_back(x);
			}
    	}
    }
    bfs();
    return 0;
}

