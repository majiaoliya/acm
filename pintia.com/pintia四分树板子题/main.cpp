// #define debug
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
//测试Ofast能有多快  193ms
// #pragma GCC optimize(Ofast)
// O2 160ms
// #pragma GCC optimize(2)
// O3 102ms
#pragma GCC optimize(3)

using namespace std;

int n, sz;
int x, y, val;
int x1, x2, y1, y2;

struct Node { //四分树
	int x1, x2, y1, y2, sum;
	Node(int _x1=1, int _x2=20005, int _y1=1, int _y2=20005) : 
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
	now->sum += val;
	if(now->x1 == now->x2 && now->y1 == now->y2) return;

	int midx = (now->x1 + now->x2) >> 1, midy = (now->y1 + now->y2) >> 1;
	if(x>=now->x1 && x<=midx && y>=now->y1 && y<=midy) { //左上
		if(!now->chl[0]) 
			now->chl[0] = new Node(now->x1, midx, now->y1, midy);
		insert(now->chl[0]);
		return ;
	}
	if(x>=midx+1 && x<=now->x2 && y>=now->y1 && y<=midy) { //右上
		if(!now->chl[1])
			now->chl[1] = new Node(midx+1, now->x2, now->y1, midy);
		insert(now->chl[1]);
		return ;
	}
	if(x>=now->x1 && x<=midx && y>=midy+1 && y<=now->y2) { //左下
		if(!now->chl[2])
			now->chl[2] = new Node(now->x1, midx, midy+1, now->y2);
		insert(now->chl[2]);
		return ;
	}
	if(x>=midx+1 && x<=now->x2 && y>=midy+1 && y<=now->y2) { //右下
		if(!now->chl[3])
			now->chl[3] = new Node(midx+1, now->x2, midy+1, now->y2);
		insert(now->chl[3]);
		return ;
	}
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
	int flag = 1;
	while(flag) {
		char ch = getchar();
		if(ch == 'I') { flag = 1; getchar(); }
		else if(ch == 'Q') { flag = 2; getchar(); }
		else if(ch == 'E') break;
		else {
			ungetc(ch, stdin); //把getchar()得到的值吐回去
			if(flag == 1) { //insert
				scanf("%d %d %d ", &x, &y, &val);
				insert(&root);
			} else { //query
				scanf("%d %d %d %d ", &x1, &x2, &y1, &y2);
				printf("%d\n", query(&root));
			}
		}
	}







#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}



