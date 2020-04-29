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
#include <math.h>
#include <stack>
#include <queue>
#define MAXN ((int)5e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

int n;
struct node {
	double x, y;
	node(double _x=0, double _y=0) : x(_x), y(_y) { }
	node operator - (const node& no) const { return node{x-no.x, y-no.y}; }
	//重装乘法用于叉乘
	double operator * (const node& no) const { return x*no.y - y*no.x; }
	inline void read() { scanf("%lf %lf ", &x, &y); }
} a[MAXN]; //n个点

int stk[MAXN], top;
bool cmp(node& p1, node& p2) { //用叉乘来排序 避免atan2的精度问题
	return (p1-a[stk[1]]) * (p2-a[stk[1]]) > 0;
}

#define eps (1e-9)

double dis(node& p1, node& p2) {
	return sqrt((p2.y-p1.y)*(p2.y-p1.y)+(p2.x-p1.x)*(p2.x-p1.x));
}

int main() {
#ifdef debug
//	freopen("/home/majiao/下载/P2742_2.in", "r", stdin);
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);
	stk[top=1] = 1;
	for(int i=1; i<=n; i++) { //读入每个点并把最左下角的点设置到栈底
		scanf("%lf %lf ", &a[i].x, &a[i].y);
		if(a[stk[1]].x>a[i].x || 
				(fabs(a[i].x-a[stk[1]].x)<eps && a[i].y<a[stk[1]].y)) {
			stk[1] = i;
		}
	}
	swap(a[stk[1]], a[1]); //设置最左下角的点到栈底
	stk[1] = 1; 
	sort(a+2, a+1+n, cmp); //排序的时候不排最左下角
	for(int i=2; i<=n; i++) {
		//核心部分
		//把所有不满足BA叉乘BC的是逆时针的点B出栈
		while(top>1 && 
				(a[stk[top-1]]-a[stk[top]])*(a[i]-a[stk[top]])>0)
			top --;
		stk[++top] = i; //把点加到栈里
	}
	
	stk[top+1] = 1;
	double ans = 0;
	for(int i=1; i<=top; i++)
		ans += dis(a[stk[i]], a[stk[i+1]]);
	printf("%.2lf", ans);
#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif
	return 0;
}



