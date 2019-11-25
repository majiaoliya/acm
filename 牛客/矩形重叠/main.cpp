#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 300005
#include <map>
#define ll long long int
#define max(x, y) ( x > y ? x : y )

using namespace std;

int n;

struct Rect {
	int x1, x2, y1, y2;
	bool operator < (const Rect& other) {
		return this->x1 < other.x1;
	}
} arr[MAXN];

vector<int> vx, vy;

int main() {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) 
		scanf("%d", &arr[i].x1);
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i].y1);
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i].x2);
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i].y2);

	return 0;
}



