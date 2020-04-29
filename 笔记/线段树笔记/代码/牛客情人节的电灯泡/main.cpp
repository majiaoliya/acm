//#define debug
//#ifdef debug
//#include <time.h>
//#include "/home/majiao/mb.h"
//#endif
//
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string.h>
//#include <map>
//#include <set>
//#include <stack>
//#include <queue>
//#define MAXN (1024)
//#define ll long long int
//#define QAQ (0)
//
//using namespace std;
//
//#include <stdlib.h>
//
//int min4(int a, int b, int c, int d) {
//	return min(a, min(b, min(c, d)));
//}
//
//int max4(int a, int b, int c, int d) {
//	return max(a, max(b, max(c, d)));
//}
//
//struct Node {
//	int val, r1, c1, r2, c2;
//	Node* a[4];
//	Node(int _val=0, int _r1=1, int _c1=MAXN, int _r2=1, int _c2=MAXN)
//	   	: val(_val), r1(_r1), c1(_c1), r2(_r2), c2(_c2)
//	{ memset(a, false, sizeof(a)); }
//	
//	bool point_in(int r, int c) {
//		return r>=r1 && r<=r2 && c>=c1 && c<=c2;
//	}
//	bool in_rect(int _r1, int _c1, int _r2, int _c2) {
//		return r1<=_r1&&_r1<=r2 && c1<=_c1&&_c1<=c2
//			&& r1<=_r2&&_r2<=r2 && c1<=_c2&&_c2<=c2;
//	}
//	bool hav_equal(int _r1, int _c1, int _r2, int _c2) {
//		if(r1<=_r1&&_r1<=r2&&c1<=_c1&&_c1<=c2
//				&& r1<=_r2&&_r2<=r2&&c1<=_c2&&_c2<=c2) return true;
//		if(_r1<=r1&&r1<=_r2&&_c1<=c1&&c1<=_c2
//				&& _r1<=r2&&r2<=_r2&&_c1<=c2&&c2<=_c2) return true;
//		int w1, w2, h1, h2, W, H;
//		w1 = abs(r2 - r1) + 1;
//		w2 = abs(_r2 - _r1) + 1;
//		h1 = abs(c1 - c2) + 1;
//		h2 = abs(_c1 - _c2) + 1;
//		W = abs(min4(r1, r2, _r1, _r2) - max4(r1, r2, _r1, _r2)) + 1;
//		H = abs(min4(c1, c2, _c1, _c2) - max4(c1, c2, _c1, _c2)) + 1;
//		return w1+w2<W && h1+h2<H;
//
//	}
//} *root = new Node();
//
//int mtx[MAXN][MAXN];
//
//void build(Node*&now, int r1, int c1, int r2, int c2) {
//	if(r2 < r1 || c2 < c1) return ;
//#ifdef debug2
//	printf("(%d %d) (%d %d)\n", r1, c1, r2, c2);
//	printf("--(%d %d) (%d %d)\n", r1, c1, (r1+r2)/2, (c1+c2)/2);
//	printf("--(%d %d) (%d %d)\n", r1, (c1+c2)/2+1, (r1+r2)/2, c2);
//	printf("--(%d %d) (%d %d)\n", (r1+r2)/2+1, c1, r2, (c1+c2)/2);
//	printf("--(%d %d) (%d %d)\n", (r1+r2)/2+1, (c1+c2)/2+1, r2, c2);
//#endif
//
//	if(!now) now = new Node(0, r1, c1, r2, c2);
//	if(r1==r2 && c1==c2) {
//		now->val = mtx[r1][c1];
//		return ;
//	}
//	build(now->a[0], r1, c1, (r1+r2)/2, (c1+c2)/2);
//	build(now->a[1], r1, (c1+c2)/2+1, (r1+r2)/2, c2);
//	build(now->a[2], (r1+r2)/2+1, c1, r2, (c1+c2)/2);
//	build(now->a[3], (r1+r2)/2+1, (c1+c2)/2+1, r2, c2);
//	for(int i=0; i<4; i++)
//		now->val += now->a[i] ? now->a[i]->val : 0;
//}
//
//int key, R, C, R2, C2, n, m;
//void update(Node*& now) {
//	if(!now) return ;
//	if(now->r1==now->r2 && now->c1==now->c2 && now->r1==R && now->c1==C) {
//		//printf("%d %d (%d %d) (%d %d)\n", 
//		//		R, C, now->r1, now->c1, now->r2, now->c2);
//		now->val = !now->val;
//		return ;
//	}
//	now->val = 0;
//	for(int i=0; i<4; i++) {
////		printf("point_in(%d) %d\n", i, now->a[i]->point_in(R, C));
//		if(!now->a[i]) continue ;
//		if(now->a[i]->point_in(R, C)) update(now->a[i]);
//		now->val += now->a[i]->val;
//	}
//}
//
////用多个树节点拼出一个大矩形
//int query(Node*& now, int r1, int c1, int r2, int c2) {
//	if(!now || !now->hav_equal(r1, c1, r2, c2)) return 0;
//	if(now->in_rect(r1, c1, r2, c2)) {
//		printf("in_read() + %d\n", now->val);
//		return now->val;
//	}
//	int ret = 0;
//	if(now->a[0]->hav_equal(r1, c1, (r1+r2)/2, (c1+c2)/2))
//		ret += query(now->a[0], r1, c1, (r1+r2)/2, (c1+c2)/2);
//	if(now->a[1]->hav_equal(r1, (c1+c2)/2+1, (r1+r2)/2, c2))
//		ret += query(now->a[1], r1, (c1+c2)/2+1, (r1+r2)/2, c2);
//	if(now->a[2]->hav_equal((r1+r2)/2+1, c1, r2, (c1+c2)/2))
//		ret += query(now->a[2], (r1+r2)/2+1, c1, r2, (c1+c2)/2);
//	if(now->a[3]->hav_equal((r1+r2)/2+1, (c1+c2)/2+1, r2, c2))
//		ret += query(now->a[3], (r1+r2)/2+1, (c1+c2)/2+1, r2, c2);
//	return ret;
//}
//
//int main() {
//#ifdef debug
//	freopen("test", "r", stdin);
//	clock_t stime = clock();
//#endif
//	scanf("%d %d ", &n, &m);
//	for(int i=1; i<=n; i++)
//		for(int k=1; k<=n; k++)
//			scanf("%d ", &mtx[i][k]);
//	build(root, 1, 1, n, n);
//	while(m--) {
//		int op;
//		scanf("%d ", &op);
//		if(op == 1) {
//			scanf("%d %d ", &R, &C);
//			update(root);
//		} else {
//			scanf("%d %d %d %d ", &R, &C, &R2, &C2);
//			printf("%d\n", query(root, R, C, R2, C2));
//		}
//	}
//
//
//
//
//
//#ifdef debug
//	clock_t etime = clock();
//	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
//#endif 
//	return 0;
//}
//















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
#define MAXN ((int)2e4+7)
#define ll long long int
#define QAQ (0)
using namespace std;

int n, sz;
int x, y, val;
int x1, x2, y1, y2;

struct Node { //四分树
	int x1, x2, y1, y2, sum;
	Node(int _x1=1, int _x2=1024, int _y1=1, int _y2=1024) :
		x1(_x1), x2(_x2), y1(_y1), y2(_y2), sum(0) { }
	Node* chl[4]; //横竖切分成四个块a,b,c,d

	inline bool inRect(int a, int b, int c, int d) { //判断该节点的矩形是否完全在矩形(abcd)里
		return this->x1 >= a && this->x2 <= b
			&& this->y1 >= c && this->y2 <= d;
	}
	inline bool havIntersect(int a, int b, int c, int d) { //判断两矩形(该节点的矩形和矩形abcd)是否有交集
		int maxw = max(x2, b);
		int maxh = max(y2, d);
		int minw = min(x1, a);
		int minh = min(y1, c);
		int w1 = x2 - x1, w2 = b - a;
		int h1 = y2 - y1, h2 = d - c;
		if(maxw-minw <= w1+w2 && maxh-minh <= h1+h2) return true;
		return false;
	}
#ifdef debug
	friend ostream& operator << (ostream& out, Node& node) {
		out << "[" << node.x1 << "," << node.x2 << "," << node.y1 << "," <<
			node.y2 << "]" << endl;
		return out;
	}
#endif
} root;

void insert(Node* now) { //插入一个值
//	now->sum += val;
	if(now->x1 == now->x2 && now->y1 == now->y2) {
		now->sum = !now->sum;
		return ;
	}
	now->sum = 0;

	int midx = (now->x1 + now->x2) >> 1, midy = (now->y1 + now->y2) >> 1;
	if(x>=now->x1 && x<=midx && y>=now->y1 && y<=midy) { //左上
		if(!now->chl[0])
			now->chl[0] = new Node(now->x1, midx, now->y1, midy);
		insert(now->chl[0]);
	}
	if(x>=midx+1 && x<=now->x2 && y>=now->y1 && y<=midy) { //右上
		if(!now->chl[1])
			now->chl[1] = new Node(midx+1, now->x2, now->y1, midy);
		insert(now->chl[1]);
	}
	if(x>=now->x1 && x<=midx && y>=midy+1 && y<=now->y2) { //左下
		if(!now->chl[2])
			now->chl[2] = new Node(now->x1, midx, midy+1, now->y2);
		insert(now->chl[2]);
	}
	if(x>=midx+1 && x<=now->x2 && y>=midy+1 && y<=now->y2) { //右下
		if(!now->chl[3])
			now->chl[3] = new Node(midx+1, now->x2, midy+1, now->y2);
		insert(now->chl[3]);
	}
	for(int i=0; i<4; i++)
		if(now->chl[i]) now->sum += now->chl[i]->sum;
}

int query(Node* now) { //查询矩形(x1,y1,x2,y2)里的和
	//先判空 两个矩形有交集才往下递归
	if(!now || !now->havIntersect(x1, x2, y1, y2)) return 0;

	//如果这个节点的矩形完全被包含在被查询的矩形里 就直接返回这个节点的和
	if(now->inRect(x1, x2, y1, y2)) return now->sum;
	int ret = 0;
	for(int i=0; i<4; i++) //如果不完全包含就递归4个子树
		if(now->chl[i] && now->chl[i]->havIntersect(x1, x2, y1, y2))
			ret += query(now->chl[i]);
	return ret;
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	int m;
	scanf("%d %d ", &n, &m);
	for(int i=1; i<=n; i++)
		for(int k=1; k<=n; k++) {
			scanf("%d ", &val);
			x = i, y = k;
			if(val)
				insert(&root);
		}
	while(m--) {
		int op;
		scanf("%d ", &op);
		if(op == 1) {
			scanf("%d %d ", &x, &y);
			insert(&root);
		} else {
			scanf("%d %d %d %d ", &x1, &y1, &x2, &y2);
//			printf("%d %d %d %d   ", x1, y1, x2, y2);
			int ans = query(&root);
			printf("%d\n", ans);
		}
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif
	return 0;
}




