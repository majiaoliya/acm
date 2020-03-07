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
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 直接枚举每个银币重量+-的每种情况(24种而已)
 */

int T, w[512];
char lef[128][128], rig[128][128], rs[128][128];

bool check() {
	for(int id=0; id<3; id++) {
		int lsum = 0, rsum = 0;
		for(int i=0; lef[id][i]; i++) lsum += w[(int)lef[id][i]];
		for(int i=0; rig[id][i]; i++) rsum += w[(int)rig[id][i]];
		if(lsum<rsum && rs[id][0]!='d') return false;
		if(lsum==rsum && rs[id][0]!='e') return false;
		if(lsum>rsum && rs[id][0]!='u') return false;
	}
	return true;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	cin >> T;
	while(T--) {
		for(int i=0; i<3; i++) 
			scanf("%s %s %s ", lef[i], rig[i], rs[i]);
		int i;
		for(i='A'; i<='L'; i++) {
			memset(w, false, sizeof(w));
			w[i] = 1; //第i枚是重假币
			if(check()) break;
			w[i] = -1; //第i枚是轻假币
			if(check()) break;
			w[i] = 0;
		}
		printf("%c is the counterfeit coin and it is %s.\n", 
				i, w[i]>0 ? "heavy" : "light");
	}


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


