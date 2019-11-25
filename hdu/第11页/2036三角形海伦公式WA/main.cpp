#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#define MAXN 105
using namespace std;

int n;
struct Node {
	double x, y;
} arr[MAXN];

double get_bian(double x1, double y1, double x2, double y2) { //两点间的距离
	double ret = 0, xx = abs(x1-x2)*abs(x1-x2),
					yy = abs(y1-y2)*abs(y1-y2);
	ret = sqrt(xx+yy);
	return ret;
}

double get_area(double a, double b, double c) { //通过边长求三角形面积
	//网上copy的海伦公式 
	//  p = (a+b+c) / 2;
	//	S = sqrt(p (p-a)(p-b)(p-c))
	double p = (a+b+c)/2;
	double s = sqrt(p * (p-a)*(p-b)*(p-c));
	return s;
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n), n; ) {
		for(int i=1; i<=n; i++) {
			scanf("%lf %lf", &arr[i].x, &arr[i].y);
		}
		if(n>=3) {
			double sum=0;
			int idx1=1, idx2=2, idx3=3;
			for(int idx3=3; idx3<=n; idx3++) {
				double a = get_bian(arr[idx1].x, arr[idx1].y, arr[idx2].x, arr[idx2].y);
				double b = get_bian(arr[idx1].x, arr[idx1].y, arr[idx3].x, arr[idx3].y);
				double c = get_bian(arr[idx2].x, arr[idx2].y, arr[idx3].x, arr[idx3].y);
				double area = get_area(a, b, c);
				sum += area;
				idx2 = idx3;
			}
			printf("%.1lf\n", sum);
		}
	}
	
	return 0;
}
