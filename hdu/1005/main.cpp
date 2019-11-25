
#include <iostream>
using namespace std;

//f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
//https://blog.csdn.net/qq_16542775/article/details/45481603
int main(void) {

	int a = 1, b = 1, n = 1;
	bool tag = true;
	for( ; cin >>a >> b >> n, a && b && n; ) {
		//因为f(n)需要mod7 所以f(n)只可能是{0, 1, 2, 3, 4, 5, 6}
		//f(n-1)和f(n-2)共7*7=49种可能
		int dp[50];
		for(int i=1; i<=50; i++) {
			if(i==1 || i==2) dp[i] = 1;
			else {
				dp[i] = (a*dp[i-1] + b*dp[i-2])%7;
			}
		}
		cout << dp[n%49] << endl;
	}

	return 0;
}




/**
 * 我的程序没有错 但是题目有坑,ｎ会非常大,直接超时
#include <iostream>
using namespace std;

//f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

int main(void) {

	int a = 1, b = 1, n = 1;
	bool tag = true;
	for( ; ; ) {
		cin >> a; cin >> b; cin >> n;
		//if(!n && !a && !b) return 0;
		if(n==0 && a==0 && b==0) {
			cout << endl;
			return 0;
		}

		int sum = 0;
		int left = 1;
		int right = 1;
		for(int k=3; k<=n; k++) {
			sum = (a*right + b*left)%7;
			left = right;
			right = sum;
		}
		//cout << dp[n] << endl;
		if(n == 1 || n == 2) sum = 1;
		cout << "a:" << a << " b:" << b << " n:" << n << " sum:" << sum << endl;
	}

	return 0;
}
*/


/** 动态规划解决
#include <iostream>
using namespace std;

//f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

int main(void) {

	for( ; ; ) {
		int a, b, n;
		cin >> a; cin >> b; cin >> n;
		if(!n && !a && !b) break;

		int rs = 0;
		int dp[n+1];
		dp[1] = dp[2] = 1;
		for(int k=3; k<=n; k++) {
			dp[k] = (a*dp[k-1] + b*dp[k-2])%7;
		}
		cout << dp[n] << endl;
	}

	return 0;
}
*/


/**
 * 应该是递归太多层 爆栈了
#include <iostream>
using namespace std;

//f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

int f(int x, int a, int b) {
	if(x == 1 || x == 2) return 1;
	int ret = 0;
	return (a*f(x-1, a, b) + b*f(x-2, a, b) ) % 7;
}

int main(void) {

	for( ; ; ) {
		int a, b, n;
		cin >> a; cin >> b; cin >> n;
		if(!n && !a && !b) break;

		cout << f(n, a, b) << endl;

	}

	return 0;
}
*/
