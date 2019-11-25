#include <iostream>
#define MAXN 16
using namespace std;

int n, t;

void dfs(int x, int state) {
	if(x == n) {
		for(int i=0, c=0; i<n; i++) 
			if(state>>i & 1) { //把一个数右移n位再&1就可以判断这个数的第n位是0还是1
				if(c++) printf(" ");
				printf("%d", i+1);
			}
		printf("\n");
		return ;
	}
	dfs(x+1, state);
	dfs(x+1, state|(1<<x)); //state|(1<<x)把state的第x位设为1(x从0开始)
}

int main(void) {
    freopen("test", "r", stdin);
    for( ; EOF != scanf("%d", &n); ) {
        dfs(0, 0);
    }
    /**
	char x = 9;
	for(int i=7; i>=0; i--) {
		printf("%d", x>>i&1);
	}
	x = x|1<<2;
	printf("\n");
	for(int i=7; i>=0; i--) {
		printf("%d", x>>i&1);
	}
	*/
    return 0;
}
