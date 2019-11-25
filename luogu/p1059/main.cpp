#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define MAXN 105

int n, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	if(n <= 0) return 0;
	for(int i=1; i<=n; i++) scanf("%d", arr+i);
	sort(arr+1, arr+1+n);
	int m = 1, lst = arr[1];
	for(int i=2; i<=n; i++) {
		if(arr[i] != lst)
			arr[++m] = arr[i];
		lst = arr[i];
	}
	printf("%d\n", m);
	for(int i=1; i<=m; i++)
		printf("%d%c", arr[i], i==m ? '\n' : ' ');
	return 0;
}



