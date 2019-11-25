#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#define MAXN 16
using namespace std;

int c, n;

int main()
{
	freopen("test", "r", stdin);
	cin >> c >> n;
	for(int i=0; i<(n>>1); i++) {
		for(int k=0; k<(n>>1)-i; k++)
			printf(" ");
		printf("%c", (char)(c+i));
	}
	return 0;
}

