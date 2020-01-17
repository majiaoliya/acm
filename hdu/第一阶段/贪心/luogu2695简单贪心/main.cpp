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
#include <queue>
#define MAXN ((int)1e5+7)
#define ll long long int
#define ld long double
#define QAQ (0)

using namespace std;

//luogu2695
int n, m, a[MAXN], b[MAXN]; 

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d ", a+i);
	for(int i=1; i<=m; i++) scanf("%d ", b+i);
	sort(a+1, a+1+n);
	sort(b+1, b+1+m);
	bool ok = true;

	int sum = 0, i = 1, k = 1;
	while(i<=n && k<=m) {
		if(a[i] <= b[k]) i++, sum += b[k];
		k ++;
	}
	if(i-1 != n) ok = false;

	if(ok) printf("%d\n", sum);
	else printf("you died!\n");
	
	
	
	
	
	
	
	




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


