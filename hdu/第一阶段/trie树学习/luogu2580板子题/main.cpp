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
#define QAQ (0)

using namespace std;

/**
 * 字典树板子题:给出一堆单词和一大堆查询
 */

int n, m;
char buf[64];
struct Node {
	char is_end;
	Node* chls[27];
	Node() { is_end = 0; memset(chls, false, sizeof(chls)); }
} root;

void insert(Node* root, char* buf) {
	auto now = root;
	for(int i=0; buf[i]; i++) {
		int pos = buf[i] - 'a';
		if(!now->chls[pos]) now->chls[pos] = new Node();
		now = now->chls[pos];
	}
	now->is_end = true;
}

char search_str(Node* root, char* buf) {
	auto now = root;
	for(int i=0; buf[i]; i++) {
		int pos = buf[i] - 'a';
		if(!now->chls[pos]) return false;
		now = now->chls[pos];
	}
	return now->is_end;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	for(int i=1; i<=n; i++) {
		scanf("%s ", buf);
		insert(&root, buf);
	}
	scanf("%d ", &m);
	map<string, int> mp;
	while(m--) {
		scanf("%s ", buf);
		auto flag = search_str(&root, buf);
		if(flag == 0) printf("WRONG\n");
		else if(flag == 1) {
			int& rx = mp[buf];
			if(rx == 1) printf("REPEAT\n");
			else {
				rx = 1;
				printf("OK\n");
			}
		}
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


