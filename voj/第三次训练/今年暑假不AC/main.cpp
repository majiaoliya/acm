#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAXN 105
using namespace std;

int n;
struct Node {
	int start, end;
} arr[MAXN];

int cmp(Node& x, Node& y) { return x.end < y.end; }

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n) && n; ) {
		for(int i=1; i<=n; i++)
			scanf("%d %d", &arr[i].start, &arr[i].end);
		sort(arr+1, arr+1+n, cmp);
//		for(int i=1; i<=n; i++)
//			printf("%d %d\n", arr[i].start, arr[i].end);
		int cnt = 1, lst = 1;
		for(int i=2; i<=n; i++)
			if(arr[i].start >= arr[lst].end) { cnt++; lst = i; }
		printf("%d\n", cnt);
	}
	return 0;
}
