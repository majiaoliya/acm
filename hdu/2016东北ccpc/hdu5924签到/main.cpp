#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long int
#define REVERSE { neg = !neg; }
using namespace std;

int main(void) {
	int t;
	ll n;
	freopen("test", "r", stdin);
	cin>>t;
	for(int i=1; i<=t; i++) {
		ll lef, rig;
		cin >> lef >> rig;
		printf("Case #%d:\n", i);
		if(lef == rig) {
			printf("1\n%lld %lld\n", lef, rig);
		} else {
			printf("2\n%lld %lld\n%lld %lld\n", lef, rig, rig, lef);
		}
	}
	return 0;
}
