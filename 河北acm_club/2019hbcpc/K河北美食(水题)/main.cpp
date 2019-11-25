#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
//#include <math.h>
#define MAXN 1005
#define ll long long
using namespace std;

string names[MAXN];
int n, m;
map<string, int> mp;

int main(void) {
	freopen("test", "r", stdin);
	cin >> n >> m;
	string name;
	int sum;
	mp.clear();
	for(int i=1; i<=n; i++) {
		cin >> names[i] >> sum;
		mp[names[i]] = sum;
	}
	bool ok = true;
	for(int i=1, t; i<=m; i++) {
		cin >> t;
		for( ; t--; ) {
			cin >> name >> sum;
			if(!ok) continue;
			int& psum = mp[name];
			if(sum > psum) ok = false;
			else psum -= sum;
		}
	}
	if(!ok) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i=1; i<=n; i++) {
		int cnt = mp[names[i]];
		if(cnt) cout << names[i] << " " << cnt << endl;
	}
	
	return 0;
}
