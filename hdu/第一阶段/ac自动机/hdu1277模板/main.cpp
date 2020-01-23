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
#include <stdlib.h>
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)
#define ld long double
#define OO (0x3f3f3f3f)

using namespace std;
int n, m, l;
vector<int> out; 

/** 
 * 给定一些关键字, 和一个长文本,
 * 问那些关键字出现了
 * ac自动机板子
 */
struct node {
	node* next[10], *fail;
	int id;
	node() {
		memset(next, false, sizeof(next));
		fail = 0;
		id = 0;
	}
} *head;
char tmp[MAXN], si[MAXN], pi[MAXN];

void build(char* s, node* head, int id) { //insert 
	int l = strlen(s), k;
	for(int i=0; i<l; i++) {
		k = s[i] - '0';
		if(head->next[k] == nullptr)
			head->next[k] = new node();
		head = head->next[k];
	}
	head->id = id;
}

void build_fail(node* head) {
	node *now, *p;
	queue<node*> q;
	head->fail = nullptr;
	q.push(head);
	for( ; !q.empty(); ) {
		now = q.front(); q.pop();
		for(int i=0; i<10; i++) 
			if(now->next[i]) {
				p = now->fail;
				for( ; p && !p->next[i]; p=p->fail) ;
				now->next[i]->fail = p ? p->next[i] : head;
				q.push(now->next[i]);
			}
	}
}

int flag = true;
void ac_find(char* s, node* head) {
	int len = strlen(s);
	node* p = head;
	for(int i=0; i<len; i++) {
		int k = s[i] - '0';
		for( ; !p->next[k] && p!=head; p=p->fail) ;
		p = p->next[k]==nullptr ? head : p->next[k];
		node* tmt = p;
		for( ; tmt!=head; tmt=tmt->fail)
			if(tmt->id) {
				out.push_back(tmt->id);
				flag = false;
			}
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m)) {
		out.clear();
		head = new node();
		for(int i=0; i<n; i++) {
			scanf("%s ", tmp);
			if(i == 0) strcpy(si, tmp);
			else strcat(si, tmp);
		}
		for(int i=1; i<=m; i++) {
			scanf("%s ", pi);
			scanf("%s ", pi);
			scanf("%d] %s ", &l, pi);
			build(pi, head, i);
		}
		build_fail(head);
		ac_find(si, head);
		if(out.empty()) printf("No key can be found !\n");
		else {
			printf("Found key:");
			for(auto x : out)
				printf(" [Key No. %d]", x);
			printf("\n");
		}
	}





#ifdef debug
	clock_t etime = clock();
#endif 
	return 0;
}







