#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 999999;
int n, m, k;
int x[MAXN], y[MAXN];

int main(void) {
	freopen("test", "r", stdin);
	for(n=0; ; ) {
		scanf("%d", x+n);
		char c = getchar();
		if(c == '\n') break;
		n ++;
	}
	for(m=0; ; ) {
		int tmp;
		if(EOF == scanf("%d", &tmp)) break;
		y[m++] = tmp;
	}
	sort(x, x+n);
	sort(y, y+m);
	int xi = n, yi = m, cnt = 0;
	for( ; yi>=0; yi--) 
		for(int k=xi; k>=0; k--) {
			if(x[k] <= y[yi]) {
				cnt ++;
				xi = k - 1;
				break;
			}
		}
	printf("%d\n", cnt);
	return 0;
}
