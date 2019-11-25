#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#define float double
using namespace std;

float my_abs(float x) { return x > 0 ? x : -x; }

int main(void) {
	freopen("test", "r", stdin);
	int num;
	for( ; EOF != scanf("%d", &num); ) {
		char rs = 'F';
		if(num>=90 && num<=100) {
			rs = 'A';
		} else if(num>=80 && num<=89) {
			rs = 'B';
		} else if(num>=70 && num<=79) {
			rs = 'C';
		} else if(num>=60 && num<=69) {
			rs = 'D';
		} else if(num>=0 && num<=59) {
			rs = 'E';
		}
		if(rs=='F')
			printf("Score is error!\n");
		else 
			printf("%c\n", rs);
	}
	return 0;
}
