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
#include <math.h>
#include <queue>
#include <stdlib.h>
#define random(x) (rand()%x)
#define MAXN (32)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, T;

int main() {
#ifdef debug
	freopen("test", "w", stdout);
	clock_t stime = clock();
#endif
	srand(time(0));
	int T = 20000;
	printf("%d\n", T);
	while(T--) {
		vector<int> va, vb, vc;
		int na = random(10)+1, nb = random(10)+1, nc = random(10)+1;
		printf("%d %d %d\n", na, nb, nc);
		for(int i=1; i<=na; i++) va.push_back(random(100)-50);
		for(int i=1; i<=nb; i++) vb.push_back(random(100)-50);
		for(int i=1; i<=nc; i++) vc.push_back(random(100)-50);
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());
		sort(vc.begin(), vc.end());

		for(int i=0; i<va.size(); i++) printf("%d ", va[i]);
		printf("\n");
		for(int i=0; i<vb.size(); i++) printf("%d ", vb[i]);
		printf("\n");
		for(int i=0; i<vc.size(); i++) printf("%d ", vc[i]);
		printf("\n");

	}


#ifdef debug
#endif 
	return 0;
}


