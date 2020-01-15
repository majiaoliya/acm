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
#define MAXN (32)
#define ll long long int
#define PARSE(x) ((x>='a' && x<='z') ? x-'a' : x-'A')
#define QAQ (0)

using namespace std;

ll n, m, q;
char table[MAXN][MAXN], mp[MAXN][MAXN];
string key, src;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	cin >> key >> src;
	while(key.length() < src.length()) key += key;
	for(int i=0; i<26; i++) {
		for(int k=0; k<26; k++) {
			int pos = (i + k) % 26;
			table[i][k] = pos + 'A'; //正向对比表
			mp[i][pos] = k + 'A'; //逆向对比表
		}
	}
#ifdef debug
	for(int i=0; i<26; i++) {
		for(int k=0; k<26; k++) {
			printf("%c ", mp[i][k]);
		}
		printf("\n");
	}
#endif
	for(int i=0; i<(int)src.length(); i++) {
		int offset = src[i] - 'A';
		int a = PARSE(key[i]); //key[i]
		int b = PARSE(src[i]); //src[i]
		char ch = mp[a][b];
		printf("%c", (src[i]>='a' && src[i]<='z') ? ch+('a'-'A') : ch);
	}



#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


