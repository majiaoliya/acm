#include <iostream>
#include <algorithm>
#include <math.h>
#define ll long long int
#define MAXN 5000
using namespace std;

int n, arr[MAXN], an, mod;

bool check(int idx) { //判断是否从第idx个位置开始循环
	bool ok = true;
	for(int i=1, k=idx; i<idx && k<an; i++, k++)
		if(arr[i] != arr[k]) {
			ok = false;
			break;
		}
	return ok;
}

int getloop() {
	for(int i=2; i<an; i++)
		if(check(i)) return i;
	return -1;
}

int main(void) {
	freopen("test", "r", stdin);
	an = 5000;
	arr[1] = 1, arr[2] = 7;
	for(int i=3; i<an; i++)
		arr[i] = (arr[i-2] - (i-1)*(i-1)*(i-1) + (i*i*i) ) % 2009;
#ifdef debug
	printf("%d is start loop\n", getloop());
#endif
	mod = 4018;
	while(~scanf("%d", &n) && n)
		printf("%d\n", arr[n%mod]);
	return 0;
}
