#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#define float double
using namespace std;

int table[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
	freopen("test", "r", stdin);
	
	int y, m, d;
	for( ; EOF != scanf("%d/%d/%d", &y, &m, &d); ) {
		if((y%4==0 && y%100) || y%400==0) 
			table[2] = 29;
		int sum = 0;
		for(int i=1; i<m; i++) {
			sum += table[i];
		}
		sum += d;
		table[2] = 28;
		printf("%d\n", sum);
	}
	
	return 0;
}
