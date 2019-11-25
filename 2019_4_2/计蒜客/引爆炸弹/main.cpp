// https://nanti.jisuanke.com/t/A1139
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX (1024<<4)
using namespace std;

int n, m;

int main(void) {
	freopen("test", "r", stdin);
	
	scanf("%d %d", &n, &m);
	cin.ignore();
	string mtx[n];
	for(int i=0; i<n; i++) {
		getline(cin, mtx[i]);
		cout << mtx[i] << endl;
	}
	
	return 0;
}
