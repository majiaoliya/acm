#include <bits/stdc++.h>
#include <stdlib.h>
#define random(x) ((rand()%x) + 1)
int main(void) {
	freopen("test", "w", stdout);
	int t = 2;
	srand(time(0));
	printf("%d\n", t);
	while(t--) {
		int n = random(20), q = random(30);
		printf("%d %d\n", n, q);
		for(int i=0; i<n; i++) {
			if(i) printf(" ");
			printf("%d", random(100));
		}
		printf("\n");
		char cmd[] = "AQR";
		while(q--) {
			char c = cmd[random(3)-1];
			printf("%c ", c);
			if(c == 'A') {
				int a = random(100), idx = random(n);
				printf("%d %d\n", a, idx);
			} else if(c == 'R') {
				int a=random(100), L=random(n), R=random(n);
				if(L > R) std::swap(L, R);
				printf("%d %d %d\n", a, L, R);
			} else {
				int L=random(n), R=random(n);
				if(L > R) std::swap(L, R);
				printf("%d %d\n", L, R);
			}
		}
	}
	return 0;
}


