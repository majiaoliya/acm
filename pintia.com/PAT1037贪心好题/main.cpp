#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
#include <algorithm>
#define MAXN 100005
using namespace std;

vector<int> xfu, xzheng; //第一个序列的正负数
vector<int> yfu, yzheng; //第二个序列的正负数

int main() { //把两个序列分成正负两部分 
	freopen("test", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i=0, x; i<n; i++) {
		scanf("%d", &x);
		if(x > 0) xzheng.push_back(x);
		else xfu.push_back(x);
	}
	scanf("%d", &n);
	for(int i=0, x; i<n; i++) {
		scanf("%d", &x);
		if(x > 0) yzheng.push_back(x);
		else yfu.push_back(x);
	}
	
	sort(xfu.begin(), xfu.end()), sort(xzheng.begin(), xzheng.end());
	sort(yfu.begin(), yfu.end()), sort(yzheng.begin(), yzheng.end());
	int sum = 0;
	//负数和负数绝对值最大的求乘积 
	for(int ix=0, iy=0; ix<xfu.size()&&iy<yfu.size(); ix++, iy++) 
		sum += (xfu[ix] * yfu[iy]);
	//正数和正数绝对值最大的求乘积 
	for(int ix=xzheng.size()-1,iy=yzheng.size()-1; ix>=0&&iy>=0; ix--,iy--) 
		sum += (xzheng[ix] * yzheng[iy]);
	printf("%d\n", sum > 0 ? sum : 0);
	return 0;
}


