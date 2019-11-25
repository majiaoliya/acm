#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define ll long long int
#define MAXN 1000005
using namespace std;

ll arr[MAXN];

/** 第81项时 已经报long long int了 不要妄想存下来 应该找规律
int get_fibo() {
	arr[0] = 7, arr[1] = 11;
	for(int i=2; i<MAXN; i++) {
		arr[i] = arr[i-1] + arr[i-2];
		if(arr[i] < 0) { printf("%d", i); break; }
	}
}
*/
/**
 * 打表发现规律 答案8位后开始循环
1,2,0,2,2,1,0,1,
1,2,0,2,2,1,0,1,
1,2,0,2,2,1,0,1,
1,2,0,2,2,1,0,1,
1,2,0,2,2,1,0,1,
 */
void print_ans() { //打表找规律
	arr[1] = 7, arr[2] = 11;
	for(int i=3; i<=40; i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}
	for(int i=1; i<=40; i++) { //前40项的规律 
		printf("%lld,", arr[i]%3);
		if(i && i%8==0) printf("\n");
	}
	printf("\n");
}

int table[] = { 1,2,0,2,2,1,0,1 };
int main(void) {
	freopen("test", "r", stdin);
//	print_ans();
	for(int x; EOF != scanf("%d", &x); ) {
		printf("%s\n", (table[x%8]==0) ? "yes" : "no");
	}
	return 0;
}





