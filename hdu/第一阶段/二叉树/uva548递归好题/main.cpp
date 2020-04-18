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
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

bool ok = true;
int Q;

int dfs() {
	int W1, W2, D1, D2, lef = 0, rig = 0;
	scanf("%d %d %d %d ", &W1, &D1, &W2, &D2);
	if(W1 && W2){
		if(W1*D1 != W2*D2) ok = false;
		return W1 + W2;
	} else if(W1 && !W2) {
		lef = W1;
		rig = dfs();
		if(lef*D1 != rig*D2) ok = false;
		return lef + rig;
	} else if(!W1 && W2) {
		lef = dfs();
		rig = W2;
		if(lef*D1 != rig*D2) ok = false;
		return lef + rig;
	} else {
		if(!W1) lef = dfs();
		if(!W2) rig = dfs();
		if(lef*D1 != rig*D2) ok = false;
		return lef + rig;
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &Q);
	while(Q--) {
		ok = true;
		dfs();
		printf("%s\n", ok ? "YES" : "NO");
		if(Q) printf("\n");
	}





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


