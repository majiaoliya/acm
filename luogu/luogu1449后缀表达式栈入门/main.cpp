#define debug
#ifdef debug
#include <time.h>
#include "/home/majiao/mb.h"
#endif


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAXN 10005
#include <map>
#include <stack>
#define ll long long int
#define QAQ (0)

using namespace std;

/**
 * 给定一个后缀表达式,求结果
 * 栈的入门题
 */

char ch;
ll x;
stack<ll> num;

int main() {
#ifdef debug
	freopen("test", "r", stdin);
	clock_t stime = clock();
#endif
	while((ch=getchar()) != '@') {
		if(ch == '.') {
			num.push(x);
			x = 0;
		} else if(ch>='0' && ch<='9') {
			x = x*10 + (ch-'0');
		} else {
			ll b = num.top(); num.pop();
			ll a = num.top(); num.pop();
//			printf("%lld %lld\n", a, b);
			if(ch == '-') num.push(a-b);
			else if(ch == '*') num.push(a*b);
			else if(ch == '+') num.push(a+b);
			else if(ch == '/') num.push(a/b);
		}
	}
	printf("%lld\n", num.top());








#ifdef debug
	clock_t etime = clock();
	printf("rum time: %lf 秒\n",(double) (etime-stime)/CLOCKS_PER_SEC);
#endif 
	return 0;
}

