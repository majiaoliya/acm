/**
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <queue>
#include <unordered_set>
#define ll long long int
#define max(x, y) ( x > y ? x : y )
#define min(x, y) ( x < y ? x : y )
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

int n, m;

struct Node {
	int val, idx;
};

vector<Node> amin, amax;

bool cmp_min(Node& x, Node& y) {
	if(x.val == y.val) return x.idx < y.idx;
	else return x.val < y.val;
}

bool cmp_max(Node& x, Node& y) {
	if(x.val == y.val) return x.idx > y.idx;
	else return x.val > y.val;
}

int main() {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		Node x;
		for(int i=1; i<=n; i++) {
			x.idx = i;
			scanf("%d", &x.val);
			amin.push_back(x), amax.push_back(x);
		}
		make_heap(amin.begin(), amin.end(), cmp_max);
		make_heap(amax.begin(), amax.end(), cmp_min);
		printf("\n");
		int cnt = 0, sub;
		int lef[m+3], rig[m+3], nlef = 0, nrig = 0;
		Node tmin = amin[0], tmax = amax[0];
		while(cnt<m) {
			cnt ++;
			tmin = amin[0], tmax = amax[0];
			sub = abs(tmin.val - tmax.val);
			if(sub <= 1) break;
			pop_heap(amin.begin(), amin.end(), cmp_max);
			pop_heap(amax.begin(), amax.end(), cmp_min);
			tmin.val ++, tmax.val --;
			amin[n-1] = tmin, amax[n-1] = tmax;
			push_heap(amin.begin(), amin.end(), cmp_max);
			push_heap(amax.begin(), amax.end(), cmp_min);
		}	
		printf("%d %d\n", sub, cnt);
		for(int i=0; i<nlef; i++)
			printf("%d %d\n", rig[i], lef[i]);
	}
	return 0;
}

		
*/


#include <iostream>
#include <set>
#include <vector>
using namespace std;

int n, m;

struct Node {
	int idx, val;
	bool operator < (const Node& other) const {
		return (this->val==other.val) ? (this->idx<other.idx) : (this->val<other.val);
	}
};

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d %d", &n, &m)) {
		Node x;
		set<Node> seta;
		for(int i=1; i<=n; i++) {
			x.idx = i;
			scanf("%d", &x.val);
			seta.insert(x);
		}
		Node big, lit;
		int cnt = 0, sub = 0;
		vector<pair<int,int> > rs;
		while((big=*(--seta.end()), lit=*seta.begin()), (sub=big.val-lit.val)>1 && cnt<m) {
			seta.erase(seta.begin()), seta.erase(--seta.end());
			cnt ++;
			rs.push_back({big.idx, lit.idx});
			big.val --, lit.val ++;
			seta.insert(big), seta.insert(lit);
		}
		printf("%d %d\n", sub, cnt);
		for(int i=0; i<rs.size(); i++)
			printf("%d %d\n", rs[i].first, rs[i].second);
	}
	return 0;
}
