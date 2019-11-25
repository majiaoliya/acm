#include <bits/stdc++.h>
using namespace std;
#define random(x) (rand()%x)

int a, n, t;

int main(void) {
    freopen("test", "w", stdout);
    int T = 1000000;
    printf("%d\n", T);
    while(T--) {
		int n = random(1000000000), a = random(40000-10) + 4;
		printf("%d %d\n", n, a);
    }
    return 0;
}
