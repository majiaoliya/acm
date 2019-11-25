#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)1e6+7)
#include <map>
#include <unordered_set>
#define ll long long int

using namespace std;

int T, n;
char str[MAXN];

#define pp ((int)'p')
#define pi ((int)'i')
#define pn ((int)'n')
#define pk ((int)'k')

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d\n", &T);
	while(T--) {
		scanf("%d\n", &n);
		scanf("%s\n", str+1);
		int mx[512], mn[512];
		for(int i=1; i<=n; i++) mx[i] = -1, mn[i] = MAXN;
		bool vis[512] = { 0 };
		for(int i=1; i<=n; i++) {
//			printf("%d %d\n", mn[pp], mx[pp]);
			if(str[i] == 'p') {
				mx[pp] = max(mx[pp], i);
				mn[pp] = min(mn[pp], i);
				vis[pp] = true;
			}
			if(str[i] == 'i') {
				mx[pi] = max(mx[pi], i);
				mn[pi] = min(mn[pi], i);
				vis[pi] = true;
			}
			if(str[i] == 'n') {
				mx[pn] = max(mx[pn], i);
				mn[pn] = min(mn[pn], i);
				vis[pn] = true;
			}
			if(str[i] == 'k') {
				mx[pk] = max(mx[pk], i);
				mn[pk] = min(mn[pk], i);
				vis[pk] = true;
			}
		}
		int a = mx[pi] - mn[pp] - 1;
		int b = mx[pn] - mn[pi] - 1;
		int c = mx[pk] - mn[pn] - 1;
		printf("%d %d %d\n", a, b, c);
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

