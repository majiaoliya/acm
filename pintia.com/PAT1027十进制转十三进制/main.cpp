#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

int n;

int table[] = {'0','1','2','3','4','5','6','7','8','9', 'A', 'B', 'C'};

void parse(int num) { //十进制转十三进制
	stack<int> stk;
	int tnum = num;
	while(tnum) {
		stk.push(tnum%13);
		tnum /= 13;
	}
	int count = stk.size();
	for( ; count<2; count++)
		printf("0");
	while(!stk.empty()) {
		count ++;
		printf("%c", table[stk.top()]), stk.pop();
	}
}

int main() {
	freopen("test", "r", stdin);
	printf("#");
	for(int i=1; i<=3; i++) {
		scanf("%d", &n);
		parse(n);
	}
	return 0;
}
























