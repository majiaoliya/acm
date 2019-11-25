#include <iostream>
using namespace std;

/** 统计某个数的二进制共有多少个1(比如13) */
/**
	x & 0 = 0 //任何数字和 0 按位与都是 0
    x & 1 = x //任何数字和 1 按位与都是 本身
*/

int countOne(int x) {
	int cnt = 0;
	while(x) {
		if(x&1) cnt ++;
		x >>= 1;
	}
	return cnt;
}

int countOne2(int a) { //超高效 神仙解法
	int m1 = 0x55555555;
	int m2 = 0x33333333;
	int m4 = 0x0f0f0f0f;
	int m8 = 0x00ff00ff;
	int m16 = 0x0000ffff;
	
	int b = (a&m1) + ((a>>1)&m1);
	int c = (b&m2) + ((b>>2)&m2);
	int d = (c&m4) + ((c>>4)&m4);
	int e = (d&m8) + ((d>>8)&m8);
	int f = (e&m16) + ((e>>16)&m16);
	
	return f;
}

int main(void) {
	
	int x = 17;
	cout << countOne2(x);
	
	return 0;
}
