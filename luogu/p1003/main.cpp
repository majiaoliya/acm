#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define MAXN 10005

struct Node {
	int x, y, w, h;
} arr[MAXN];

int n;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	int i;
	for(i=1; i<=n; i++)
		scanf("%d %d %d %d", &arr[i].x, &arr[i].y, &arr[i].w, &arr[i].h);
	int x, y;
	scanf("%d %d", &x, &y);
	for(i=n; i>=1; i--) {
		if(x>=arr[i].x && y>=arr[i].y 
				&& x<=arr[i].x+arr[i].w && y<=arr[i].y+arr[i].h) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}



