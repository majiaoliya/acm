#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 45000
#define ll long long int
using namespace std;

ll n, m, arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	for(int i=0; i<MAXN; i++) {
		arr[i] = 0;
		arr[i] = arr[i-1] + i;
		if(i <= 20) printf("%lld  ", arr[i]);
	}
	while(cin>>n>>m && (n+m)) {
		for()
	}
	return 0;
}
