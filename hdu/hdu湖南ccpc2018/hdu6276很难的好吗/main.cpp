#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long int
using namespace std;

const int MAXN = 250005;

int n, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n); ) {
		int rs = 0;
		for(int i=0; i<=n; i++) {
			scanf("%d", arr+i);
			if(arr[i]>=i+1) {
				rs = max(rs, i);
			}
		}
		printf("%d\n", rs);
	}
	return 0;
}
