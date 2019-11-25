#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#define MAX_SIZE 27
using namespace std;

//题意 : 给定多个字符串, 判断是否有存在一个字符串X是由两个其他字符串合成的 

#define MAXN (int)(5e5+7)
int n, cnt, tree[MAXN][MAX_SIZE];
bool is_end[MAXN];
char str[MAXN][128];

void insert(char* s) {
	int len = strlen(s), root = 0;
	for(int i=0; i<len; i++) {
		int pos = s[i] - 'a';
		if( ! tree[root][pos]) tree[root][pos] = ++cnt;
		root = tree[root][pos];
	}
	is_end[root] = true;
}

bool find(char* s, int lef, int rig) {
	int root = 0;
	for(int i=lef; i<=rig; i++) {
		int pos = s[i] - 'a';
		if( ! tree[root][pos]) return false;
		root = tree[root][pos];
	}
	return is_end[root];
}

int main(void) {
	freopen("test", "r", stdin);
	while(~scanf("%s", str[n])) {
		insert(str[n]);
		n++;
	}
	for(int i=0; i<n; i++) {
		int len = strlen(str[i]);
		for(int mid=0; mid<len-1; mid++) {
			if(find(str[i], 0, mid) && find(str[i], mid+1, len-1)) {
				printf("%s\n", str[i]);
				break;
			}
		}
	}
	return 0;
}
