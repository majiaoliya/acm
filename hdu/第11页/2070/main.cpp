#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 55
#define ll long long int
using namespace std;

int n, m;
ll fb[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	fb[1] = fb[2] = 1;
	for(int i=3; i<MAXN; i++)
		fb[i] = fb[i-1] + fb[i-2];
	while(cin>>n && n!=-1) {
		printf("%lld\n", fb[n]);
	}
	return 0;
}
