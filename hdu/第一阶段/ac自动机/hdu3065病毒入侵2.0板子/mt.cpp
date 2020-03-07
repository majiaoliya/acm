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

int n, m, T;

int main() {
#ifdef debug
	freopen("test", "w", stdout);
	clock_t stime = clock();
#endif
	srand(time(0));
	n = 1000;
	printf("%d\n", n);
	for(int i=0; i<n; i++) {
		int len = random(48) + 1;
		while(len--) printf("%c", random(26)+'A');
		printf("\n");
	}
	n = 2000000;
	while(n--) printf("%c", random(90)+32);
#ifdef debug
#endif 
	return 0;
}


