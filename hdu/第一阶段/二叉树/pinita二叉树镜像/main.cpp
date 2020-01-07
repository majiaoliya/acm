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
 * 给定两个二叉树判断他们是否互为镜像
 * 算法一: 先翻转第一科树得到新树, 比较新树和另一颗树的先序遍历中序遍历
 */

int n, m, visa[MAXN], visb[MAXN], ok;
struct Node {
	char ch, lef, rig;
	Node() : ch('-'), lef('-'), rig('-') { }
} ta[MAXN], tb[MAXN];

void swapit(int now) {
	if(ta[now].ch == '-') return ;
	swapit(ta[now].lef);
	swapit(ta[now].rig);
	swap(ta[now].lef, ta[now].rig);
}

void dfs_pre(Node* arr, int now, vector<char>& vec) {
	if(arr[now].ch == '-') return ;
	vec.push_back(arr[now].ch);
	dfs_pre(arr, arr[now].lef, vec);
	dfs_pre(arr, arr[now].rig, vec);
}
void dfs_in(Node* arr, int now, vector<char>& vec) {
	if(arr[now].ch == '-') return ;
	dfs_in(arr, arr[now].lef, vec);
	dfs_in(arr, arr[now].rig, vec);
	vec.push_back(arr[now].ch);
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

	scanf("%d ", &n);
	for(int i='0'; i<'0'+n; i++) {
		scanf("%c %c %c ", &ta[i].ch, &ta[i].lef, &ta[i].rig);
		if(ta[i].lef != '-') visa[(int)ta[i].lef] = true;
		if(ta[i].rig != '-') visa[(int)ta[i].rig] = true;
	}
	scanf("%d ", &m);
	for(int i='0'; i<'0'+m; i++) {
		scanf("%c %c %c ", &tb[i].ch, &tb[i].lef, &tb[i].rig);
		if(tb[i].lef != '-') visb[(int)tb[i].lef] = true;
		if(tb[i].rig != '-') visb[(int)tb[i].rig] = true;
	}
	if(n != m) { printf("No\n"); return 0; }
	int ra = '0', rb = '0';
	for(int i='0'; i<'0'+n; i++) {
		if(!visa[i]) ra = i;
		if(!visb[i]) rb = i;
	}
	swapit(ra);
	vector<char> apre, ain, bpre, bin;
	dfs_pre(ta, ra, apre);
	dfs_pre(tb, rb, bpre);
	dfs_in(ta, ra, ain);
	dfs_in(tb, rb, bin);
	ok = true;
#ifdef debug
	forvec(apre);
	forvec(bpre);
	forvec(ain);
	forvec(bin);
#endif
	for(int i=0; i<(int)apre.size(); i++)
		if(apre[i] != bpre[i]) ok = false;
	for(int i=0; i<(int)ain.size(); i++)
		if(ain[i] != bin[i]) ok = false;
	printf("%s\n", ok ? "Yes" : "No");


#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


