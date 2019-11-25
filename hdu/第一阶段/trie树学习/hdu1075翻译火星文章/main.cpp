#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <sstream>
#define MAXN 10005
using namespace std;

#define MAX_SIZE 26
//题目意思 : 给定一个字典 要求翻译一篇文章

char s1[30], s2[30];

struct Node {
	bool is_end;
	char val[30];
	Node* next[MAX_SIZE];

	Node() : is_end(false) { val[0]=0; memset(next, false, sizeof(next)); }
	~Node() { 
		for(int i=0; i<MAX_SIZE; i++) 
			if(next[i])
	   			delete next[i];
   	}
} *root;

void insert(char* s1, char* s2) {
	Node* p = root;
	for(int i=0; *(s2+i); i++) {
		int pos = s2[i] - 'a';
		if( ! p->next[pos]) p->next[pos] = new Node;
		p = p->next[pos];
	}
	p->is_end = true;
	strcpy(p->val, s1);
}

char* find(char* s) {
	Node* p = root;
	for(int i=0; *(s+i); i++) {
		int pos = s[i] - 'a';
		if( ! p->next[pos]) return s;
		p = p->next[pos];
	}
	return p->is_end ? p->val : s;
}

char line[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	root = new Node;
	while(EOF != scanf("%s", s1)) {
//		printf("try insert (%s %s)\n", s1, s2);
		if(strcmp(s1, "START") == 0) continue ;
		else if(strcmp(s1, "END") == 0) break ;
		scanf("%s", s2);
		insert(s1, s2);
	}
	getchar();
	while(cin.getline(line, MAXN)) {
		if(strcmp(line, "START") == 0) continue ;
		else if(strcmp(line, "END") == 0) break;
		int cnt = 0;
		char word[30];
		for(int i=0; *(line+i); i++) {
			if('a'<=line[i] && line[i]<='z') {
				word[cnt++] = line[i];
				word[cnt] = 0;
			} else {
				if(cnt) printf("%s", find(word));
				printf("%c", line[i]);
				cnt = 0;
			}
		}
		if(cnt) printf("%s", find(word));
		printf("\n");
	}

	return 0;
}
