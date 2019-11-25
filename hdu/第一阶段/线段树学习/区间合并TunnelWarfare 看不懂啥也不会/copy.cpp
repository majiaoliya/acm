/*
translation:
	打地道战，n个村庄用地道连成一条直线，鬼子有时破坏掉一个村庄，这时八路军要修好这个据点。现在要求询问任意一个村庄，
	得出这个村庄现在与几个村庄相连，包括它本身。
solution:
	线段树维护连续子区间
	将村庄抽象成一个点，正常下值为1,被破坏后变成0,即可将题目抽象成一个求目标节点所在的最长连续1序列的区间的长度。
	所以在线段树里面维护3个信息，前缀最长1序列，后缀最长1序列，以及最长1序列。具体维护的方法看代码。
note:
	*：习得线段树维护连续子区间的正确姿势ORZ
date:
	2016.11.19
*/
#include <iostream>
#include <cstdio>
#include <stack>
 
using namespace std;
const int maxn = 50000 + 5;
 
int n, q;
int s[maxn*4], e[maxn*4];
int preLen[maxn*4], sufLen[maxn*4], maxLen[maxn*4];
 
void build(int o, int l, int r)
{
	s[o] = l;
	e[o] = r;
	preLen[o] = sufLen[o] = maxLen[o] = r - l + 1;
 
	int m = (l + r) >> 1;
	if(l != r){
		build(o << 1, l, m);
		build(o << 1 | 1, m+1, r);
	}
}
 
void pushUp(int o)
{
	preLen[o] = preLen[o << 1];
	sufLen[o] = sufLen[o << 1 | 1];
	maxLen[o] = max(maxLen[o << 1], maxLen[o << 1 | 1]);
	maxLen[o] = max(maxLen[o], sufLen[o << 1] + preLen[o << 1 | 1]);
 
	if(preLen[o<<1] == e[o<<1] - s[o<<1]+1)
		preLen[o] += preLen[o<<1|1];
	if(sufLen[o<<1|1] == e[o<<1|1]-s[o<<1|1]+1)
		sufLen[o] += sufLen[o<<1];
}
 
void update(int o, int k, int v)
{
	if(s[o] == k && e[o] == k){
		preLen[o] = sufLen[o] = maxLen[o] = v;
		return;
	}
	if(s[o] == e[o])	return;
 
	int m = (s[o] + e[o]) >> 1;
	if(k <= m)	update(o << 1, k, v);
	else 		update(o << 1 | 1, k, v);
	pushUp(o);
}
 
int query(int o, int k)
{
	if(s[o] == e[o] || maxLen[o] == 0 || maxLen[o] == e[o] - s[o] + 1)
		return maxLen[o];
 
	int m = (s[o] + e[o]) >> 1;
	int lc = o << 1, rc = o << 1 | 1;
 
	if(k <= m){
		if(k >= e[lc] - sufLen[lc] + 1)	return sufLen[lc] + preLen[rc];
		else							return query(lc, k);
	}else{
		if(k <= s[rc] + preLen[rc] - 1)	return preLen[rc] + sufLen[lc];
		else							return query(rc, k);
	}
}
 
int main()
{
	//freopen("in.txt", "r", stdin);
    while(~scanf("%d%d", &n, &q)){
		build(1, 1, n);
 
		char op;
		int a;
		stack<int> village;
 
		while(q--){
			getchar();
			scanf("%c", &op);
 
			if(op == 'D'){
				scanf("%d", &a);
				village.push(a);
				//printf("push: %d\n", a);
				update(1, a, 0);
			}
			if(op == 'Q'){
				scanf("%d", &a);
				printf("%d\n", query(1, a));
			}
			if(op == 'R'){
				if(!village.empty()){
					a = village.top();
					village.pop();
					//printf("pop: %d\n", a);
					update(1, a, 1);
				}
			}
		}
    }
    return 0;
}
