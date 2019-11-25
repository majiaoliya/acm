#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#define MAXN 16
using namespace std;

int n;
int arr[MAXN];

int main()
{
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", arr+i);
	queue<int> rs;
	for(int i=2; i<=n; i++) {
		rs.push(arr[i]-arr[i-1]);
	}
	int c = 0;
	for(int i=1; !rs.empty(); i++) {
		if(c++) printf(" ");
		printf("%d", rs.front());
		if(i%3 == 0) {
			printf("\n");
			c = 0;
		}
		rs.pop();
	}
	return 0;
}

