#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <queue>
#define MAXN ((int)1e6+7)
#define ll long long int
#define QAQ (0)

using namespace std;

//kmp统计出现次数

int nxt[MAXN], tlen, plen;
char text[MAXN], pa[MAXN];

void get_next() {
	nxt[0] = nxt[1] = 0;
	int k = 0;
	for(int i=1; i<plen; i++) {
		while(k && pa[i]!=pa[k]) k = nxt[k];
		nxt[i+1] = (pa[i] == pa[k] ? ++k : 0);
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%s %s ", text, pa)) {
		tlen = strlen(text), plen = strlen(pa);
		get_next();
		int k = 0, ans = 0;
		for(int i=0; i<tlen; i++) {
			while(k && text[i]!=pa[k]) k = nxt[k];
			k += text[i]==pa[k] ? 1 : 0;
			if(k == plen) ans ++;
		}
		printf("%d\n", ans);
	}




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


