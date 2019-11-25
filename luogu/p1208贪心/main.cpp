#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long int
#define MAXN ((int)1e5)

int n, m;
struct Node {
	int unit, w;
} arr[MAXN];

bool cmp(Node& x, Node& y) {
//	int wx = x.w / x.unit, wy = y.w / y.unit;
//	return x.w*y.unit > y.w*x.unit;
	return x.unit < y.unit;
}

int main(void) {
	freopen("test", "r", stdin);
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++)
		scanf("%d %d", &arr[i].unit, &arr[i].w);
	sort(arr, arr+m, cmp);
	int sum = 0;
	for(int i=0; i<m; i++) {
		if(n >= arr[i].w) {
			sum += arr[i].w * arr[i].unit;
			n -= arr[i].w;
		} else {
			sum += arr[i].unit * n;
			break;
		}
	}
	printf("%d\n", sum);
	return 0;
}



