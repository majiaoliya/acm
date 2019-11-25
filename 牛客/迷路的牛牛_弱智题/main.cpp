#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 300005
#include <map>
#define ll long long int
#define max(x, y) ( x > y ? x : y )
#define abs(x) ( x > 0 ? x : -x )
using namespace std;

int main() {
	freopen("test", "r", stdin);
	int n, cur = 0;
	char str[1024];
	while(~scanf("%d %s", &n, str)) {
		for(int i=0; i<n; i++) {
			if(str[i] == 'L') cur --;
			else cur ++;
			if(cur == -4 || cur == 4) cur = 0;
		}	
		if(cur == 0) printf("N\n");
		if(cur == -1 || cur == 3) printf("W\n");
		if(cur == 2 || cur == -2) printf("S\n");
		if(cur == 1 || cur == -3) printf("E\n");
	}
	return 0;
}



