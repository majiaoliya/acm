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
#define MAXN (1024)
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 一张n*n的矩阵,q次操作
 * 		操作: 把子矩阵(x1,y1)(x2,y2)整块+1
 * 	最后打印这个矩阵
 * 	
 * 	差分性质 : 差分数组的前缀和就是原数组
 * 	
 * 	二维差分: 
 * 	0  0  0  0  0
 * 	0  1  0  0 -1
 * 	0  0  0  0  0
 * 	0  0  0  0  0
 * 	0 -1  0  0  1 
 * 	假设现在要操作子矩阵(2,2)(4,4)
 * 	那么操作后如下  4个角打上标记
 * 	0  0  0  0  0
 * 	0  1  0  0 -1
 * 	0  0  0  0  0
 * 	0  0  0  0  0
 * 	0 -1  0  0  1
 * 	
 * 	最后对每个位置求前缀和即可
 */
int n, m, mtx[MAXN][MAXN];

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	scanf("%d %d ", &n, &m);
	while(m--) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d ", &x1, &y1, &x2, &y2);
		//四个角都标上
		mtx[x1][y1] ++; //左上
		mtx[x1][y2+1] --; //右上
		mtx[x2+1][y1] --; //左下
		mtx[x2+1][y2+1] ++; //右下
	}
	for(int i=1; i<=n; i++) 
		for(int k=1; k<=n; k++) 
			mtx[i][k] += mtx[i-1][k]+mtx[i][k-1]-mtx[i-1][k-1],
			printf("%d%c", mtx[i][k], k==n ? '\n' : ' ');





#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


