#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#define MAX_SIZE 4
#define MAXN (int)(1e5+7)
using namespace std;

//题意 : 有前缀输出not 

int n, flag = true, tree[MAXN][MAX_SIZE], cnt;
bool is_end[MAXN];
char str[25];

void init() {
	memset(tree, false, sizeof(tree));
	memset(is_end, false, sizeof(is_end));
	cnt = 0;
	flag = true;
}

bool insert(char* s) { //字典树板子
	int root = 0, mark = false, len = strlen(s);
	for(int i=0; i<len; i++) {
		int pos = s[i] - '0';
		if( ! tree[root][pos]) {
			mark = true;
			tree[root][pos] = ++cnt;
		}
		root = tree[root][pos];
		if(is_end[root]) return false;
	}
	is_end[root] = true;
	return mark;
}

int main(void) {
	freopen("test", "r", stdin);
	int cases = 0;
	while(true) {
		if(scanf("%s", str) == EOF) break;
		if(str[0] == '9') {
			printf("Set %d is %simmediately decodable\n", ++cases, flag ? "":"not ");
			init();
			continue ;
		}
//		printf("%s\n", str);
		if(flag) flag = insert(str);
	}
	return 0;
}
