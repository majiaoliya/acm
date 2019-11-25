////Serika 非常喜欢捏她的玩偶，她第一天会捏一下，第二天也会也会捏一下，而在第 i(i⩾3)​i(i \geqslant3)​i(i⩾3)​ 天，如果她在前 i−1​i -1​i−1​ 天一共捏了 k​k​k​ 下，那么她会在这一天捏 ⌊k2⌋​\lfloor \frac{k}{2} \rfloor​⌊2k​⌋​ 下。

//Senri 发现 Serika 的玩偶质量非常差，如果它从第一天算起被捏的次数总共 >x> x>x 次，那么它就会坏掉。

//现在 Senri 想知道 Serika 的玩偶会在第几天坏掉。

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAXN 32

using namespace std;
long long int n;
int main(void) {
	freopen("test", "r", stdin);
	for( ; cin>>n; ) {
		if(n<=0) { printf("0\n"); continue ; }
		int i=1, cnt=0;
		long long int sum = 0, t = 0;
		while(n>0) {
			cnt ++;
			if(i==1 || i==2) n--, sum++;
			else {
				t = sum >> 1;
				sum += t;
				n -= t;
			}
			i ++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
