#include <iostream>
#include <math.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n;
int num; //分块的个数
int belong[MAXN]; //表示i属于那一块
int block; //表示每一块的大小
int l[MAXN], r[MAXN]; //第i个数的所在块的左右边界

void build() {
	block = sqrt(n);
	num = n/block;
	if(n%block) num ++;
	for(int i=1; i<=num; i++) //for每块设置左右边界
		l[i] = (i-1)*block+1, r[i] = i*block;
	r[num] = n;
	for(int i=1; i<=n; i++) //每个数字属于那一块
		belong[i] = (i-1)/block+1;
}

int main(void) {
	
	return 0;
}
