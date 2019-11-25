#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define MAXN 3005
using namespace std;
int n;
int tag[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	int t;
	scanf("%d", &t);
	for( ; t--; ) {
		scanf("%d", &n);
		memset(tag, false, sizeof(tag));
		bool ok = true;
		for(int i=1; i<=n-1; i++) {
			int j=1, count = 0;
			for( ; j+i<=n; j++) {
				int x;
				scanf("%d", &x);
				tag[i] += x;
				tag[i+j] += x;
				if(tag[i]>=3 || tag[i+j]>=3) ok = false;
			}
//			printf("\n");
		}
		printf("%s\n", ok ? "Great Team!" : "Bad Team!");
	}
	return 0;
}
