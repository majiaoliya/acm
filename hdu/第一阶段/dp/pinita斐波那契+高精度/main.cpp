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
#define MAXN ((int)1e5+7)
#define ll long long int
#define QAQ (0)

using namespace std;

//斐波那契数列 + 高精度

struct Int {
	vector<int> vec;
	Int(int val=0) {
		while(val) {
			vec.push_back(val%10);
			val /= 10;
		}
	}
	friend Int operator + (Int& a, Int& b) {
		Int ret;
		int i = 0, k = 0, an = a.vec.size(), bn = b.vec.size();
		bool flag = false;
		while(i<an && k<bn) {
			int tsum = a.vec[i] + b.vec[k] + flag;
			flag = false;
			if(tsum >= 10) tsum -= 10, flag = true;
			ret.vec.push_back(tsum);
			i ++, k ++;
		}
		while(i<an) {
			int tsum = a.vec[i] + flag;
			flag = false;
			if(tsum >= 10) tsum -= 10, flag = true;
			ret.vec.push_back(tsum);
			i++;
		}
		while(k<bn) {
			int tsum = b.vec[k] + flag;
			flag = false;
			if(tsum >= 10) tsum -= 10, flag = true;
			ret.vec.push_back(tsum);
			k++;
		}
		if(flag) ret.vec.push_back(flag);
		return ret;
	}
	void print() {
		for(int i=this->vec.size()-1; i>=0; i--)
			printf("%d", this->vec[i]);
	}
} ;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif

#ifdef debug2
	Int a(99999999), b(1);
	a.print(), b.print();
	(a+b).print();
#endif
	Int llst(1), lst(1), now(1);
	int n;
	scanf("%d ", &n);
	for(int i=2; i<=n; i++) {
		now = lst + llst;
		llst = lst;
		lst = now;
	}
	now.print();






#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}


