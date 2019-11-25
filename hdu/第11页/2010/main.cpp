#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> rs;

bool check(int x) {
	int temp = x, sum = 0;
	while(temp) {
		sum += pow(temp%10, 3);
		temp /= 10;
	}
	return sum == x;
}

int main(void) {
	freopen("test", "r", stdin);
	int m, n;
	for( ; EOF != scanf("%d %d", &m, &n); ) {
		rs.clear();
		bool tag = false;
		for(int i=m; i<=n; i++) {
			if(check(i)) { tag = true; rs.push_back(i); }
		}
		if(tag) {
			for(int i=0, c=0; i<rs.size(); i++) {
				if(c++) printf(" ");
				printf("%d", rs[i]);
			}
			printf("\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}
