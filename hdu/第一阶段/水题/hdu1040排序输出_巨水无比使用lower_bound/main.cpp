#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#define MAXN 10005
using namespace std;

int n, x, t;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d", &n);
		vector<int> v;
		for(int i=1; i<=n; i++) {
			scanf("%d", &x);
			vector<int>::iterator mid = lower_bound(v.begin(), v.end(), x);
			v.insert(mid, x);
		}
		for(int i=0; i<v.size(); i++) {
			if(i) printf(" ");
			printf("%d", v[i]);
		}
		printf("\n");
	}
	return 0;
}





