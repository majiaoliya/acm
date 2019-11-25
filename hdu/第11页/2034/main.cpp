#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#define MAXN 10005
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	int n, m;
	for( ; (EOF != scanf("%d %d", &n, &m)) && (n+m); ) {
		vector<int> s1;
		set<int> s2;
		int x;
		for(int i=1; i<=n; i++)	{
			scanf("%d", &x);
			s1.push_back(x);
		}
		for(int i=1; i<=m; i++)	{
			scanf("%d", &x);
			s2.insert(x);
		}
		for(int i=0; i<s1.size(); ) {
			if(s2.find(s1[i]) != s2.end()) {
				s1.erase(s1.begin()+i);
				continue ;
			}
			i++;
		}
		sort(s1.begin(), s1.end());
		if(s1.empty()) printf("NULL\n");
		else {
			for(int i=0; i<s1.size(); i++) {
				printf("%d ", s1[i]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
