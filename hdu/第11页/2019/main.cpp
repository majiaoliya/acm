#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN 100005
using namespace std;

int cows[MAXN];
int count = 1, n;

int main(void) {
	freopen("test", "r", stdin);
	int n, m;
	for( ; EOF != scanf("%d %d", &n, &m) && (n+m); ) {
		vector<int> v;
		for(int i=0; i<n; i++) {
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), m);
		v.insert(it, m);
		for(int i=0, c=0; i<v.size(); i++) {
			if(c++) printf(" ");
			printf("%d", v[i]);
		}
		printf("\n");
	}
	return 0;
}
