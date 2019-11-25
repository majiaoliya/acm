#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 300005
#include <map>
#define ll long long int
#define max(x, y) ( x > y ? x : y )

using namespace std;

int main() {
	freopen("test", "r", stdin);
	int t, n;
	char str[1024];
	scanf("%d", &t);
	while(t--) {
		scanf(" %d %s", &n, str);
		int rs = 0;
		for(int i=0; i<=n; i++) {
			if(str[i] == '.') {
				rs ++; i+=2;
			}
		}
		printf("%d\n", rs);
	}
	return 0;
}



