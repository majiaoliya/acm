#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 26
using namespace std;

const int MAXN = 2e6+5; //64MB
int tree[MAXN][30];
bool flagg[MAXN];

int tot;

inline void init() {
	memset(tree, false, sizeof(tree));
	memset(flagg, false, sizeof(flagg));
	tot = 0;
}

void insert_(char* str) {
	int len = strlen(str);
	int root = 0;
	for(int i=0; i<len; i++) {
		int id =str[i] - '0';
		if(!tree[root][id]) tree[root][id] = ++tot;
		root = tree[root][id];
	}
	flagg[root] = true;
}

bool find_(const char* str) {
	int len = strlen(str);
	int root = 0;
	for(int i=0; i<len; i++) {
		int id = str[i] - '0';
		if(!tree[root][id]) return false;
		root = tree[root][id];
	}
	return true;
}

int main(void) {

	char s[6][10] = { "java", "ps", "php", "ui", "css", "js" };
	for(int i=0; i<6; i++)
		insert_(s[i]);
	printf("java: %d  jav: %d   fuck:%d\n", find_("java"), find_("jav"), find_("fuck"));

	return 0;
}
