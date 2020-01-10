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
#define MAXN ((int)1e5+7)
#define ll unsigned long long int
#define uchar unsigned char
#define QAQ (0)

using namespace std;

template <typename T>
void printll(T x) {
	vector<int> vec(sizeof(T)*8, false);
	int ptr = vec.size() - 1;
	while(ptr >= 0) {
		vec[ptr] = x & 1;
		ptr --;
		x >>= 1;
	}
	forvec(vec);
}

void puchar(uchar ch) {
	vector<int> vec(8, false);
	for(int i=7; i>=0; i--) {
		vec[i] = (ch & 1);
		ch >>= 1;
	}
	forvec(vec);
}

char buf[MAXN][512];

/**
 *  UTF-8最多可用到6个字节
	如表： 
	1字节 0xxxxxxx   (注意单字节是0个1  k字节就是k个前导1)
	2字节 110xxxxx 10xxxxxx 
	3字节 1110xxxx 10xxxxxx 10xxxxxx 
	4字节 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx 
	5字节 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 
	6字节 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 
 */
ll get_word(uchar* buf, int& lef) { //从缓冲区里读一个"字"
	ll ret = 0;
	uchar* ptr = (uchar*) &ret;
	uchar tmp = buf[lef++];
	*ptr = tmp, ptr ++;
	if((tmp>>7) & 1) {
		tmp <<= 1;
		while((tmp>>7) & 1) {
			*ptr = buf[lef++], ptr ++;
			tmp <<= 1;
		}
	}
	return ret;
}

struct Node;
typedef std::map<ll, Node*> NTable;
struct Node {
	int id;
	NTable next;
	Node() : id(false) { }
} root;

void pword(ll x) {
	char* ptr = (char*)&x;
	for(int i=0; i<8; i++) printf("[%d]", (unsigned int)*(ptr+i));
	printf("\n");
}

typedef std::set<Node>::iterator ITE;
void insert(char* str, int sid, int rig=0) {
	Node* now = &root;
	int len = rig ? rig : strlen(str);
	int num = 0;
	for(int i=0; i<len; ) {
		ll key = get_word((uchar*)str, i);
#ifdef debug2
		pword(key);
#endif
		if(now->next.find(key) == now->next.end())
			now->next[key] = new Node();
		num = key;
		now = now->next[key];
	}
	now->id = sid;
}

ll searchit(uchar* buf) {
	Node* now = &root;
	ll num = 0;
	for(int i=0; buf[i]; ) {
		ll word = get_word((uchar*)buf, i);
		if(now->next.find(word) == now->next.end()) return false;
		now = now->next[word];
		num = word;
	}
	return now->id;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	int T;
	scanf("%d ", &T);
	int id = 1;
	while(T--) {
		scanf("%s ", buf[id]);
		int len = strlen(buf[id]);
		for(int i=0; i<len; ) { //输入所有前缀到字典树
			insert(buf[id]+i, id);
			get_word((uchar*)buf[id], i);
		}
		id ++;
	}
	scanf("%d ", &T);
	while(T--) {
		scanf("%s ", buf[0]);
		int id = searchit((uchar*)buf[0]);
		printf("%s %s\n", buf[0], id ? buf[id] : "null");
	}




#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

