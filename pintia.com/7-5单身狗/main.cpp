#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n, m, tag[MAXN], pairs[MAXN]; //<x,y> pairs[x]=y+1 错开一位方便存储 如果pairs[x] == 0 则 x没有伴侣
bool vis[MAXN];

int main() {
	freopen("test", "r", stdin);
	
	cin >> n;
	int x, y;
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		pairs[x] = y+1; // 取x的伴侣y时 y = pairs[x]-1; 
		pairs[y] = x+1;
	}
	set<int> rs;
	int m;
	cin >> m;
	for( ; m--; ) {
		cin >> x;
		if(pairs[x] == 0) { //x没有伴侣
			vis[x] = true;
			rs.insert(x);
		} else { //有伴侣
			set<int>::iterator it = rs.find( (pairs[x]-1) ); //来的人里面找伴侣
			if(it == rs.end()) //来的人里面没有伴侣
				rs.insert(x);
			else
				rs.erase(it);
		}
	}
	cout << rs.size() << endl;
	set<int>::iterator it = rs.begin();
	for(int c=0; it!=rs.end(); it++) {
		if(c++) printf(" ");
		printf("%05d", *it);
	}
	return 0;
}


