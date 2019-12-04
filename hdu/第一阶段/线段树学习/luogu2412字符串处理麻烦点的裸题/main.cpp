#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN ((int)5e4+7)
#include <map>
#include <unordered_set>
#define ll long long int
using namespace std;

/**
 * 题意:给定n个字符串,给定Q个查询,每次查询strs[L,R]里字典序最大的那个str
 * 思路:先把字符串备份,排序,映射好下标
 * 		再建线段树 裸模板直接套就行了
 */


#define cmpi (i<(int)str.length() && k<(int)y.str.length())
#define CHAR(x) (x>='A'&&x<='Z' ? x+('a'-'A') : x)

int n, m, arr[MAXN], tree[MAXN<<2];
struct Node {
	int id; //str在原数组中的位置
	string str;
	bool operator < (const Node& y) const { 
		int i = 0, k = 0;
		for( ; cmpi; i++, k++) { //比较字符串要忽略大小写
			char cha = CHAR(str[i]), chb = CHAR(y.str[k]);
			if(cha == chb) continue ;
			return cha < chb;
		}
		return str.length() < y.str.length();
	}
} nodes[MAXN];

string s[MAXN]; //原字符串数组

inline void push_up(int rt) { tree[rt] = max(tree[rt<<1], tree[rt<<1|1]); }

void build(int rt, int lef, int rig) {
	if(lef == rig) {
		tree[rt] = arr[lef];
		return ;
	}
	int mid = (lef + rig) >> 1;
	build(rt<<1, lef, mid);
	build(rt<<1|1, mid+1, rig);
	push_up(rt);
}

int L, R;
int query(int rt, int lef, int rig) {
	if(L<=lef && rig<=R) return tree[rt];
	int mid = (lef + rig) >> 1, ret = 0;
	if(L <= mid) ret = query(rt<<1, lef, mid);
	if(mid < R) ret = max(ret, query(rt<<1|1, mid+1, rig));
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> nodes[i].str;
		s[i] = nodes[i].str;
		nodes[i].id = i;
	}
	sort(nodes+1, nodes+1+n);
	for(int i=1; i<=n; i++) arr[nodes[i].id] = i;
	build(1, 1, n);
	for(int i=1; i<=m; i++) {
		cin >> L >> R;
		cout << s[nodes[query(1, 1, n)].id] << endl;
	}
	







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

