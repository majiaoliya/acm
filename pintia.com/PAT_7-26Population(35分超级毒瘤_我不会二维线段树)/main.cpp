#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 100050
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>
#define ll long long int

using namespace std;

int n, m, Timer;
char str[512];
struct Rect { //查询的方块
	int id, xmin, xmax, ymin, ymax, timer, sum;
	inline bool in_rect(int x, int y) {
		return (xmin<=x && x<=xmax) && (ymin<=y && y<=ymax);
	}
#ifdef debug
	friend ostream& operator << (ostream& out, Rect& rect) {
		out << "[id:" << rect.id << " xmin:" << rect.xmin << " xmax:" << rect.xmax << " ymin:" << rect.ymin << " ymax:" << rect.ymax << "]";
		return out;
	}
#endif
} A[MAXN], B[MAXN], tmp[MAXN];

typedef pair<int,int> pii;
map<pair<pii,pii>, int> ans;
map<int, Rect*> mp2; //id映射A[]的rect*

struct Query {
	char ch;
	int arr[4];
} q[MAXN]; //每个操作离线下来

bool cmp1(Rect& a, Rect& b) { //先按xmin排, 再按xmax排
	if(a.xmin == b.xmin) return a.xmax < b.xmax;
	return a.xmin < b.xmin;
}

bool cmp2(Rect& a, Rect& b) { //先按ymin排, 再按ymax排
	if(a.ymin == b.ymin) return a.ymax < b.ymax;
	return a.ymin < b.ymin;
}


inline int query(int i) {
	return ans[{{q[i].arr[0],q[i].arr[1]}, {q[i].arr[2],q[i].arr[3]}}];
}

//重大失误 查询一些线段里所有包含点(x,y)的线段 好像做不到logn
inline void update(int i) { //找到所有包含(x,y)的区间并更新,不能二分,这里并没有单调性
	int x = q[i].arr[0], y = q[i].arr[1], w = q[i].arr[2], L, R;
//	printf("update:%d %d %d\n", x, y, w);
	Timer ++;
	for(int k=0; k<n; k++)
		if(A[k].in_rect(x,y)) A[k].timer = Timer;
	for(int k=0; k<n; k++)
		if(B[k].in_rect(x,y)) {
			B[k].sum += w;
			ans[{{B[k].xmin,B[k].xmax}, {B[k].ymin,B[k].ymax}}] = B[k].sum;
//			cout << "	" << B[k] << " sum=" << B[k].sum << endl;
		}
}

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	char now = 'I';
	while(cin) {
		cin.getline(str, sizeof(str));
		if(str[0] == 'I') { now='I'; continue ; }
		else if(str[0] == 'Q') { now='Q'; continue ;}
	   	else if(str[0] == 'E') break;
		if(now == 'I') {
			q[m].ch = 'I';
			sscanf(str, "%d %d %d ", 
					&(q[m].arr[0]), &(q[m].arr[1]), &(q[m].arr[2]));
		//	printf("query:%c %d %d %d\n", 
		//			q[m].ch, q[m].arr[0], q[m].arr[1], q[m].arr[2]);
			m ++;
		} else {
			q[m].ch = 'Q';
			sscanf(str, "%d %d %d %d ", 
					&(q[m].arr[0]), &(q[m].arr[1]), &(q[m].arr[2]), &(q[m].arr[3]));
		//	printf("query:%c %d %d %d %d\n", 
		//			q[m].ch, q[m].arr[0], q[m].arr[1], q[m].arr[2], q[m].arr[3]);
			A[n].id = B[n].id = n;
			A[n].xmin = B[n].xmin = q[m].arr[0];
			A[n].xmax = B[n].xmax = q[m].arr[1];
		   	A[n].ymin = B[n].ymin = q[m].arr[2];
			A[n].ymax = B[n].ymax = q[m].arr[3];
			mp2[n] = A;
			n++, m ++;
		}
   	}
	//sort(A, A+n, cmp1); //按横线排序 (错的,不能二分,因为没有单调性)
	//sort(B, B+n, cmp2); //按竖线排序
	
#ifdef debug
	//for(int i=0; i<n; i++) 	cout << A[i] << endl;
	//for(int i=0; i<n; i++) 	cout << B[i] << endl;
#endif
	for(int i=0; i<m; i++) {
		if(q[i].ch == 'Q') { printf("%d\n", query(i)); continue ; }
		update(i);
	}




	

#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

