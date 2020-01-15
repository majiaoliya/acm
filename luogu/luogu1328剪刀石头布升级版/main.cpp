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
#define PARSE(x) ((x>='a' && x<='z') ? x-'a' : x-'A')
#define QAQ (0)

using namespace std;

//这个升级版的剪刀石头布还蛮好玩的

int n, na, nb, a[MAXN], b[MAXN];
int mp[8][8] = {
	{ 0, 0, 1, 1, 0 },
	{ 1, 0, 0, 1, 0 },
	{ 0, 1, 0, 0, 1 },
	{ 0, 0, 1, 0, 1 },
	{ 1, 1, 0, 0, 0 }
};

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d %d ", &n, &na, &nb);
	int lef = 0, rig = 0;
	for(int i=0; i<na; i++) scanf("%d ", a+i);
	for(int i=0; i<nb; i++) scanf("%d ", b+i);
	for(int i=0; i<n; i++) {
		int posa = a[i%na], posb = b[i%nb];
		lef += mp[posa][posb];
		rig += mp[posb][posa];
	}
	printf("%d %d", lef, rig);






	
#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


