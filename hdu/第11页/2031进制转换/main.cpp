#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
using namespace std;

int n, m;
int table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF!=scanf("%d %d", &n, &m); ) {
		stack<int> s;
		int tn = abs(n), tm = m;
		while(tn) {
			s.push(tn%m);
			tn /= m;
		}
		int c = 0;
		while(!s.empty()) {
			if(!c++ && n<0) printf("-");
			printf("%c", table[s.top()]);
			s.pop();
		}
		printf("\n");
	}
	return 0;
}
