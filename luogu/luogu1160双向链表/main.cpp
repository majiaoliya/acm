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
#include <stack>
#include <queue>
#define MAXN ((int)1e6+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n, m, x, y, tot, head = 1;
struct Node {
	int val, pre, nxt;
} a[MAXN];

int mp[MAXN], vis[MAXN];

void insert(int x, int y) {
	++ tot;
	a[tot].val = tot;
	if(y) { //在x的右边插入
		a[tot].nxt = a[x].nxt;
		a[x].nxt = tot;
		a[tot].pre = x;
		if(a[tot].nxt) a[a[tot].nxt].pre = tot;
	} else { //在x的左边插入
		a[tot].pre = a[x].pre;
		a[x].pre = tot;
		a[tot].nxt = x;
		if(a[tot].pre) a[a[tot].pre].nxt = tot;
		else head = tot;
	}
}

void del(int x) { //删除链表已有的x
	if(!vis[x]) return ;
	vis[x] = false;
	if(!a[x].pre) head = a[x].nxt; //删除链表头时要把头往下指
	if(!a[x].nxt) { //链表尾
		if(a[x].pre) 
			a[a[x].pre].nxt = 0;
		return ;
	}
	a[a[x].pre].nxt = a[x].nxt;
	a[a[x].nxt].pre = a[x].pre;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	a[++tot].val = 1;
	vis[1] = true;
	scanf("%d ", &n);
	for(int i=1; i<n; i++) {
		scanf("%d %d ", &x, &y);
		vis[i+1] = true;
		insert(x, y);
	}
	//for(int i=head; i; i=a[i].nxt)
	//	if(a[i].val) printf("[%d,%d,%d],", a[i].pre, a[i].val, a[i].nxt);
	scanf("%d ", &m);
	while(m--) {
		scanf("%d ", &x);
		del(x);
	}
	for(int i=head; i; i=a[i].nxt)
		if(a[i].val) printf("%d ", a[i].val);






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


