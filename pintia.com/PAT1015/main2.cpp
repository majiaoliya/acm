#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;
int n, rad;

int parse(int num, int rad) { //10进制num转rad进制
	int tnum = num;
	stack<int> s; //r进制的num翻转
	while(tnum) {
		s.push(tnum%rad);
		tnum /= rad;
	}
	int sum = 0;
	for(int i=0; !s.empty(); i++) { //r进制的数转成十进制
		sum += s.top()*(pow(rad, i));
		s.pop();
	}
//	cout << sum << endl;
	return sum;
}

bool is_ss(int num) {
	if(num==0 || num==1) return 0;
	int t = sqrt(num);
	for(int i=2; i<=t; i++) 
		if(num%i == 0) return false;
	return true;
}

int main() {
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d", &n) && n>0; ) {
		scanf("%d", &rad);
		if(is_ss(n) && is_ss(parse(n, rad))) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	
	return 0;
}
























