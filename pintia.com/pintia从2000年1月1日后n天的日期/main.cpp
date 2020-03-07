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
#include <set>
#include <math.h>
#define MAXN ((int)4096)
#define IS_PRIME(x) (!vis[x])
#define ll long long int
#define QAQ (0)
//#pragma GCC optimize(2)

using namespace std;

int n, T;
int arr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
string str[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#define check(x) ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	freopen("out1", "w", stdout);
	clock_t stime = clock();
#endif
	while(~scanf("%d ", &n) && (-1!=n)) {
		int year = 2000, mon = 1, day = 1, week = (n+6)%7;
		for( ; ; ) {
			if(check(year)) {
				if(n >= 366) n -= 366, year ++;
				else break;
			} else {
				if(n >= 365) n -= 365, year ++;
				else break;
			}
		}
		arr[1] = check(year) ? 29 : 28;
		for(int i=0; i<12 && (n)>=arr[i]; i++)
			n -= arr[i], mon ++;
//		printf("%d-%02d-%02d %s\n", year, mon, day+n, str[week].data());
		printf("%d-%02d-%02d %s%s\n", year, mon, day+n, str[week].data(),
				check(year) ? "润" : "平");
	}
	




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}












