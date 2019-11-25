#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#define MAXN 105
using namespace std;

int arr[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	int n;
	cin >> n;
	string text;
	for( ; n--; ) {
		cin >> text;
		int count = 0;
		for(int i=0; i<text.length(); i++) 
			if(text[i]>='0' && text[i]<='9') count ++;
		printf("%d\n", count);
	}
	return 0;
}
