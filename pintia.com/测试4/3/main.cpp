#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 10005
using namespace std;

int n, m;
int table[MAXN];
int main()
{
	freopen("test", "r", stdin);
	cin >> n;
	string str;
	int cur_max = 0;
	for(int i=1; i<=n; i++) {
		cin >> str;
		for(int k=0; k<str.length(); k++) {
			table[str[k]-'0'] ++;
			if(table[str[k]-'0'] > cur_max) {
				cur_max = table[str[k]-'0'];
			}
		}
	}
	set<int> rs;
	for(int i=0; i<=10; i++)
		if(table[i] == cur_max) rs.insert(i);
	cout << cur_max << ":";
	set<int>::iterator it = rs.begin();
	while(it != rs.end()) {
		printf(" %d", *it);
		it ++;
	}
	return 0;
}

