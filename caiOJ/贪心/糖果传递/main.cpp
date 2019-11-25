#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define MAXN 654322
using namespace std;

int n, x;
vector<int> v;
int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%d", &n)) {
		for(int i=1; i<=n; i++) {
			scanf("%d", &x);
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
			v.insert(it, x);
		}
		printf("%d\n", v[v.size()/2]);
	}
	return 0;
}
