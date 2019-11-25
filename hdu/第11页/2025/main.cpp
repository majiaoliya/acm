#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	freopen("test", "r", stdin);
	for(string str; getline(cin, str) && !str.empty(); ) {
		int max_num = str[0];
		for(int i=1; i<str.length(); i++)
			if(str[i] > max_num) 
				max_num = str[i];
		for(int i=0; i<str.length(); i++) {
			printf("%c", str[i]);
			if(str[i] == max_num) 
				printf("(max)");
		}
		printf("\n");
	}
	return 0;
}
