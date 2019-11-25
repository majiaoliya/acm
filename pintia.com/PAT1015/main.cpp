#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int n, rad;

bool is_ss(int x) {
	if(x==1 || x==0) return false;
	int t = sqrt(x);
	for(int i=2; i<=t; i++) 
		if(x%i == 0) return false;
	return true;
}

int parse(int num, int rad) {
	string str_rad; // num rad进制
	int tnum = num, sum = 0;
	while(tnum) { //num转成rad进制
		str_rad = to_string(tnum%rad) + str_rad;
		tnum /= rad;
	}
	for(int i=0; i<str_rad.length(); i++) { //rad进制转化为十进制
		sum += (str_rad[i]-'0')*pow(rad, i);
	}
//	printf("%d的%d进制是:%s   %d的十进制%d\n", num, rad, str_rad.data(), num, sum);
	return sum;
}

int main() {
	freopen("test", "r", stdin);
	
	for( ; EOF != scanf("%d", &n) && n>=0; ) {
		scanf("%d", &rad);
		if(is_ss(n) && is_ss(parse(n, rad))) 
			printf("Yes\n");
		else 
			printf("No\n");
	}
	
	return 0;
}
























