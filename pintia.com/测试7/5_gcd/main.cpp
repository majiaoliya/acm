#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n, m;

int gcd(int a, int b) {
	return (b>0) ? gcd(b, a%b) : a;
}

int gb(int a, int b) {
	return (a*b)/gcd(a, b);
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &m);
	printf("%d %d", gcd(n, m), gb(n, m));
	return 0;
}

