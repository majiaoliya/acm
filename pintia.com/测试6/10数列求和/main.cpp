//#include <iostream>
//#include <vector>
//#include <string.h>
//#include <set>
//#define MAXN 100005
//using namespace std;

//int arr[MAXN], a, n;

//int main()
//{
//	freopen("test", "r", stdin);
//	scanf("%d %d", &a, &n);
//	long long int sum = 0, lst = 0, cheng = 1;
//	for(int i=1; i<=n; i++) {
//		long long int temp = a * cheng + lst;
//		sum += temp;
//		lst = temp;
//		cheng *= 10;
//	}
//	
//	printf("%d", sum);
//	return 0;
//}



#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#define MAXN 1000010
using namespace std;

int a, n;

int rs[MAXN];
int rs_len = 0;
vector<int> temp;

void big_add() {
	int rsi = MAXN-1, ti = temp.size()-1, rlen = MAXN-rs_len;
	int tag = false;
	for( ; rsi>=rlen && ti>=0; rsi--, ti--) {
		rs[rsi] += (tag + temp[ti]);
		tag = false;
		if(rs[rsi] > 9) {
			rs[rsi] -= 10;
			tag = true;
		}
	}
}

int main()
{
	freopen("test", "r", stdin);
	scanf("%d %d", &a, &n);
	int idx = MAXN - 1;
	rs_len = 5;
	for(int i=1; i<=n; i++) {
		temp.push_back(a);
		big_add();
		rs_len ++;
	}
	bool tag = false;
	for(int i=MAXN-rs_len; i<MAXN; i++) {
		if(rs[i]) tag = true;
		if(tag)
			printf("%d", rs[i]);
	}
	if(tag == false)
		printf("0");
	return 0;
}


