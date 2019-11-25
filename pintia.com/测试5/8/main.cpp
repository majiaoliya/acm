#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n;
map<string, int> mp;

int main()
{
//	freopen("test", "r", stdin);
	
	cin >> n;
	string t;
	getline(cin, t);
	for(int i=0; i<n; i++) {
		string name;
		getline(cin, name);
		mp[name] ++;
	}
	
	map<string, int>::iterator it = mp.begin();
	while(it != mp.end()) {
		double rs = it->second*1. / (n*1.) * 100;
		string name = it->first;
		cout << name;
		printf(" %.4lf%%\n", rs);
//		printf("%s %.4lf\n", name.data(), rs);
		it ++;
	}
	
	return 0;
}

