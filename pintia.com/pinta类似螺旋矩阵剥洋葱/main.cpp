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
#include <stack>
#include <time.h>
#define MAXN ((int)1024)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m;
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
char ans[MAXN][MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	cin >> m;
	n = 1 + ((m-1) * 2);
	int cnt = n * n, r = 0, c = 0, i = 0;
	char ch = 'A';
	while(cnt--) {
		ans[r][c] = ch;
		int nr = r+dr[i], nc = c+dc[i];
		if(nr>=n || nc>=n || nr<0 || nc<0 || ans[nr][nc]!=0) {
			i = (i+1) % 4;
			if(i == 0) ch ++;
		}
		
		r = r+dr[i], c = c+dc[i];
	}
	for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++)
			printf("%c", ans[i][k]);
		printf("\n");
	}



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}




