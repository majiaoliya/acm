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
#define MAXN (4096)
#define ll long long int
#define QAQ (0)

using namespace std;

int n;

struct Node {
	double x, y;
	Node operator + (Node& no) { return Node{x+no.x, y+no.y}; }
	Node operator - (Node& no) { return Node{x-no.x, y-no.y}; }
	double operator ^ (Node& no) { return x*no.y - y*no.x; } //叉积
} d[MAXN];

struct Line {
	Node A, B, L;
	Line() { }
	Line(Node _A, Node _B) : A(_A), B(_B), L(_B-_A) { }
} l[MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d ", &n);

	for(int i=1; i<=n; i++) 
		scanf("%lf %lf ", &d[i].x, &d[i].y);
	d[n+1] = d[1];
	double ans = 0;
	for(int i=1; i<=n; i++) 
		ans += (d[i] ^ d[i+1]);
	printf("%.0lf\n", fabs(ans)/2);







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


