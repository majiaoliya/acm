#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n;

struct Point {
	int x, y;
	Point(int _x, int _y) : _x(x), _y(y) { }
} arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	while(EOF != scanf("%d", &n) && n) {
		for(int i=1; i<=n; i++) 
			scanf("%d %d", &arr[i].x, &arr[i].y);
		for(int i=2; i<=n; i++) {
			sum += 
		}
	}
	return 0;
}
