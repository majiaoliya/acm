#include <stdio.h>
#include <iostream>
#include <string>
#define MAXN 105
using namespace std;

int n, t;
char buf[32];

int main(void) {
	freopen("test", "r", stdin);
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << (a%100 + b%100) % 100 << endl;
	}
	return 0;
}
