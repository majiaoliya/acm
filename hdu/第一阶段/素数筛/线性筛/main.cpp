#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <time.h>
#define MAXN ((int)1e8+7)
using namespace std;

//线性筛法求素数
int n = 50;
int prime[MAXN], vis[MAXN], pn = 0;
void func() {
	for(int i=2; i<=n; i++) {
		if(!vis[i]) {
			prime[pn++] = i;
		}
		for(int j=0; j<pn && i*prime[j]<=n; j++) {
			vis[i*prime[j]] = 1;
			if(i%prime[j] == 0)
				break;
		}
	}
}

int main(void) {
	n = 1e8;
	clock_t s = time(0);
	func();
	clock_t e = time(0);
	cout << e-s << " size:" << pn << endl;
	//for(int i=0; i<pn; i++) {
	//	printf("%d,", prime[i]);
	//}
	
	return 0;
}
