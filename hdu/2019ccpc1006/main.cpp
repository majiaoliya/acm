#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN 200005
#define ll long long int

int n, q, arr[MAXN], h[MAXN];
bool vis[MAXN];

int main() {
    freopen("test", "r", stdin);
	scanf("%d %d", &n, &q);
	for(int i=n; i>=1; i--) {
		scanf("%d", arr+i);
		h[arr[i]] = i;
	}
	for(int i=1, x; i<=q; i++) {
		scanf("%d", &x);
		vis[h[x]] = true;
		n ++;
		arr[n] = x;
		h[x] = n;
	}
	for(int i=n; i>=1; i--) {
		if(!vis[i])
			printf("%d ", arr[i]);
	}
    return 0;
}

