#define debug 
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#define MAXN (2048)
#define ll long long int
#define uint unsigned int 
#define uchar unsigned char
#define QAQ (0)

using namespace std;

uint n, a[MAXN];

void pit(uint x) {
	uchar* ptr = (uchar*) &x;
	for(int i=3; i>=0; i--) {
		printf("%hhu%c", ptr[i], i==0?'\n':'.');
	}
}

signed main() {
#ifdef debug
	freopen("test", "r", stdin);
	freopen("main_out", "w", stdout);
	clock_t stime = clock();
#endif
	while(~scanf("%u ", &n)) { 
		memset(a, false, sizeof(a));
		uint tmin, tmax;
		int tmp = 32;
		for(int i=1; i<=(int)n; i++) {
			uchar* ptr = (uchar*) (a + i);
			scanf("%hhu.%hhu.%hhu.%hhu ", ptr+3, ptr+2, ptr+1, ptr+0);
			if(i == 1) {
				tmin = a[i];
				tmax = a[i];
			} else {
				tmin = min(tmin, a[i]);
				tmax = max(tmax, a[i]);
				int m = 0, x = a[1], y = a[i];
				for(int k=31; k>=0; k--) {
					bool b = ((x>>k)&1) == ((y>>k)&1);
					if(!b) break;
					m ++;
				}
				tmp = min(m, tmp);
			}
		}
		int mask = 0;
		for(int i=31; tmp--; i--) {
			mask |= (1<<i);
		}
		uint ans1 = tmin & mask;
		pit(ans1);
		pit(mask);
	}






#ifdef debug
	clock_t etime = clock();
#endif 
	return 0;
}









