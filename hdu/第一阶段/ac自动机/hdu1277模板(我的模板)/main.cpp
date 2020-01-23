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
#define MAXN ((int)60007)
#define ll long long int
#define QAQ (0)

using namespace std;

//给一个文本text,和一些关键字word[n], 判断某个关键字word[i]是否出现过

int n, m, tn;
vector<int> ans;
char tmp[1024], text[MAXN];

struct Node {
	int id;
	Node* fail;
	Node* next[10];
	Node() { 
		id = 0, fail = nullptr; 
		memset(next, false, sizeof(next));
   	}
//	~Node() { delete fail; for(int i=0; i<26; i++) delete next[i]; }
} *root;

void insert(char* s, int id) {
	Node* now = root;
	int pos;
	for(int i=0; s[i]; i++) {
		pos = s[i] - '0';
		if(!now->next[pos]) now->next[pos] = new Node();
		now = now->next[pos];
	}
	now->id = id;
}

void build_fail() { //bfs构建失配指针
	queue<Node*> q;
	q.push(root);
	root->fail = nullptr;
	while(!q.empty()) {
		auto now = q.front(); q.pop();
		for(int i=0; i<10; i++) 
			if(now->next[i]) {
				Node* p = now->fail;
				while(p && !p->next[i]) p = p->fail;
				now->next[i]->fail = p ? p->next[i] : root;
				q.push(now->next[i]);
			}
	}
}

void ac_find(char* s) {
	Node* now = root;
	for(int i=0; s[i]; i++) {
		int pos = s[i] - '0';
		while(!now->next[pos] && now!=root) now = now->fail;
		now = now->next[pos]==nullptr ? root : now->next[pos];
		Node* tmt = now;
		for( ; tmt!=root; tmt=tmt->fail) 
			if(tmt->id) ans.push_back(tmt->id);
	}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while(~scanf("%d %d ", &n, &m)) {
		tn = 0;
//		delete root;
		root = new Node();
		ans.clear();
		while(n) {
			char ch = getchar();
			if(ch<'0' || ch>'9') n --;
			else text[tn++] = ch;
		}
		getchar();
	//	for(int i=0; i<n; i++) {
	//		scanf("%s ", tmp);
	//		if(i) strcat(text, tmp);
	//		else strcpy(text, tmp);
	//	}
		int id;
		for(int i=1; i<=m; i++) {
			scanf("%s %s %d] %s ", tmp, tmp, &id, tmp);
			insert(tmp, id);
		}
		build_fail();
		ac_find(text);
		if(ans.empty()) printf("No key can be found !\n");
		else {
			printf("Found key:");
			for(auto x : ans)
				printf(" [Key No. %d]", x);
			printf("\n");
		}
	}








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


