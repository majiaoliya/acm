#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	freopen("test", "r", stdin);
	int n, m;
	for( ; EOF != scanf("%d %d", &n, &m); ) {
		int arr[n];
		for(int i=0; i<n; i++)
			scanf("%d", arr+i);
		int i = 0;
		for( ; i<n; i++) {
			if(arr[i] == m) { printf("%d\n", i); break; }
		}
		if(i == n) printf("Not Found\n");
	}
	return 0;
}

