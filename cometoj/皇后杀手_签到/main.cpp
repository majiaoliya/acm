#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n;

int cmp(string& x, string& y) {
	for(int xi=0, yi=0; xi<x.length() && yi<y.length(); ) {
		if(x[xi] == y[yi]) xi++, yi++;
		else return x[xi] < y[yi];
	}
	return x.length() < y.length();
}

int main(void) {
	freopen("test", "r", stdin);
	string x, y;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> x;
		if(i == 1) y = x;
		else {
			y = cmp(x, y) ? x : y;
		}
	}
	cout << y << endl;
	return 0;
}





























