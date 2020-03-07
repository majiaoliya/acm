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
#define MAXN (500005)
#define ll long long int
#define PARSE_MIN(x) ((x>='a' && x<='z') ? x-('a'-'A') : x)
#define QAQ (0)

using namespace std;

int n, sz;
char buf[MAXN][1024];

struct Node {
	Node* next[128];
	set<int> ids; //存子串下标
	Node() : ids(set<int>()) { memset(next, false, sizeof(next)); }
} root;

void insert(int id, char* s, int lef, int rig) {
	Node* now = &root;
	for(int i=lef; i<=rig; i++) {
		int pos = PARSE_MIN(s[i]); //切成小写
		if(!now->next[pos]) now->next[pos] = new Node();
		now = now->next[pos];
		now->ids.insert(id);
	}
}

set<int> search(char* s, int len) {
	Node* now = &root;
	for(int i=0; i<len; i++) {
		int pos = PARSE_MIN(s[i]);
		if(!now->next[pos]) return set<int>();
		now = now->next[pos];
	}
	return now->ids;
}

int main() {
#ifdef debug
	//freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	FILE* fp = fopen("test", "r");
	while(fgets(buf[++sz], 1024, fp)) {
		int len = strlen(buf[sz]) - 1;
		buf[sz][len] = 0;
//		printf("insert:%s\n", buf[sz]);
		int i = 0;
		while(len>=0 && buf[sz][len]==' ') len --;
		while(i<len && (buf[sz][i]==' ' || buf[sz][i]==9 || 
					buf[sz][i]=='	')) i ++;
		for(; i<len; i++)
			insert(sz, buf[sz], i, len-1);
	}
	printf("finish line %d:\n", sz);
	while(~scanf("%s", buf[0])) {
		int len = strlen(buf[0]);
		auto seta = search(buf[0], len);
		printf("%s\n", buf[0]);
		fflush(stdin);
		printf("size:%d\n", (int)seta.size());
		for(auto x : seta)
			printf("	%d:%s %d\n", x, buf[x], buf[x][0]);
	}


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf \n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


