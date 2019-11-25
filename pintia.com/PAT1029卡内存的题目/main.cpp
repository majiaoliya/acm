//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <algorithm>
//#define MAXN 10086
//using namespace std;

//int main() {
//	freopen("test", "r", stdin);
//	
//	int n, x;
//	scanf("%d", &n);
//	vector<int> v;
//	for(int i=1; i<=n; i++) {
//		scanf("%d", &x);
//		vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
//		v.insert(it, x);
//	}
//	scanf("%d", &n);
//	for(int i=1; i<=n; i++) {
//		scanf("%d", &x);
//		vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
//		v.insert(it, x);
//	}
//	if(v.size())
//		printf("%d\n", v[v.size()/2]);
//	return 0;
//}







/**
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
//#define MAXN 100086
using namespace std;
const int MAXN = 2*1e5 + 5;
int x[MAXN], y[MAXN];

int main() {
	freopen("test", "r", stdin);
	
	int n, m;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", x+i);
	scanf("%d", &m);
	for(int i=0; i<n; i++)
		scanf("%d", y+i);
	
	int xi = 0, yi = 0, count = 0, nm = n+m, irs = 0;
	int * rs = x;
	if(nm != 0) {
		for(int i=0; i<nm; i++) {
			if(i == (nm+1)/2) {
				printf("%d\n", rs[irs]);
				break;
			} 
			if(xi<n && yi<m) {
				if(x[xi] < y[yi]) {
					rs = x;
					irs = xi;
					xi ++;
				} else {
					rs = y;
					irs = yi;
					yi ++;
				}
			} else if(xi<n && yi>=m) { //x[]还有
				rs = x;
				irs = xi;
				xi ++;
			} else if(xi>=n && yi<m) { //y[]还有
				rs = y;
				irs = yi;
				yi ++;
			}
		}
	}
	
	return 0;
}
*/

// https://blog.csdn.net/xmj15715216140/article/details/80925186
/**
	题解：
		 第一个队列存好后，把第二个队列边读，边和第一个队列比较，选择出队。这样可以不用一次存完第二个队列，解决超内存的问题。

	思路：
		第一、二个序列分别有n, m个元素，所以需要从队头剔除（n + m - 1） / 2个元素，
		最后答案就是两个队头的最小值。对于最终答案在第一第二个队列中的情况要分开处理。
		若答案在第二个队列中，在输入数据时就可以提前得出答案并退出，若答案在第一个队列中，要二次出队才能找到答案。

	注意：
		在所有元素入队列完毕后，把INT_MAX入队列，一是这样队列永不为空，方便处理。
	-----------------------------------------
	修改：
	1.题目说数据不超过long int, long int占4还是8个字节是要看具体情况的。
	2.根据测试代码1，测得所有数据不超过int
	3.根据测试代码2，测得PAT中 long int占8个字节
	4.如果全部用long int 存储，会爆内存。题目说数据不超过lont int ,但实际没超过int。
	  之前题解中是我对 long int 没考虑周全，谢谢评论区提醒

	说明与致歉：
	1.首先，这篇博客是原创，并且开源在柳婼github上的，有pull request记录 
	  https://github.com/liuchuo/PAT/commit/ad3de403d3d750aa98efd0ecb2c5234ca17b303e
	2.其次，我之前没说明，造成误解不好意思，表示歉意，现在柳婼的这题的题解已经更新其他解法了。
	3.最后，如果由其他有问题也欢迎和我交流。
	-----------------------------------------
*/


#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
#define ll int
//#define ll long int //一改long就爆内存....
using namespace std;
//柳神的解法
queue<ll> q1; //只存第一个序列 第二个序列边读边判断

int main() {
	freopen("test", "r", stdin);
	
	ll size1, size2, mid, midv, x, x1;
	scanf("%d", &size1);
	for(ll i=0; i<size1; i++) { //存第一个序列
		ll x;
		scanf("%d", &x);
		q1.push(x);
	}
	scanf("%d", &size2);
	mid = (size1+size2+1)>>1;
	ll i=1, tag = true;
	while(i<=mid) {
		if(size2) { //第二个序列可读
			if(tag) { //读
				scanf("%d", &x);
				tag = false;
				size2 --;
			}
			if(!q1.empty()) {
				x1 = q1.front();
				if(x1 < x) { //取x1 即第一个序列的front
					q1.pop();
					midv = x1;
				} else { //取x 即第二个序列的front
					midv = x;
					tag = true;
				}
			} else {
				midv = x;
				tag = true;
			}
		} else { //第二个序列不可读
			midv = q1.front();
			q1.pop();
		}
		i++;
	}
//	if(mid)
		printf("%lld\n", midv);
	
	return 0;
}








